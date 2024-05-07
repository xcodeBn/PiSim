//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "SummerEchoApp.h"
using namespace inet;
#include "inet/common/ModuleAccess.h"
#include "inet/common/Simsignals.h"
#include "inet/networklayer/common/L3AddressTag_m.h"
#include "inet/transportlayer/common/L4PortTag_m.h"
#include "inet/transportlayer/contract/udp/UdpControlInfo_m.h"
#include "inet/applications/base/ApplicationPacket_m.h"
#include "inet/common/ModuleAccess.h"
#include "inet/common/TagBase_m.h"
#include "inet/common/TimeTag_m.h"
#include "inet/common/lifecycle/ModuleOperations.h"
#include "inet/common/packet/Packet.h"
#include "inet/networklayer/common/FragmentationTag_m.h"
#include "inet/networklayer/common/L3AddressResolver.h"
#include "inet/transportlayer/contract/udp/UdpControlInfo_m.h"
#include "Network/Packet/HelloPacket_m.h"
Define_Module(SummerEchoApp);

void SummerEchoApp::initialize(int stage) {
    ApplicationBase::initialize(stage);

    if (stage == INITSTAGE_LOCAL) {
        // Initialize statistics
        numEchoed = 0;
        WATCH(numEchoed);
    }
}

void SummerEchoApp::handleMessageWhenUp(cMessage *msg) {
    socket.processMessage(msg);
}

void SummerEchoApp::socketDataArrived(UdpSocket *socket, Packet *pk) {
    EV << "Received packet: " << pk->str() << endl;

    // Simply forward the packet for further processing
    processPacket(socket, pk);
}

void SummerEchoApp::processPacket(UdpSocket *socket, Packet *pk) {
    // Determine its source address/port
    const auto &l3AddressInd = pk->getTag<L3AddressInd>();
    const auto &l4PortInd = pk->getTag<L4PortInd>();
    L3Address remoteAddress = l3AddressInd->getSrcAddress();
    int srcPort = l4PortInd->getSrcPort();

    EV << "Testttt" << pk->str() << endl;

    // Peek at the HelloPacket chunk to modify
    const auto& helloChunk = pk->peekAtFront<HelloPacket>(B(-1), Chunk::PF_ALLOW_REINTERPRETATION);
    if (!helloChunk) {
        EV_WARN << "Received packet does not contain a HelloPacket chunk." << endl;
        delete pk;
        return;
    }
    EV << "Testt2" << pk->str() << endl;

    // Deserialize the data and calculate the response
    Summer sum;
    sum.deserialize(helloChunk->getData());
    std::string answer = std::to_string(sum.a + sum.b);
    auto newPayload = makeShared<HelloPacket>();
    newPayload->setData(answer.c_str());
    newPayload->setChunkLength(B(answer.length()));

    // Create a new packet with the new payload
    Packet *responsePacket = new Packet("ResponsePacket");
    responsePacket->insertAtBack(newPayload);

    // Clear the original packet's tags and prepare for sending
    pk->clearTags();
    pk->trim();

    // Sending the response packet
    emit(packetSentSignal, responsePacket);
    EV << "Sending response packet: " << responsePacket->str() << endl;
    socket->sendTo(responsePacket, remoteAddress, srcPort);

    delete pk;  // Clean up the original packet
}






void SummerEchoApp::socketErrorArrived(UdpSocket *socket,
        Indication *indication) {
    EV_WARN << "Ignoring UDP error report " << indication->getName() << endl;
    delete indication;
}

void SummerEchoApp::socketClosed(UdpSocket *socket) {
    if (operationalState == State::STOPPING_OPERATION)
        startActiveOperationExtraTimeOrFinish(par("stopOperationExtraTime"));
}

void SummerEchoApp::refreshDisplay() const {
    ApplicationBase::refreshDisplay();

    char buf[40];
    sprintf(buf, "echoed: %d pks", numEchoed);
    getDisplayString().setTagArg("t", 0, buf);
}

void SummerEchoApp::finish() {
    ApplicationBase::finish();
}

void SummerEchoApp::processPacket(Packet *pk) {

}
void SummerEchoApp::sendPacket(Packet *pckt, std::string data) {

    HelloPacket *helloPacket = new HelloPacket();
    helloPacket->setData(data.c_str());
    Packet *packet = new Packet("SummerPacket");

    const auto &payload = makeShared<HelloPacket>();
    payload->setChunkLength(B(par("messageLength")));

    payload->setData(data.c_str());
    payload->addTag<CreationTimeTag>()->setCreationTime(simTime());


    packet->insertAtBack(payload);
    L3Address destAddr = chooseDestAddr();
    emit(packetSentSignal, packet);
    EV << packet->str();
    socket.sendTo(packet, destAddr, destPort);




}

L3Address SummerEchoApp::chooseDestAddr() {

    int k = intrand(destAddresses.size());
    if (destAddresses[k].isUnspecified() || destAddresses[k].isLinkLocal()) {
        L3AddressResolver().tryResolve(destAddressStr[k].c_str(),
                destAddresses[k]);
    }
    return destAddresses[k];
}

int SummerEchoApp::echoSum() {

    return 0;
}

void SummerEchoApp::handleStartOperation(LifecycleOperation *operation) {
    socket.setOutputGate(gate("socketOut"));
    int localPort = par("localPort").intValue();
    socket.bind(localPort);
    const MulticastGroupList &mgl = getModuleFromPar<IInterfaceTable>(
            par("interfaceTableModule"), this)->collectMulticastGroups();
    socket.joinLocalMulticastGroups(mgl);
    socket.setCallback(this);
}

void SummerEchoApp::handleStopOperation(LifecycleOperation *operation) {
    socket.close();
    delayActiveOperationFinish(par("stopOperationTimeout"));
}

void SummerEchoApp::handleCrashOperation(LifecycleOperation *operation) {
    if (operation->getRootModule() != getContainingNode(this))
        socket.destroy(); // In real OS, program crash would be detected by the OS and it would close the sockets of crashed programs
    socket.setCallback(nullptr);
}

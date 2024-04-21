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

#include "SummerUdpApp.h"

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
#include "Util/DashSummer/Summer.h"
Define_Module(SummerUdpApp);

void SummerUdpApp::initialize(int stage) {
    ApplicationBase::initialize(stage);

    if (stage == INITSTAGE_LOCAL) {
        numSent = 0;
        numReceived = 0;
        WATCH(numSent);
        WATCH(numReceived);

        localPort = par("localPort");
        destPort = par("destPort");

        packetName = par("packetName").str();

    }
}

void SummerUdpApp::handleMessageWhenUp(cMessage *msg) {
    if (msg->isSelfMessage()) {
        // Handle timers here
    } else {
        // Handle incoming packet
    }
}

void SummerUdpApp::finish() {
    // Cleanup code here
}

void SummerUdpApp::refreshDisplay() const {
    char buf[40];
    sprintf(buf, "Packets sent: %d | Received: %d", numSent, numReceived);
    getDisplayString().setTagArg("t", 0, buf);
}

L3Address SummerUdpApp::chooseDestAddr() {
    // Logic to choose a destination address
    return L3Address();
}

void SummerUdpApp::sendPacket(const std::string &data) {
    // Packet sending logic
    std::ostringstream str;
    str << packetName << "-" << numSent; // Constructs the packet name with an incrementing suffix
    std::string message = data;  // Use the data string as the packet's message

    // Create a HelloPacket and set its data
    auto helloPacket = makeShared<HelloPacket>();
    helloPacket->setData(message.c_str());
    helloPacket->setChunkLength(B(message.size())); // Set the chunk's byte length to match the message size

    // Create a Packet object to encapsulate the HelloPacket
    Packet *packet = new Packet(str.str().c_str());
    if (dontFragment) {
        packet->addTag<FragmentationReq>()->setDontFragment(true); // Set the 'do not fragment' flag if specified
    }
    packet->insertAtBack(helloPacket); // Insert the HelloPacket into the Packet

    // Choose the destination address and send the packet
    L3Address destAddr = chooseDestAddr();
    socket.sendTo(packet, destAddr, destPort);
    emit(packetSentSignal, packet); // Emit signal indicating a packet has been sent
    EV << "Sending packet: " << packet->str() << endl;

    numSent++;  // Increment the sent packet count
}

void SummerUdpApp::processPacket(Packet *packet) {
    // Packet processing logic
}

void SummerUdpApp::processPacket(UdpSocket *socket, Packet *pk) {
    // Determine its source address/port
    const auto &l3AddressInd = pk->getTag<L3AddressInd>();
    const auto &l4PortInd = pk->getTag<L4PortInd>();
    L3Address remoteAddress = l3AddressInd->getSrcAddress();
    int srcPort = l4PortInd->getSrcPort();

    EV << "Testttt" << pk->str() << endl;

    // Peek at the HelloPacket chunk to modify
    const auto &helloChunk = pk->peekAtFront<HelloPacket>(B(-1),
            Chunk::PF_ALLOW_REINTERPRETATION);
    if (!helloChunk) {
        EV_WARN << "Received packet does not contain a HelloPacket chunk."
                       << endl;
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
void SummerUdpApp::handleStartOperation(LifecycleOperation *operation) {
    socket.setOutputGate(gate("socketOut"));
    int localPort = par("localPort").intValue();
    socket.bind(localPort);
    const MulticastGroupList &mgl = getModuleFromPar<IInterfaceTable>(
            par("interfaceTableModule"), this)->collectMulticastGroups();
    socket.joinLocalMulticastGroups(mgl);
    socket.setCallback(this);
}

void SummerUdpApp::socketDataArrived(UdpSocket *sock, Packet *packet) {
    EV << "Received packet: " << packet->str() << endl;

    processPacket(sock, packet);
}

void SummerUdpApp::socketErrorArrived(UdpSocket *sock, Indication *indication) {
    EV_WARN << "Ignoring UDP error report " << indication->getName() << endl;
    delete indication;
}

void SummerUdpApp::socketClosed(UdpSocket *sock) {
    // Socket closure handling code
    if (operationalState == State::STOPPING_OPERATION)
        startActiveOperationExtraTimeOrFinish(par("stopOperationExtraTime"));
}

void SummerUdpApp::handleStopOperation(LifecycleOperation *operation) {
    socket.close();
    delayActiveOperationFinish(par("stopOperationTimeout"));
}

void SummerUdpApp::handleCrashOperation(LifecycleOperation *operation) {
    // Crash operation logic
    if (operation->getRootModule() != getContainingNode(this))
        socket.destroy(); // In real OS, program crash would be detected by the OS and it would close the sockets of crashed programs
    socket.setCallback(nullptr);
}



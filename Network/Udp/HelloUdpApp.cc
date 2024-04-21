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

#include "HelloUdpApp.h"
#include "inet/applications/udpapp/UdpBasicApp.h"
#include "inet/applications/base/ApplicationPacket_m.h"
#include "inet/common/ModuleAccess.h"
#include "inet/common/TagBase_m.h"
#include "inet/common/TimeTag_m.h"
#include "inet/common/lifecycle/ModuleOperations.h"
#include "inet/common/packet/Packet.h"
#include "inet/networklayer/common/FragmentationTag_m.h"
#include "inet/networklayer/common/L3AddressResolver.h"
#include "inet/transportlayer/contract/udp/UdpControlInfo_m.h"
#include "Util/DashSummer/Summer.h"
#include "Network/Packet/HelloPacket_m.h"
Define_Module(HelloUdpApp);
using namespace inet;

void HelloUdpApp::initialize(int stage) {

    bool isSummer = par("isSummer");
    if (isSummer) {

    } else {
        UdpBasicApp::initialize(stage);
    }
}

void HelloUdpApp::handleMessageWhenUp(cMessage *msg) {

    UdpBasicApp::handleMessageWhenUp(msg);
}

void HelloUdpApp::finish() {

    UdpBasicApp::finish();
}

void HelloUdpApp::refreshDisplay() const {

    UdpBasicApp::refreshDisplay();
}

L3Address HelloUdpApp::chooseDestAddr() {
    return UdpBasicApp::chooseDestAddr();
}

void HelloUdpApp::sendPacket() {

    int numToSend = par("numToSend");
    if (numSent >= numToSend) {
        return;
    }
    std::ostringstream str;
    str << packetName << "-" << numSent;
    std::string message = generateMessage();
    HelloPacket *helloPacket = new HelloPacket();
    helloPacket->setData(message.c_str());
    Packet *packet = new Packet(str.str().c_str());
    if (dontFragment)
        packet->addTag<FragmentationReq>()->setDontFragment(true);
    const auto &payload = makeShared<HelloPacket>();
    payload->setChunkLength(B(par("messageLength")));

    payload->setData(message.c_str());
    payload->addTag<CreationTimeTag>()->setCreationTime(simTime());

    packet->insertAtBack(payload);
    L3Address destAddr = chooseDestAddr();
    emit(packetSentSignal, packet);
    EV << packet->str();
    socket.sendTo(packet, destAddr, destPort);
    numSent++;

}

void HelloUdpApp::processPacket(Packet *msg) {
    EV_INFO << "Received packettt: " << msg->str() << endl;
    numReceived++;
    UdpBasicApp::processPacket(msg);

}

void HelloUdpApp::setSocketOptions() {
    UdpBasicApp::setSocketOptions();
}

void HelloUdpApp::processStart() {
    UdpBasicApp::processStart();
}

void HelloUdpApp::processSend() {

    sendPacket();

    selfMsg->setKind(STOP);
}

void HelloUdpApp::processStop() {
    UdpBasicApp::processStop();
}

std::string HelloUdpApp::generateMessage() {

    int a = randomGenerator.generateRandomInt();
    int b = randomGenerator.generateRandomInt();
    sum = new Summer(a, b);
    std::string stuff = sum->serialize();
    return stuff;
}

HelloUdpApp::~HelloUdpApp() {
    // cleanup if necessary
}


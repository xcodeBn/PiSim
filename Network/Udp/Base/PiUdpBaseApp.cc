#include <string.h>
#include "PiUdpBaseApp.h"
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
#include "Network/Packet/XY_Packet_m.h"

Define_Module(PiUdpBaseApp);

void PiUdpBaseApp::initialize(int stage) {
    ClockUserModuleMixin::initialize(stage);

    if (stage == INITSTAGE_LOCAL) {
        numSent = 0;
        numReceived = 0;
        WATCH(numSent);
        WATCH(numReceived);

        localPort = par("localPort");
        destPort = par("destPort");
        startTime = par("startTime");
        stopTime = par("stopTime");
        packetName = par("packetName");
        dontFragment = par("dontFragment");
        if (stopTime >= CLOCKTIME_ZERO && stopTime < startTime)
            throw cRuntimeError("Invalid startTime/stopTime parameters");
        selfMsg = new ClockEvent("sendTimer");
    }
}

void PiUdpBaseApp::handleMessageWhenUp(cMessage *msg) {
    UdpBasicApp::handleMessageWhenUp(msg);
}

void PiUdpBaseApp::finish() {
    UdpBasicApp::finish();
}

void PiUdpBaseApp::refreshDisplay() const {
    UdpBasicApp::refreshDisplay();
}

L3Address PiUdpBaseApp::chooseDestAddr() {
    return UdpBasicApp::chooseDestAddr();
}

void PiUdpBaseApp::sendPacket() {
    int numToSend = par("numToSend");
    if (numSent >= numToSend) {
        return;
    }
    std::ostringstream str;
    str << packetName << "-" << numSent;
    std::string message = generateMessage();
    auto helloPacket = makeShared<XY_Packet>();
    helloPacket->setData(message.c_str());
    helloPacket->setChunkLength(B(message.size()));

    auto packet = new Packet(str.str().c_str());
    if (dontFragment)
        packet->addTag<FragmentationReq>()->setDontFragment(true);
    packet->insertAtBack(helloPacket);

    L3Address destAddr = chooseDestAddr();
    emit(packetSentSignal, packet);
    EV << "Sending packet: " << packet->str() << endl;
    socket.sendTo(packet, destAddr, destPort);
    numSent++;
}

void PiUdpBaseApp::processPacket(Packet *msg) {
    EV_INFO << "Received packet: " << msg->str() << endl;
    numReceived++;
    const auto &helloChunk = msg->peekAtFront<XY_Packet>(B(-1), Chunk::PF_ALLOW_ALL);
    if (!helloChunk) {
        EV_WARN << "Received packet does not contain a HelloPacket chunk." << endl;
        delete msg;
        return;
    }

    std::string answer = helloChunk->getData();
    EV << "Results arrived: " << answer << endl;
}

void PiUdpBaseApp::setSocketOptions() {
    UdpBasicApp::setSocketOptions();
}

void PiUdpBaseApp::processStart() {
    UdpBasicApp::processStart();

}
void PiUdpBaseApp::processSend() {

    sendPacket();

    selfMsg->setKind(STOP);
}

void PiUdpBaseApp::processStop() {
    UdpBasicApp::processStop();
}

std::string PiUdpBaseApp::generateMessage() {
    int a = intrand(100);  // Random integers between 0 and 99
    int b = intrand(100);
    Summer sum(a, b);
    return sum.serialize();
}

PiUdpBaseApp::~PiUdpBaseApp() {
    // cleanup if necessary
}

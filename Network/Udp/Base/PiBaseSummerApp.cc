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

#include "PiBaseSummerApp.h"

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

#include "Util/DashSummer/Summer.h"
#include "Network/Packet/DataChunk_m.h"
#include "Network/Packet/XY_Packet_m.h"
#include "Network/Udp/Util/PacketHelper.h"
#include  "Util/json/json.h"
Define_Module(PiBaseSummerApp);

void PiBaseSummerApp::initialize(int stage) {
    ApplicationBase::initialize(stage);

    if (stage == INITSTAGE_LOCAL) {
        numSent = 0;
        numReceived = 0;
        WATCH(numSent);
        WATCH(numReceived);
        localPort = par("localPort");
        destPort = par("destPort");
        packetName = par("packetName").str();
        checkEvenOdd = par("checkEvenOdd");

    }
}

void PiBaseSummerApp::handleMessageWhenUp(cMessage *msg) {
    if (msg->isSelfMessage()) {
        // Handle timers here
        EV << "Self message:" << msg->str() << endl;
    } else {
        // Handle incoming packet
        EV << "Incoming packet:" << msg->str() << endl;
        socket.processMessage(msg);
    }
}

void PiBaseSummerApp::finish() {
    // Cleanup code here
}

void PiBaseSummerApp::refreshDisplay() const {
    char buf[40];
    sprintf(buf, "Packets sent: %d | Received: %d", numSent, numReceived);
    getDisplayString().setTagArg("t", 0, buf);
}

L3Address PiBaseSummerApp::chooseDestAddr() {
    // Logic to choose a destination address
    return L3Address();
}

ChunkType PiBaseSummerApp::getChunkType(Packet *pk) {
    return PacketHelper::checkPacketChunk(pk);
}
void PiBaseSummerApp::sendPacket(const std::string &data) {
    // Packet sending logic
    std::ostringstream str;
    str << packetName << "-" << numSent; // Constructs the packet name with an incrementing suffix
    std::string message = data;  // Use the data string as the packet's message

    // Create a HelloPacket and set its data
    auto dataChunk = makeShared<DataChunk>();
    dataChunk->setData(message.c_str());
    dataChunk->setChunkLength(B(message.size())); // Set the chunk's byte length to match the message size

    // Create a Packet object to encapsulate the HelloPacket
    Packet *packet = new Packet(str.str().c_str());
    if (dontFragment) {
        packet->addTag<FragmentationReq>()->setDontFragment(true); // Set the 'do not fragment' flag if specified
    }
    packet->insertAtBack(dataChunk); // Insert the HelloPacket into the Packet

    // Choose the destination address and send the packet
    L3Address destAddr = chooseDestAddr();
    socket.sendTo(packet, destAddr, destPort);
    emit(packetSentSignal, packet); // Emit signal indicating a packet has been sent
    EV << "Sending packet: " << packet->str() << endl;

    numSent++;  // Increment the sent packet count
}

void PiBaseSummerApp::processPacket(Packet *packet) {
    // Packet processing logic
}

void PiBaseSummerApp::echoSendPacket(const L3Address &remoteAddress, int srcPort,
        UdpSocket *socket, const std::string &data) {
    std::string packetName = "SumResponsePacket:" + std::to_string(sentPackets);
    // Create a new Packet instance for each send operation
    Packet *newPacket = new Packet(packetName.c_str()); // Consider using a more descriptive name or a variable name

    // Assuming the payload is being set up here; ensure `data` contains your desired payload
    auto payload = makeShared<DataChunk>();
    payload->setChunkLength(B(data.length() * 8)); // Assuming each character is one byte, adjust accordingly
    payload->setData(data.c_str());
    newPacket->insertAtBack(payload);

    // Send the newly created packet
    socket->sendTo(newPacket, remoteAddress, srcPort);
    sentPackets++;

}

void PiBaseSummerApp::processDataChunk(UdpSocket *socket, Packet *pk) {
    // Determine its source address/port
    const auto &l3AddressInd = pk->getTag<L3AddressInd>();
    const auto &l4PortInd = pk->getTag<L4PortInd>();
    L3Address remoteAddress = l3AddressInd->getSrcAddress();
    int srcPort = l4PortInd->getSrcPort();
    EV_INFO << "Packet recieved:" << pk->str() << endl;
    // Peek at the HelloPacket chunk to modify
    const auto &dataChunk = pk->peekAtFront<DataChunk>(B(-1),
            Chunk::PF_ALLOW_ALL);
    if (!dataChunk) {
        EV_WARN << "Received packet does not contain a DataChunk chunk."
                       << endl;
        delete pk;
        return;
    }
    nlohmann::json jsonData = deserializeJson(dataChunk->getData());
    try {
        x = jsonData.at("x");
        EV_INFO << "Value of x: " << x << endl;
        hostAAddress = remoteAddress;
        hostAPort = srcPort;

    } catch (nlohmann::json::out_of_range &e) {
        if(x<=-1){
            EV_ERROR << "Error: x does not exist in the JSON data." << endl;
        }
    } catch (nlohmann::json::type_error &e) {
        EV_ERROR
                        << "Type Error: Expected an integer for x, but found different type."
                        << endl;
    }

    try {
        y = jsonData.at("y");
        EV_INFO << "Value of y: " << y << endl;
        hostBAddress = remoteAddress;
        hostBPort = srcPort;
    } catch (nlohmann::json::out_of_range &e) {
        if(y<=-1)
        EV_ERROR << "Error: y does not exist in the JSON data." << endl;
    } catch (nlohmann::json::type_error &e) {
        EV_ERROR
                        << "Type Error: Expected an integer for y, but found different type."
                        << endl;
    }
    EV_INFO << "Data Recieved:" << dataChunk->getData() << endl;

    bool isReady = isReadyToSum();
    if (!isReady) {
        EV_WARN << "NOT READY YET" << endl;
        delete pk;
        return;
    }

    int result = x + y;
    nlohmann::json resultJson;
    resultJson["SumResults"] = result;

    if (checkEvenOdd) {
        resultJson["SumResults"] = {{"Value" , result}, {"Even/Odd" , evenOrOdd(result)}};
        resultJson["x"] = { { "Value", x }, { "Even/Odd", evenOrOdd(x) } };
        resultJson["y"] = { { "Value", y }, { "Even/Odd", evenOrOdd(y) } };
    }

    std::string resultStr = resultJson.dump();

    auto newPayload = makeShared<DataChunk>();
    newPayload->setChunkLength(B(resultStr.length() * 8)); // Assuming 8 bits per character
    newPayload->setData(resultStr.c_str());

    // Create a new packet with the new payload
    Packet *responsePacket = new Packet("ResponsePacket");
    responsePacket->insertAtBack(newPayload);
    // Clear the original packet's tags and prepare for sending
    pk->clearTags();
    pk->trim();
    // Sending the response packet
    emit(packetSentSignal, responsePacket);
    // Log the sending action
    EV_INFO << "Sending response packet to HostA" << endl;
    echoSendPacket(hostAAddress, hostAPort, socket, resultStr);

    // Log the sending action
    EV_INFO << "Sending response packet to HostB" << endl;
    echoSendPacket(hostBAddress, hostBPort, socket, resultStr);
    delete pk; // Clean up the original packet
}

void PiBaseSummerApp::processHelloChunk(UdpSocket *socket, Packet *pk) {
    EV << "Testttt" << pk->str() << endl;
    // Peek at the HelloPacket chunk to modify
    const auto &helloChunk = pk->peekAtFront<XY_Packet>(B(-1),
            Chunk::PF_ALLOW_ALL);
    // Determine its source address/port
    const auto &l3AddressInd = pk->getTag<L3AddressInd>();
    const auto &l4PortInd = pk->getTag<L4PortInd>();
    L3Address remoteAddress = l3AddressInd->getSrcAddress();
    int srcPort = l4PortInd->getSrcPort();

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
    auto newPayload = makeShared<XY_Packet>();
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
    delete pk; // Clean up the original packet
}

void PiBaseSummerApp::processXYChunk(UdpSocket *socket, Packet *pk) {
    processHelloChunk(socket, pk);
}

void PiBaseSummerApp::processPacket(UdpSocket *socket, Packet *pk) {

    EV_INFO << "Processing received packet...:" << endl;
    ChunkType chunkType = PacketHelper::checkPacketChunk(pk); // Ensure this method is defined to return the correct chunk type

    switch (chunkType) {
    case ChunkType::HELLO_CHUNK:
        EV << " HELLO CHUNK RECIEVED" << endl;
        processHelloChunk(socket, pk);
        break;  // Prevents fall-through

    case ChunkType::DATA_CHUNK:
        processDataChunk(socket, pk);
        break;  // Prevents fall-through

    case ChunkType::XY_CHUNK:
        processXYChunk(socket, pk);
        break;

    default:
        return;
        break;  // Handles cases where no known chunk type is found
    }
}

void PiBaseSummerApp::handleStartOperation(LifecycleOperation *operation) {
    socket.setOutputGate(gate("socketOut"));
    int localPort = par("localPort").intValue();
    socket.bind(localPort);
    const MulticastGroupList &mgl = getModuleFromPar<IInterfaceTable>(
            par("interfaceTableModule"), this)->collectMulticastGroups();
    socket.joinLocalMulticastGroups(mgl);
    socket.setCallback(this);
}

void PiBaseSummerApp::socketDataArrived(UdpSocket *sock, Packet *packet) {
    EV << "Received packet: " << packet->str() << endl;

    processPacket(sock, packet);
}

void PiBaseSummerApp::socketErrorArrived(UdpSocket *sock, Indication *indication) {
    EV_WARN << "Ignoring UDP error report " << indication->getName() << endl;
    delete indication;
}

void PiBaseSummerApp::socketClosed(UdpSocket *sock) {
    // Socket closure handling code
    if (operationalState == State::STOPPING_OPERATION)
        startActiveOperationExtraTimeOrFinish(par("stopOperationExtraTime"));
}

void PiBaseSummerApp::handleStopOperation(LifecycleOperation *operation) {
    socket.close();
    delayActiveOperationFinish(par("stopOperationTimeout"));
}

void PiBaseSummerApp::handleCrashOperation(LifecycleOperation *operation) {
    // Crash operation logic
    if (operation->getRootModule() != getContainingNode(this))
        socket.destroy(); // In real OS, program crash would be detected by the OS and it would close the sockets of crashed programs
    socket.setCallback(nullptr);
}

bool PiBaseSummerApp::isReadyToSum() {
    if (x < 0) {
        EV_INFO << "x not recieved..." << endl;
    }
    if (y < 0) {
        EV_INFO << "y not recieved..." << endl;
    }
    if (x < 0 || y < 0) {
        return false;
    }
    EV_INFO << "READY TO SUM" << endl;
    return true;
}

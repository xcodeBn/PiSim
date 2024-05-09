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

#include "SenderUdpApp.h"
#include "Util/json/json.h"
#include "Util/Generators/RandomGenerator.h"
#include "Network/Packet/DataChunk_m.h"
#include "inet/applications/base/ApplicationPacket_m.h"
#include "inet/common/ModuleAccess.h"
#include "inet/common/TagBase_m.h"
#include "inet/common/TimeTag_m.h"
#include "inet/common/lifecycle/ModuleOperations.h"
#include "inet/common/packet/Packet.h"
#include "inet/networklayer/common/FragmentationTag_m.h"
#include "inet/networklayer/common/L3AddressResolver.h"
#include "inet/transportlayer/contract/udp/UdpControlInfo_m.h"
#include "Network/Udp/Util/PacketHelper.h"
Define_Module(SenderUdpApp);

std::string SenderUdpApp::generateMessage() {
    // Use the JsonHelperRepository to create a JSON object and serialize it
    bool shouldGenerateRandomVar = par("shouldGenerateRandomVar");
    varName = par("varName").stdstringValue();
    if (shouldGenerateRandomVar) {
        varValue = randomGenerator.generateRandomInt(1, 999);
    } else {
        varValue = par("appVar");
    }
    nlohmann::json jsonMsg = createJson(varName, varValue);
    return serializeJson(jsonMsg);
}

void SenderUdpApp::initialize(int stage) {
    if (stage == INITSTAGE_LOCAL) {
        message = generateMessage();
    }

    PiUdpBaseApp::initialize(stage);
}

void SenderUdpApp::sendPacket() {
    int numToSend = par("numToSend");
    if (numSent >= numToSend) {
        return;
    }
    std::ostringstream str;
    str << packetName << "-" << numSent;
    auto dataChunk = makeShared<DataChunk>();
    dataChunk->setData(message.c_str());
    dataChunk->setChunkLength(B(message.size()));

    auto packet = new Packet(str.str().c_str());
    if (dontFragment)
        packet->addTag<FragmentationReq>()->setDontFragment(true);
    packet->insertAtBack(dataChunk);

    L3Address destAddr = chooseDestAddr();
    emit(packetSentSignal, packet);
    EV_INFO << "Sending packet: " << packet->str() << "  from host" <<endl;
    socket.sendTo(packet, destAddr, destPort);
    numSent++;
}

void SenderUdpApp::processPacket(Packet *msg) {
    EV_INFO << "Received packet: " << msg->str() << endl;
    numReceived++;


    const auto &dataChunk = msg->peekAtFront<DataChunk>(B(-1),
            Chunk::PF_ALLOW_ALL);
    if (!dataChunk) {
        EV_WARN << "Received packet does not contain a HelloPacket chunk."
                       << endl;
        delete msg;
        return;
    }

    std::string answer = dataChunk->getData();
    EV << "Summation results arrived: " << answer << endl;
}

void SenderUdpApp::processJsonData(const nlohmann::json &jsonData) {
    // Even if you don't need to process JSON data, you need to implement this method
    EV << "Processing JSON Data: " << jsonData.dump() << std::endl;
}

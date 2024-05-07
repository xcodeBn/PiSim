/*
 * PacketHelper.h
 *
 *  Created on: Apr 29, 2024
 *      Author: lenovo
 */

#ifndef NETWORK_UDP_UTIL_PACKETHELPER_H_
#define NETWORK_UDP_UTIL_PACKETHELPER_H_

#include "inet/common/packet/Packet.h"
#include "Network/Udp/Util/ChunkType.h"
#include "Network/Packet/DataChunk_m.h"  // Include your specific DataChunk header
#include "Network/Packet/HelloPacket_m.h"  // Include your specific HelloPacket header
#include "Network/Packet/XY_Packet_m.h"
#include "Network/Packet/DetailedResultChunk_m.h"
using namespace inet;
class PacketHelper {
public:
    // Static method to determine the chunk type contained in a packet
    static ChunkType checkPacketChunk(inet::Packet *packet) {
        const auto &chunk = packet->peekData(); // Peek without specifying type

        // Use dynamic_cast to check for each specific chunk type
        if (dynamic_cast<const DataChunk*>(chunk.get()) != nullptr) {
            return ChunkType::DATA_CHUNK;
        }
        if (dynamic_cast<const HelloPacket*>(chunk.get()) != nullptr) {
            return ChunkType::HELLO_CHUNK;
        }
        if (dynamic_cast<const XY_Packet*>(chunk.get()) != nullptr) {
            return ChunkType::XY_CHUNK;
        }

        if(dynamic_cast<const DetailedResultChunk*>(chunk.get()) != nullptr){
            return ChunkType::DETAILED_RESULT;
        }

        // If no types matched, return NOCHUNK
        return ChunkType::NOCHUNK;
    }
};

#endif /* NETWORK_UDP_UTIL_PACKETHELPER_H_ */

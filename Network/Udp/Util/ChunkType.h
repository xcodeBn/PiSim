/*
 * ?hunkType.h
 *
 *  Created on: Apr 28, 2024
 *      Author: lenovo
 */

#ifndef NETWORK_UDP_UTIL_CHUNKTYPE_H_
#define NETWORK_UDP_UTIL_CHUNKTYPE_H_



// Enum class for different types of chunks a packet might contain
enum class ChunkType {
    DATA_CHUNK,
    HELLO_CHUNK,
    XY_CHUNK,
    DETAILED_RESULT,
    NOCHUNK // Special value to indicate no specific chunk is present
};

#endif /* NETWORK_UDP_UTIL_?HUNKTYPE_H_ */

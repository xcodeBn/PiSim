
import inet.common.packet.chunk.Chunk;

cplusplus {{

#include "inet/common/packet/chunk/FieldsChunk.h"

}}
class EvenOddChunk extends inet::FieldsChunk{

string data = "";
bool isEven = false;
bool useJson = false;
bool finalOdd = false;
string extraData = "";
string details = "";
 
}
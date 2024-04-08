/*
 * HelloUdpSink.h
 *
 *  Created on: Apr 7, 2024
 *      Author: lenovo
 */

#ifndef NETWORK_UDP_HELLOUDPSINK_H_
#define NETWORK_UDP_HELLOUDPSINK_H_
#include "inet/applications/udpapp/UdpSink.h"

using namespace inet;
class HelloUdpSink: public inet::UdpSink {

protected:
    void processPacket(Packet *pk) override;

};

#endif /* NETWORK_UDP_HELLOUDPSINK_H_ */

/*
 * UdpSummerSink.h
 *
 *  Created on: Apr 14, 2024
 *      Author: lenovo
 */

#include "inet/applications/udpapp/UdpSink.h"
#ifndef NETWORK_RECIEVER_UDPSUMMERSINK_H_
#define NETWORK_RECIEVER_UDPSUMMERSINK_H_

using namespace inet;

class UdpSummerSink : public inet::UdpSink {
public:

protected:
    virtual void processPacket(Packet *msg) override;
    virtual void setSocketOptions() override;
};

#endif /* NETWORK_RECIEVER_UDPSUMMERSINK_H_ */

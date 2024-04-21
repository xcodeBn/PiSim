/*
 * UdpSummerSink.cc
 *
 *  Created on: Apr 14, 2024
 *      Author: lenovo
 */

#include "UdpSummerSink.h"
#include "Network/Packet/HelloPacket_m.h"


Define_Module(UdpSummerSink);
void UdpSummerSink::processPacket(Packet *msg){



        // Process only copies of packets, original should be deleted by base class
        auto packetCopy = msg->dup();

        // Extract the payload as HelloPacket (Ensure that this cast is valid!)
        auto helloPayload = packetCopy->peekData<HelloPacket>();

        if (helloPayload) {
            // Retrieve the message content
            const auto &content = helloPayload->getData();
            EV << "Received Message: " << content << endl;

            // Further processing here
        }
        UdpSink::processPacket(msg);

        delete packetCopy; // Clean up the duplicated packet

}
void UdpSummerSink::setSocketOptions(){
    UdpSink::setSocketOptions();
}

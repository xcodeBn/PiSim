#ifndef __PISIM_SUMMERUDPAPP_H_
#define __PISIM_SUMMERUDPAPP_H_

#include <string>
#include "inet/common/packet/Packet.h"
#include "inet/applications/base/ApplicationBase.h"
#include "inet/transportlayer/contract/udp/UdpSocket.h"

using namespace inet;

/**
 * SummerUdpApp forwards received UDP packets to a specified destination.
 *
 * It can be configured to send packets to multiple destinations and supports
 * various network features such as multicast, DSCP settings, and more.
 */
class SummerUdpApp: public ApplicationBase, public UdpSocket::ICallback {
protected:
    UdpSocket socket;
    std::vector<L3Address> destAddresses;
    int localPort = 0;
    int destPort = 0;
    L3Address localAddress;       // Local IP address to bind the socket
    std::string packetName;       // Name for created packets
    bool dontFragment = false;    // Flag to prevent IP fragmentation
    int numSent = 0;
    int numReceived = 0;

public:
    /** Lifecycle stages */
    virtual int numInitStages() const override {
        return inet::NUM_INIT_STAGES;
    }

protected:
    /** Initialize the application */
    virtual void initialize(int stage) override;

    /** Handle incoming messages */
    virtual void handleMessageWhenUp(cMessage *msg) override;

    /** Cleanup the application */
    virtual void finish() override;

    /** Update the display string */
    virtual void refreshDisplay() const override;

    /** Choose a random destination address */
    virtual L3Address chooseDestAddr();

    /** Send a packet to the chosen destination */
    virtual void sendPacket(const std::string &data);

    /** Process the received packet */
    virtual void processPacket(Packet *packet);

    /** Process the received packet */
    virtual void processPacket(UdpSocket *socket,Packet *packet);

    /** Handle start lifecycle operation */
    virtual void handleStartOperation(LifecycleOperation *operation) override;

    /** Handle stop lifecycle operation */
    virtual void handleStopOperation(LifecycleOperation *operation) override;

    /** Handle crash lifecycle operation */
    virtual void handleCrashOperation(LifecycleOperation *operation) override;

    /** Callback when data arrives at the socket */
    virtual void socketDataArrived(UdpSocket *sock, Packet *packet) override;

    /** Callback when a socket error occurs */
    virtual void socketErrorArrived(UdpSocket *sock, Indication *indication)
            override;

    /** Callback when the socket is closed */
    virtual void socketClosed(UdpSocket *sock) override;
};

#endif // __PISIM_SUMMERUDPAPP_H_

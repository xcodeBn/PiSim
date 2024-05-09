#ifndef __PISIM_SUMMERUDPAPP_H_
#define __PISIM_SUMMERUDPAPP_H_

#include <string>
#include "inet/common/packet/Packet.h"
#include "inet/applications/base/ApplicationBase.h"
#include "inet/transportlayer/contract/udp/UdpSocket.h"
#include "Network/Udp/Util/ChunkType.h"
#include "Core/repository/JsonHelperRepository.h"
using namespace inet;

/**
 * SummerUdpApp forwards received UDP packets to a specified destination.
 *
 * It can be configured to send packets to multiple destinations and supports
 * various network features such as multicast, DSCP settings, and more.
 */
class SummerUdpApp: public ApplicationBase,
        public UdpSocket::ICallback,
        private JsonHelperRepository {
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
    ChunkType chunkType;
    bool checkEvenOdd = false;

public:
    /** Lifecycle stages */
    virtual int numInitStages() const override {
        return inet::NUM_INIT_STAGES;
    }

    // Utility function to check if a number is even or odd
    virtual std::string evenOrOdd(int number) {
        return (number % 2 == 0) ? "even" : "odd";
    }

protected:
    virtual ChunkType getChunkType(Packet *pk);

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
    virtual void processPacket(UdpSocket *socket, Packet *packet);

    /** Process the received data chunk */
    virtual void processDataChunk(UdpSocket *socket, Packet *pk);

    /** Process the received hello chunk */
    void processHelloChunk(UdpSocket *socket, inet::Packet *pk);

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

private:
    bool isReadyToSum();
    void echoSendPacket(const L3Address &remoteAddress, int srcPort,
            UdpSocket *socket, const std::string &data);

    void processXYChunk(inet::UdpSocket *socket, inet::Packet *pk);

    int x = -1;
    int y = -1;
    L3Address hostAAddress;
    int hostAPort;
    L3Address hostBAddress;
    int hostBPort;

    int sentPackets = 0;

};

#endif // __PISIM_SUMMERUDPAPP_H_

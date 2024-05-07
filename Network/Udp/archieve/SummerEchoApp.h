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

#ifndef __PISIM_SUMMERECHOAPP_H_
#define __PISIM_SUMMERECHOAPP_H_

#include <omnetpp.h>
#include "inet/applications/udpapp/UdpEchoApp.h"
#include "inet/applications/base/ApplicationBase.h"
#include "inet/transportlayer/contract/udp/UdpSocket.h"
using namespace omnetpp;
using namespace inet;
#include "Util/DashSummer/Summer.h"
/**
 * TODO - Generated class
 */
class SummerEchoApp: public ApplicationBase, public UdpSocket::ICallback {
protected:
    UdpSocket socket;
    int numEchoed; // just for WATCH
    // parameters
    std::vector<L3Address> destAddresses;
    std::vector<std::string> destAddressStr;
    int localPort = -1, destPort = -1;
    Summer *sum ;

protected:
    virtual int numInitStages() const override {
        return NUM_INIT_STAGES;
    }
    virtual void initialize(int stage) override;
    virtual void handleMessageWhenUp(cMessage *msg) override;
    virtual void finish() override;
    virtual void refreshDisplay() const override;
    virtual L3Address chooseDestAddr();
    virtual void sendPacket(Packet *pckt,std::string data="");
    virtual void processPacket(UdpSocket *socket, Packet *pk);
    virtual void processPacket( Packet *pk);

    virtual int echoSum();
    virtual void handleStartOperation(LifecycleOperation *operation) override;
    virtual void handleStopOperation(LifecycleOperation *operation) override;
    virtual void handleCrashOperation(LifecycleOperation *operation) override;

    virtual void socketDataArrived(UdpSocket *socket, Packet *packet) override;
    virtual void socketErrorArrived(UdpSocket *socket, Indication *indication)
            override;
    virtual void socketClosed(UdpSocket *socket) override;
};

#endif

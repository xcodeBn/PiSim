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

#ifndef __PISIM_PIUDPBASEAPP_H_
#define __PISIM_PIUDPBASEAPP_H_

#include "inet/applications/udpapp/UdpBasicApp.h"
#include <omnetpp.h>

#include "Util/Generators/RandomGenerator.h"
#include "Util/DashSummer/Summer.h"
#include "Network/Udp/Util/ChunkType.h"
using namespace omnetpp;
using namespace inet;

using namespace omnetpp;

/**
 * TODO - Generated class
 */
class PiUdpBaseApp: public UdpBasicApp {
protected:

    virtual ChunkType getChunkType(Packet pk*);

    virtual void initialize(int stage) override;
    virtual void handleMessageWhenUp(cMessage *msg) override;
    virtual void finish() override;
    virtual void refreshDisplay() const override;

    // chooses random destination address
    virtual L3Address chooseDestAddr() override;
    virtual void sendPacket() override;
    virtual void processPacket(Packet *msg) override;
    virtual void setSocketOptions() override;

    virtual void processStart() override;
    virtual void processSend() override;
    virtual void processStop() override;

    virtual std::string generateMessage();

    piutil::RandomGenerator randomGenerator;
private:

    Summer *sum;

public:
    PiUdpBaseApp() {
    }
    virtual ~PiUdpBaseApp();
};

#endif

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

#ifndef __PISIM_EVENODDAPP_H_
#define __PISIM_EVENODDAPP_H_

#include <omnetpp.h>
#include "Network/Udp/Custom/SenderUdpApp.h"
using namespace omnetpp;

/**
 * TODO - Generated class
 */
class EvenOddApp : public SenderUdpApp
{
protected:
    virtual void processPacket(Packet* msg) override;

};

#endif

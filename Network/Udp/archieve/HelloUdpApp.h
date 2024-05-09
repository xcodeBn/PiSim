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

#ifndef __PISIM_HELLOUDPAPP_H_
#define __PISIM_HELLOUDPAPP_H_

#include <omnetpp.h>
#include "Network/Udp/Base/PiUdpBaseApp.h"

using namespace omnetpp;
using namespace inet;
/**
 * this model generates two ints packets
 */
class HelloUdpApp: public PiUdpBaseApp {
protected:






public:
    HelloUdpApp() {
    }
    virtual ~HelloUdpApp();
};

#endif

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

#ifndef __PISIM_XUDPAPP_H_
#define __PISIM_XUDPAPP_H_

#include <omnetpp.h>
#include "Network/Udp/Base/PiUdpBaseApp.h"
#include "Core/repository/JsonHelperRepository.h"
#include "Util/Generators/RandomGenerator.h"
using namespace omnetpp;

/**
 * TODO - Generated class
 */
class SenderUdpApp: public PiUdpBaseApp, private JsonHelperRepository {
protected:
    virtual void initialize(int stage) override;
    virtual std::string generateMessage() override;

    virtual void sendPacket() override;
    virtual void processPacket(Packet *msg) override ;

    virtual void processJsonData(const nlohmann::json& jsonData) override; // Implement this method
    piutil::RandomGenerator randomGenerator;

private:
    std::string varName;
    int varValue;
    std::string message;
public:
    SenderUdpApp() {
    }
    virtual ~SenderUdpApp() {

    };
};

#endif

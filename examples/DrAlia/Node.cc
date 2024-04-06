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

#include "Node.h"
#include <iostream>
#include <string>
Define_Module(Node);
#include "Util/DashSummer/DashSummer.h"
#include "Util/StringUtil/StringUtil.h"
using namespace omnetpp;
void Node::initialize() {
    // TODO - Generated method body

    EV << getName() << " Initialised \n";

    if (strcmp(getName(), "NodeA") == 0) {

        std::string messageText = piutil::StringUtil::generateRandomIntsString();
        // Using cMessage constructor that accepts a const char*
        cMessage *msg = new cMessage(messageText.c_str()); // using c_str() to convert std::string to const char*
        int a = piutil::DashSummer::calculate(messageText);
        send(msg, gate("out"));
    }
}

void Node::handleMessage(cMessage *msg) {
    // TODO - Generated method body
    if (strcmp(getName(), "NodeA") == 0) {
        EV << getName() << " recieved a message" << "\n";
    }
    if (strcmp(getName(), "NodeB") == 0) {
        EV << getName() << " recieved a message" << "\n";
    }

}

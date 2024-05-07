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

#include "EvenOddApp.h"
#include "Network/Packet/EvenOddChunk_m.h"
Define_Module(EvenOddApp);

void EvenOddApp::processPacket(Packet *msg) {

    EV_INFO << "Received packet: " << msg->str() << endl;
    numReceived++;

    const auto &dataChunk = msg->peekAtFront<EvenOddChunk>(B(-1),
            Chunk::PF_ALLOW_ALL);
    if (!dataChunk) {
        EV_WARN << "Received packet does not contain a HelloPacket chunk."
                       << endl;
        delete msg;
        return;
    }

    std::string answer = dataChunk->getData();
    EV << "Summation results arrived: " << answer << endl;

}

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

package Network.Udp.Custom;

import Network.Udp.Base.PiUdpBaseApp;

simple SenderUdpApp extends PiUdpBaseApp
{
    parameters:
        bool shouldGenerateRandomVar = default(true);
        bool evenOddCheck = default(false);
        bool isMainSenderApp = default(false);
        string testName = default("TestingSend");
        string varName = default("x");
        int appVar = default(-1);
        
        @class(SenderUdpApp);
        

}

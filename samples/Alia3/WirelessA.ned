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

package samples.Alia3;



//
// SPDX-License-Identifier: LGPL-3.0-or-later
//


package inet.tutorials.wireless;

import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.node.contract.INetworkNode;
import inet.physicallayer.wireless.common.contract.packetlevel.IRadioMedium;
import inet.visualizer.contract.IIntegratedVisualizer;

network WirelessA
{
    parameters:
        @display("bgb=795.312,504;bgg=100,1,grey95");
        @figure[title](type=label; pos=0,-1; anchor=sw; color=darkblue);

        @figure[rcvdPkText](type=indicatorText; pos=380,20; anchor=w; font=,18; textFormat="packets received: %g"; initialValue=0);
//        @statistic[packetReceived](source=hostB.app[0].packetReceived; record=figure(count); targetFigure=rcvdPkText);

    submodules:
        visualizer: <default(firstAvailableOrEmpty("IntegratedCanvasVisualizer"))> like IIntegratedVisualizer if typename != "" {
            @display("p=688.46405,135.072");
        }
        configurator: Ipv4NetworkConfigurator {
            @display("p=688.46405,213.696");
        }
        radioMedium: <default("UnitDiskRadioMedium")> like IRadioMedium {
            @display("p=688.46405,280.224");
        }
        hostA: <default("WirelessHost")> like INetworkNode {
            @display("p=52.416,174.384");
        }
        hostB: <default("WirelessHost")> like INetworkNode {
            @display("p=52.416,400.17603");
        }
        hostC: <default("WirelessHost")> like INetworkNode {
            @display("p=181.44,296.35202");
        }
        hostD: <default("WirelessHost")> like INetworkNode {
            @display("p=327.6,296.35202");
        }
        hostE: <default("WirelessHost")> like INetworkNode {
            @display("p=473.76,296.35202");
        }
}



//
// SPDX-License-Identifier: LGPL-3.0-or-later
//


package samples.sim3;

import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.node.contract.INetworkNode;
import inet.physicallayer.wireless.common.contract.packetlevel.IRadioMedium;
import inet.visualizer.contract.IIntegratedVisualizer;

network WirelessA
{
    parameters:
        @display("bgb=850.0,675.0;bgg=100,1,grey95");
        @figure[title](type=label; pos=0,-1; anchor=sw; color=darkblue);

        @figure[rcvdPkText](type=indicatorText; pos=380,20; anchor=w; font=,18; textFormat="packets received: %g"; initialValue=0);
       // @statistic[packetReceived](source=hostB.app[0].packetReceived; record=figure(count); targetFigure=rcvdPkText);

    submodules:
        visualizer: <default(firstAvailableOrEmpty("IntegratedCanvasVisualizer"))> like IIntegratedVisualizer if typename != "" {
            @display("p=580,125");
        }
        configurator: Ipv4NetworkConfigurator {
            @display("p=580,200");
        }
        radioMedium: <default("UnitDiskRadioMedium")> like IRadioMedium {
            @display("p=580,275");
        }
        hostA: <default("WirelessHost")> like INetworkNode {
            @display("p=50,325");
        }
        hostB: <default("WirelessHost")> like INetworkNode {
            @display("p=658.224,432.432");
        }

        hostR1: <default("WirelessHost")> like INetworkNode {
            @display("p=177.408,461.664");
        }
        hostR2: <default("WirelessHost")> like INetworkNode {
            @display("p=68.544,500.976");
        }
        hostR3: <default("WirelessHost")> like INetworkNode {
            @display("p=316.51202,528.192");
        }
        hostR4: <default("WirelessHost")> like INetworkNode {
            @display("p=272.16,369.936");
        }
        hostR5: <default("WirelessHost")> like INetworkNode {
            @display("p=177.408,618.91205");
        }
        hostR6: <default("WirelessHost")> like INetworkNode {
            @display("p=624.96,579.60004");
        }
        hostR7: <default("WirelessHost")> like INetworkNode {
            @display("p=442.51202,570.528");
        }
}

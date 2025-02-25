

package samples.sim5;

import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.node.ethernet.Eth100M;
import inet.node.inet.SensorNode;
import inet.node.inet.StandardHost;
import inet.node.inet.WirelessHost;
import inet.physicallayer.wireless.apsk.packetlevel.ApskScalarRadioMedium;
import inet.visualizer.common.IntegratedVisualizer;

import inet.node.inet.StandardHost;
import inet.node.inet.WirelessHost;

network LEACHNetwork {
    @display("bgb=500,400");
    submodules:
        configurator: Ipv4NetworkConfigurator;
        visualizer: IntegratedVisualizer;
        radioMedium: ApskScalarRadioMedium;

        baseStation: StandardHost {
            @display("p=225,86");
        }

        sensor1: WirelessHost {
            @display("p=65,111");
        }

        sensor2: WirelessHost {
            @display("p=104,245");
        }

        sensor3: WirelessHost {
            @display("p=282,309");
        }

        sensor4: WirelessHost {
            @display("p=225,202");
        }

        sensor5: WirelessHost {
            @display("p=420,224");
        }

   
}

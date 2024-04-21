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

package Network.Udp;

import inet.applications.contract.IApp;

//
// The SummerUdpApp listens on a specified UDP port and sends received packets to predefined destination addresses.
// It is designed to test various network behaviors including multicast functionalities and QoS features.
//
simple SummerUdpApp like IApp
{
    parameters:
        @display("i=block/app");
        @lifecycleSupport;

        // General parameters
        string destAddresses = default(""); // List of destination IP addresses, separated by spaces ("": don't send)
        int destPort = default(-1);  // Destination port for outgoing packets
        string localAddress = default("");  // Local IP address to bind to (empty string binds to all available interfaces)
        int localPort = default(-1);  // Local port to listen on for incoming packets
        string packetName = default("UdpBasicAppData");  // Default name for created packets

        // Timing parameters
        volatile double sendInterval @unit(s) = default(1s); // Time interval between sends, usually a random value (e.g., exponential(1))

        // QoS and Network settings
        int timeToLive = default(-1); // TTL for IPv4 or Hop Limit for IPv6, -1 uses system default
        bool dontFragment = default(false); // Set to true to prevent IP fragmentation
        int dscp = default(-1); // DSCP field for IPv4/IPv6 packets, -1 uses default
        int tos = default(-1); // Type Of Service for IPv4, Traffic Class for IPv6, -1 uses default

        // Multicast and Broadcast settings
        string multicastInterface = default("");  // Interface name for multicast packets, empty uses default interface
        bool receiveBroadcast = default(false); // If true, configures the socket to receive broadcast packets
        bool joinLocalMulticastGroups = default(false); // If true, joins all multicast groups on local interfaces

        // Message settings
        volatile int messageLength @unit(B) = default(100B); // Length of messages to generate, in bytes

        // Module references
        string interfaceTableModule;  // Path to the InterfaceTable module

        // Lifecycle extras
        double stopOperationExtraTime @unit(s) = default(-1s); // Additional time after lifecycle stop operation finished
        double stopOperationTimeout @unit(s) = default(2s); // Timeout for lifecycle stop operation

        // Signals and Statistics
        @signal[packetSent](type="inet::Packet");
        @signal[packetReceived](type="inet::Packet");
        @statistic[packetSent](title="Packets Sent"; source=packetSent; record=count,"sum(packetBytes)","vector(packetBytes)"; interpolationmode=none);
        @statistic[receivedPk](title="Packets Received"; source=packetReceived; record=count,"sum(packetBytes)","vector(packetBytes)"; interpolationmode=none);
        @class(SummerUdpApp);
    gates:
        input socketIn @labels(UdpControlInfo/up);
        output socketOut @labels(UdpControlInfo/down);


}

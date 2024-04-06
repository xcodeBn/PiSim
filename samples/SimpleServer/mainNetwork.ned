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
package samples.SimpleServer;
import Modules.Simple.Computer.Computer;
import Modules.Simple.Server.Server;
network MainNetwork
{
    @display("bgb=854,443");
    submodules:
        pc1: Computer {
            @display("p=135,267;is=l");
        }
        pc2: Computer {
            @display("p=646,247;is=l");
        }
        server: Server {
            @display("p=350,88;is=vl");
        }
    connections:
        pc1.out --> server.in1;
        server.out1 --> pc1.in;
        server.out2 --> pc2.in;
        pc2.out --> server.in2;
}

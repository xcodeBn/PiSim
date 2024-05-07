

package Network.Udp.Base;



import inet.applications.udpapp.UdpBasicApp;

simple PiUdpBaseApp extends UdpBasicApp
{
    parameters:
        int numToSend = default(1);
        bool isSummer = default(false);
        bool isForwarder = default(false);
    @class(PiUdpBaseApp);
   
}

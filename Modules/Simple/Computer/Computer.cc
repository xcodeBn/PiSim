#include "../../../Modules/Simple/Computer/Computer.h"

Define_Module(Computer);

void Computer::initialize() {
    // TODO - Generated method body

    if (strcmp(getName(), "pc1") == 0) {

        cMessage *msg = new cMessage("HelloIAmPc1");
        send(msg, "out");



    }

    if (strcmp(getName(), "pc2") == 0) {

        cMessage *msg = new cMessage("HelloIAmPc2");
        send(msg, "out");



    }

}

void Computer::handleMessage(cMessage *msg) {
    // TODO - Generated method body


}

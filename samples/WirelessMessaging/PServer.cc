/*
 * PServer.cc
 *
 *  Created on: Apr 5, 2024
 *      Author: lenovo
 */

#include <omnetpp.h>

using namespace omnetpp;

class PServer: public cSimpleModule {
protected:
    cMessage *msg;
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);

};

Define_Module(PServer);

void PServer::initialize(){};

void PServer::handleMessage(cMessage *msg){
    msg = new cMessage("Hello");
    cModule *target = getParentModule()->getSubmodule("client");
    sendDirect(msg,target,"radioIn");
};

/*
 * PClient.cc
 *
 *  Created on: Apr 5, 2024
 *      Author: lenovo
 */



#include <omnetpp.h>

using namespace omnetpp;

class PClient: public cSimpleModule {
protected:
    cMessage *msg;
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);

};

Define_Module(PClient);

void PClient::initialize(){

    EV<< getName() << " Initialized" ;
    msg = new cMessage("RTS");
    scheduleAt(simTime()+dblrand(), msg->dup());
    EV<< getName() << " Initialization complete \n" ;
};

void PClient::handleMessage(cMessage *msg){

    EV<<"HandleMessagePClient called \n";

    cModule *target;
    msg = new cMessage("RTS");
    target = getParentModule()->getSubmodule("server");

    sendDirect(msg, target,"radioIn");
    scheduleAt(simTime()+dblrand(), msg->dup());


};


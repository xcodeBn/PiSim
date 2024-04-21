#include "Server.h"
#include <cctype>
#include <iostream>
#include <algorithm>
#include <string>
Define_Module(Server);

bool Server::isNumerical(char c) {

    return std::isalnum(c);
// this method checks if a char is a string or num

}
void Server::initialize() {
    // TODO - Generated method body
    // do nothing
}



void Server::handleMessage(cMessage *msg) {
    // TODO - Generated method body
    std::string str = msg->getName();

    bool isvalid = std::all_of(str.cbegin(), str.cend(), isNumerical);

    if (!isvalid) {
        return;
    } // if the message is not valid the server drops its and do nothing

    std::transform(str.begin(), str.end(), str.begin(), ::toupper);

    int n = str.length();
    char char_array[n + 1];
    strcpy(char_array, str.c_str());

    cMessage *msg1 = new cMessage(char_array);

    cGate *arrivalGate = msg->getArrivalGate(); // using arrival gate to check whos sending the message pc1 or pc2

    if (arrivalGate == gate("in1")) {
        // send to pc2

        send(msg1, "out2");

    }

    if (arrivalGate == gate("in2")) {
        // send to pc1


        send(msg1, "out1");
    }

}

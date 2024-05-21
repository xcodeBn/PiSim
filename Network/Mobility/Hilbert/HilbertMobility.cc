#include "HilbertMobility.h"

using namespace inet;
Define_Module(HilbertMobility);
void HilbertMobility::initialize(int stage) {
    LineSegmentsMobilityBase::initialize(stage);
    if (stage == inet::INITSTAGE_LOCAL) {
        // Initialize Hilbert curve parameters from NED file
        int order = par("order");
        int padding = par("padding");
        speed = par("speed");

        // Generate the Hilbert curve path
        double width =par("networkWidth");
        double height = par("networkHeight");

        HilbertCurve hilbertCurve(order, width, height, padding);
        auto curvePoints = hilbertCurve.getCurve();
        for (const auto& point : curvePoints) {
            hilbertPath.emplace_back(point.first, point.second, 0);
        }
    }
}

void HilbertMobility::setInitialPosition() {
    currentIndex = 0;
    if (!hilbertPath.empty()) {
        lastPosition = hilbertPath[currentIndex];
        nextChange = simTime() + updateInterval;
    }
}

void HilbertMobility::move() {
    LineSegmentsMobilityBase::move();
    if (simTime() >= nextChange) {
        setTargetPosition();
    }
}

void HilbertMobility::setTargetPosition() {
    currentIndex++;
    if (currentIndex >= hilbertPath.size()) {
        currentIndex = 0; // Restart the path
    }
    targetPosition = hilbertPath[currentIndex];
    double distance = lastPosition.distance(targetPosition);
    double travelTime = distance / speed;
    nextChange = simTime() + travelTime;
    lastPosition = targetPosition;

    EV << "INFO: new target position = " << targetPosition << ", next change = " << nextChange << endl;
}

#include "HilbertMobility.h"

using namespace inet;

Define_Module(HilbertMobility);

void HilbertMobility::initialize(int stage) {
    LineSegmentsMobilityBase::initialize(stage);
    if (stage == INITSTAGE_LOCAL) {
        int order = par("order");
        int padding = par("padding");
        speed = par("speed");
        moveInterval = par("moveInterval").doubleValue() > 0 ? par("moveInterval") : -1; // Optional override
        double width = par("networkWidth");
        double height = par("networkHeight");

        // Generate Hilbert path
        HilbertCurve hilbertCurve(order, width, height, padding);
        auto curvePoints = hilbertCurve.getCurve();
        hilbertPath.clear();
        hilbertPath.reserve(curvePoints.size());
        for (const auto& point : curvePoints) {
            hilbertPath.emplace_back(point.first, point.second, 0); // 2D with z=0
        }

        WATCH(currentIndex);
        WATCH(speed);
        setInitialPosition();
        scheduleAt(simTime(), new cMessage("startMove")); // Start immediately
    }
}

void HilbertMobility::setInitialPosition() {
    if (hilbertPath.empty()) {
        throw cRuntimeError("Hilbert path not initialized");
    }
    currentIndex = 0;
    lastPosition = hilbertPath[currentIndex];
    targetPosition = lastPosition;
}

void HilbertMobility::move() {
    LineSegmentsMobilityBase::move(); // Updates position based on velocity
    if (simTime() >= nextChange) {
        setTargetPosition();
    }
}

void HilbertMobility::setTargetPosition() {
    currentIndex = (currentIndex + 1) % hilbertPath.size();
    targetPosition = hilbertPath[currentIndex];

    double distance = lastPosition.distance(targetPosition);
    simtime_t travelTime = moveInterval > 0 ? moveInterval : (distance / speed);
    if (travelTime <= 0) travelTime = 0.1; // Avoid zero division or infinite speed

    lastVelocity = (targetPosition - lastPosition) / travelTime.dbl();
    nextChange = simTime() + travelTime;
    lastUpdate = simTime();

    EV << "Moving to " << targetPosition << ", next change at " << nextChange << endl;
    emitMobilityStateChangedSignal();
}

void HilbertMobility::generateHilbertPath() {
    // Already handled in initialize; kept for potential future use
}



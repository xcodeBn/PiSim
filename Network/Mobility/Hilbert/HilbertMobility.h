#ifndef __PISIM_HILBERTMOBILITY_H_
#define __PISIM_HILBERTMOBILITY_H_

#include "inet/mobility/base/LineSegmentsMobilityBase.h"
#include "inet/common/INETMath.h"
#include "../../../Util/Hilbert/HilbertCurve.h" // Adjust path as needed

using namespace inet;

class HilbertMobility : public LineSegmentsMobilityBase {
protected:
    std::vector<Coord> hilbertPath; // Path points in 3D (z=0 for 2D)
    int currentIndex = 0;           // Current position index
    double speed;                   // Speed in m/s
    simtime_t moveInterval;         // Optional: time between moves (if not using speed)

protected:
    virtual void initialize(int stage) override;
    virtual void setInitialPosition() override;
    virtual void move() override;
    virtual void setTargetPosition() override;
    void generateHilbertPath();

public:
    virtual ~HilbertMobility() {}
};



#endif // __PISIM_HILBERTMOBILITY_H_

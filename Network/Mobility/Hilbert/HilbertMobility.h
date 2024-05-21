#ifndef __PISIM_HILBERTMOBILITY_H_
#define __PISIM_HILBERTMOBILITY_H_

#include <vector>

#include "../../../Util/Hilbert/HilbertCurve.h"
#include "inet/mobility/base/LineSegmentsMobilityBase.h"
#include "inet/common/INETMath.h"

class HilbertMobility : public inet::LineSegmentsMobilityBase {
protected:
    std::vector<inet::Coord> hilbertPath;
    int currentIndex = 0;
    double speed = 1.0; // Default speed

protected:
    virtual void initialize(int stage) override;
    virtual void setInitialPosition() override;
    virtual void move() override;
    virtual void setTargetPosition() override;
    void calculateNextChange();
    void generateHilbertPath();
};

#endif

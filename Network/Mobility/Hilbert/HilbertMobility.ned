package Network.Mobility.Hilbert;
import inet.mobility.base.MovingMobilityBase;

simple HilbertMobility extends MovingMobilityBase {
    parameters:
        int order = default(4);          // Hilbert curve order (2^order points per side)
        int padding = default(50);       // Padding around the curve in meters
        double networkWidth = default(500);  // Simulation area width
        double networkHeight = default(400); // Simulation area height
        double speed @unit(mps) = default(12mps); // Speed along the path
        double moveInterval @unit(s) = default(0s); // Optional: fixed interval (0 = use speed)
        @class(HilbertMobility);
}
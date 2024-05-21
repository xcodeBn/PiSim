//
// Created by xcodeBn@github.com on 5/20/2024.
// All rights reserved
//

#ifndef HILBERT_CURVE_HPP
#define HILBERT_CURVE_HPP

#include <cmath>
#include <vector>
#include <iostream>


// Class to generate and represent a 2D Hilbert curve
class HilbertCurve {
public:
    // Constructor to initialize the Hilbert curve
    HilbertCurve(int order, int width, int height, int padding = 0)
            : order(order), width(width), height(height), padding(padding) {
        n = 1 << order; // Calculate the size of the grid (2^order)
        totalPoints = n * n; // Total number of points in the Hilbert curve
        scaleX = (width - 2 * padding) / static_cast<float>(n); // Scale factor for the X axis with padding
        scaleY = (height - 2 * padding) / static_cast<float>(n); // Scale factor for the Y axis with padding
        generateCurve(); // Generate the Hilbert curve
    }

    // Get the generated Hilbert curve points
    const std::vector<std::pair<float, float>>& getCurve() const {
        return curve;
    }

private:
    int order, n, totalPoints, padding; // Order of the Hilbert curve, grid size, total points, and padding
    float scaleX, scaleY; // Scale factors for X and Y axes
    int width, height; // Width and height of the drawing area
    std::vector<std::pair<float, float>> curve; // Vector to store the points of the Hilbert curve

    // Function to generate the Hilbert curve
    void generateCurve() {
        for (int i = 0; i < totalPoints; ++i) {
            auto [x, y] = indexToPoint(i); // Convert index to (x, y) coordinates
            // Scale and translate the point to include padding
            curve.emplace_back(padding + x * scaleX, padding + y * scaleY);
        }
    }

    // Convert Hilbert curve index to 2D coordinates
    std::pair<int, int> indexToPoint(int index) const {
        int x = 0, y = 0; // Initialize coordinates
        for (int s = 1; s < n; s *= 2) {
            int rx = (index / 2) & 1; // Determine the x direction
            int ry = (index ^ rx) & 1; // Determine the y direction
            rotate(s, x, y, rx, ry); // Rotate the coordinates
            x += s * rx; // Update x coordinate
            y += s * ry; // Update y coordinate
            index /= 4; // Move to the next level
        }
        return {x, y}; // Return the calculated coordinates
    }

    // Rotate/flip a quadrant appropriately
    void rotate(int s, int &x, int &y, int rx, int ry) const {
        if (ry == 0) { // If the y direction is 0, rotate
            if (rx == 1) { // If the x direction is 1, flip the coordinates
                x = s - 1 - x;
                y = s - 1 - y;
            }
            std::swap(x, y); // Swap the coordinates
        }
    }
};

#endif //HILBERT_CURVE_HPP

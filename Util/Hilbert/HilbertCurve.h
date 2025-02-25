//
// Created by xcodeBn@github.com on 5/20/2024.
// All rights reserved
//

#ifndef HILBERT_CURVE_HPP
#define HILBERT_CURVE_HPP

#include <cmath>
#include <vector>
#include <stdexcept>
#include <iostream>

class HilbertCurve {
public:
    HilbertCurve(int order, int width, int height, int padding = 0)
            : order(order), width(width), height(height), padding(padding) {
        if (order < 0 || width <= 0 || height <= 0 || padding < 0 || padding * 2 >= width || padding * 2 >= height) {
            throw std::invalid_argument("Invalid Hilbert curve parameters: order must be non-negative, width/height must be positive, padding must fit within dimensions.");
        }
        n = 1 << order; // Grid size: 2^order
        totalPoints = n * n; // Total points in the curve
        scaleX = (width - 2 * padding) / static_cast<float>(n); // X-axis scaling
        scaleY = (height - 2 * padding) / static_cast<float>(n); // Y-axis scaling
        generateCurve();
    }

    const std::vector<std::pair<float, float>>& getCurve() const {
        return curve;
    }

private:
    int order, n, totalPoints, padding;
    float scaleX, scaleY;
    int width, height;
    std::vector<std::pair<float, float>> curve;

    void generateCurve() {
        curve.reserve(totalPoints); // Pre-allocate for efficiency
        for (int i = 0; i < totalPoints; ++i) {
            auto [x, y] = indexToPoint(i);
            curve.emplace_back(padding + x * scaleX, padding + y * scaleY);
        }
    }

    std::pair<int, int> indexToPoint(int index) const {
        int x = 0, y = 0;
        for (int s = 1; s < n; s *= 2) {
            int rx = (index / 2) & 1;
            int ry = (index ^ rx) & 1;
            rotate(s, x, y, rx, ry);
            x += s * rx;
            y += s * ry;
            index /= 4;
        }
        return {x, y};
    }

    void rotate(int s, int &x, int &y, int rx, int ry) const {
        if (ry == 0) {
            if (rx == 1) {
                x = s - 1 - x;
                y = s - 1 - y;
            }
            std::swap(x, y);
        }
    }
};

#endif //HILBERT_CURVE_HPP

/*
 * DashSummer.cpp
 *
 *  Created on: Mar 31, 2024
 *      Author: lenovo
 */

#include "DashSummer.h"
#include <string>
#include <iostream>
#include <algorithm>
namespace piutil {

 int DashSummer::calculate(const std::string& str) {
    // Check if the string is empty
    if (str.empty())
        return 0;

    // Check if the string contains only digits (a pure integer)
    bool isPureInteger = true;
    for (char c : str) {
        if (!isdigit(c)) {
            isPureInteger = false;
            break;
        }
    }
    if (isPureInteger) {
        try {
            return std::stoi(str);
        } catch (const std::invalid_argument& e) {
            // If conversion to integer fails, return 0
            return 0;
        }
    }

    // Check if the string starts and ends with integers and contains one dash
    int dashCount = std::count(str.begin(), str.end(), '-');
    if (dashCount != 1)
        return 0;

    size_t dashIndex = str.find('-');
    if (dashIndex == 0 || dashIndex == str.length() - 1)
        return 0;

    // Extract left and right parts of the string
    std::string leftPart = str.substr(0, dashIndex);
    std::string rightPart = str.substr(dashIndex + 1);

    // Check if left and right parts are valid integers
    bool isValid = true;
    try {
        int leftInt = std::stoi(leftPart);
        int rightInt = std::stoi(rightPart);
    } catch (const std::invalid_argument& e) {
        isValid = false;
    }

    // If both parts are valid integers, return their sum
    if (isValid)
        return std::stoi(leftPart) + std::stoi(rightPart);
    else
        return 0;
}

} /* namespace piutil */

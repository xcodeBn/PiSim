#include "StringUtil.h"
#include <iostream>
#include <string>
#include <random>
#include "Util/json/json.h"

namespace piutil {

std::vector<std::string> StringUtil::split(const std::string &str,
        char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;

    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

std::string StringUtil::trim(const std::string &str) {
    size_t first = str.find_first_not_of(" \t\n");
    if (first == std::string::npos) {
        return "";
    }

    size_t last = str.find_last_not_of(" \t\n");
    return str.substr(first, last - first + 1);
}

std::string StringUtil::toLower(const std::string &str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

std::string StringUtil::toUpper(const std::string &str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

std::string StringUtil::generateRandomIntsString() {
    // Initialize random number generator
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dis(1, 100); // Distribution for integers between 1 and 100

    // Generate two random integers
    int random1 = dis(gen);
    int random2 = dis(gen);

    // Concatenate the random integers with a dash separator
    std::string messageText = std::to_string(random1) + "-"
            + std::to_string(random2);

    return messageText;
}

std::string StringUtil::serializeInts(const std::vector<int> &ints,
        char separator) {
    std::ostringstream oss;
    for (size_t i = 0; i < ints.size(); ++i) {
        if (i != 0) {
            oss << separator;
        }
        oss << ints[i];
    }
    return oss.str();
}

std::vector<int> StringUtil::deserializeInts(const std::string &str,
        char separator) {
    std::vector<int> ints;
    std::istringstream iss(str);
    std::string temp;
    while (getline(iss, temp, separator)) {
        ints.push_back(std::stoi(temp));
    }
    return ints;
}

} // namespace piutil

//
// Created by lenovo on 4/1/2024.
//

#ifndef PISIM_STRINGUTIL_H
#define PISIM_STRINGUTIL_H

#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include "Util/json/json.h"
namespace piutil {

class StringUtil {
public:
    static std::vector<std::string> split(const std::string &str,
            char delimiter);
    static std::string trim(const std::string &str);
    static std::string toLower(const std::string &str);
    static std::string toUpper(const std::string &str);
    static std::string generateRandomIntsString();
    static std::string serializeInts(const std::vector<int> &ints,
            char separator);
    static std::vector<int> deserializeInts(const std::string &str,
            char separator);
    static nlohmann::json generateRandomIntsJson();
};

} // namespace piutil

#endif //PISIM_STRINGUTIL_H

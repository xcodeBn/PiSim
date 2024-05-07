#ifndef JSONHELPERREPOSITORY_H
#define JSONHELPERREPOSITORY_H

#include <string>
#include <vector>
#include <utility> // for std::pair
#include  "Util/json/json.h"

class JsonHelperRepository {
protected:
    // Create a JSON object with a single key-value pair
    nlohmann::json createJson(const std::string& key, int value) const {
        return nlohmann::json{{key, value}};
    }

    // Create a JSON object from multiple key-value pairs using a vector of pairs
    nlohmann::json createJson(const std::vector<std::pair<std::string, int>>& keyValuePairs) const {
        nlohmann::json jsonObj;
        for (const auto& kvp : keyValuePairs) {
            jsonObj[kvp.first] = kvp.second;
        }
        return jsonObj;
    }

    // Serialize a JSON object to a string
    std::string serializeJson(const nlohmann::json& jsonObj) const {
        return jsonObj.dump();
    }

    // Deserialize a string to a JSON object
    nlohmann::json deserializeJson(const std::string& payload) const {
        return nlohmann::json::parse(payload);
    }

    // Virtual function to be overridden by derived classes to process JSON data
    virtual void processJsonData(const nlohmann::json& jsonData) {

    };

public:
    // Virtual destructor to ensure proper cleanup of derived classes
    virtual ~JsonHelperRepository() {}
};

#endif // JSONHELPERREPOSITORY_H

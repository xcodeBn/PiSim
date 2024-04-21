#ifndef SUMMER_H
#define SUMMER_H

#include <string>
#include "Util/json/json.h"
#include "Core/repository/IPiSerializable.h"

// Use the nlohmann::json library for JSON operations
using json = nlohmann::json;



/**
 * @class Summer
 * @brief A class that serializes two integer properties (`a` and `b`) to JSON,
 *        and can deserialize from JSON back to its properties.
 *
 * This class implements the `IPiSerializable` interface, which includes methods for
 * serialization and deserialization of the object's state to and from a JSON formatted string.
 */
class Summer : public piutil::IPiSerializable {
public:
    int a; ///< First integer component of the Summer class.
    int b; ///< Second integer component of the Summer class.

    /**
     * @brief Construct a new Summer object.
     *
     * @param a Initial value for the component `a`, default is 0.
     * @param b Initial value for the component `b`, default is 0.
     */
    Summer(int a = 0, int b = 0) : a(a), b(b) {}

    /**
     * @brief Serialize the object to a JSON string.
     *
     * This method uses the nlohmann::json library to create a JSON representation
     * of the object. It encapsulates properties `a` and `b` into a JSON object.
     *
     * @return std::string A string containing the JSON formatted serialization of the object.
     */
    std::string serialize() const override {
        json j = {{"a", a}, {"b", b}};
        return j.dump();  // Convert the json object to a string and return
    }

    /**
     * @brief Deserialize the JSON formatted string to an object.
     *
     * This method parses a JSON formatted string and uses it to populate the object's
     * properties. It expects the string to encode a JSON object with integer fields `a` and `b`.
     *
     * @param s A string containing the JSON formatted serialization of a Summer object.
     */
    void deserialize(const std::string& s) override {
        json j = json::parse(s);
        a = j.at("a").get<int>();
        b = j.at("b").get<int>();
    }

    /**
     * @brief Static method to create a new instance of Summer by deserializing from a JSON string.
     *
     * This method creates a new instance of Summer, initializes it using data
     * deserialized from a JSON formatted string, and returns it. It is useful when you
     * want to create a new object rather than deserializing to an existing object.
     *
     * @param s A string containing the JSON formatted serialization of a Summer object.
     * @return IPiSerializable* Pointer to the newly created Summer object.
     */
    IPiSerializable* deserializeToNewObject(const std::string& s) const override {
        json j = json::parse(s);
        int tempA = j.at("a").get<int>();
        int tempB = j.at("b").get<int>();
        return new Summer(tempA, tempB);  // Allocate a new Summer object and return it
    }
};



#endif // SUMMER_H

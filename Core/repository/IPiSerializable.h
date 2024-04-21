#ifndef IPI_SERIALIZABLE_H
#define IPI_SERIALIZABLE_H

#include <string>

namespace piutil {

class IPiSerializable {
public:
    // Serialize this object to a JSON string
    virtual std::string serialize() const = 0;

    // Deserialize a JSON string to this object (modifies the object in place)
    virtual void deserialize(const std::string& s) = 0;

    // Static method to deserialize a JSON string to a new object of the implementing class
    virtual IPiSerializable* deserializeToNewObject(const std::string& s) const = 0;

    // Virtual destructor to ensure derived destructors are called
    virtual ~IPiSerializable() {}
};

} // namespace piutil

#endif // IPI_SERIALIZABLE_H

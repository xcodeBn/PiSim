#ifndef ROLE_TYPES_H
#define ROLE_TYPES_H

// Enum to represent different operational roles in the application
enum class RoleType {
    INITIAL_SENDER, // Represents a component that sends initial messages
    FORWARDER       // Represents a component that forwards received messages
};

#endif // ROLE_TYPES_H

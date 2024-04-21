//
// Generated file, do not edit! Created by opp_msgtool 6.0 from Network/Packet/SumPacket.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "SumPacket_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

Register_Class(SumPacket)

SumPacket::SumPacket() : ::inet::FieldsChunk()
{
}

SumPacket::SumPacket(const SumPacket& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

SumPacket::~SumPacket()
{
}

SumPacket& SumPacket::operator=(const SumPacket& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void SumPacket::copy(const SumPacket& other)
{
    this->data = other.data;
    this->sourcePort = other.sourcePort;
    this->destinationPort = other.destinationPort;
    this->senderName = other.senderName;
    this->recieverName = other.recieverName;
    this->isTest_ = other.isTest_;
}

void SumPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->data);
    doParsimPacking(b,this->sourcePort);
    doParsimPacking(b,this->destinationPort);
    doParsimPacking(b,this->senderName);
    doParsimPacking(b,this->recieverName);
    doParsimPacking(b,this->isTest_);
}

void SumPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->data);
    doParsimUnpacking(b,this->sourcePort);
    doParsimUnpacking(b,this->destinationPort);
    doParsimUnpacking(b,this->senderName);
    doParsimUnpacking(b,this->recieverName);
    doParsimUnpacking(b,this->isTest_);
}

const char * SumPacket::getData() const
{
    return this->data.c_str();
}

void SumPacket::setData(const char * data)
{
    handleChange();
    this->data = data;
}

int SumPacket::getSourcePort() const
{
    return this->sourcePort;
}

void SumPacket::setSourcePort(int sourcePort)
{
    handleChange();
    this->sourcePort = sourcePort;
}

int SumPacket::getDestinationPort() const
{
    return this->destinationPort;
}

void SumPacket::setDestinationPort(int destinationPort)
{
    handleChange();
    this->destinationPort = destinationPort;
}

const char * SumPacket::getSenderName() const
{
    return this->senderName.c_str();
}

void SumPacket::setSenderName(const char * senderName)
{
    handleChange();
    this->senderName = senderName;
}

const char * SumPacket::getRecieverName() const
{
    return this->recieverName.c_str();
}

void SumPacket::setRecieverName(const char * recieverName)
{
    handleChange();
    this->recieverName = recieverName;
}

bool SumPacket::isTest() const
{
    return this->isTest_;
}

void SumPacket::setIsTest(bool isTest)
{
    handleChange();
    this->isTest_ = isTest;
}

class SumPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_data,
        FIELD_sourcePort,
        FIELD_destinationPort,
        FIELD_senderName,
        FIELD_recieverName,
        FIELD_isTest,
    };
  public:
    SumPacketDescriptor();
    virtual ~SumPacketDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(SumPacketDescriptor)

SumPacketDescriptor::SumPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(SumPacket)), "inet::FieldsChunk")
{
    propertyNames = nullptr;
}

SumPacketDescriptor::~SumPacketDescriptor()
{
    delete[] propertyNames;
}

bool SumPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SumPacket *>(obj)!=nullptr;
}

const char **SumPacketDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *SumPacketDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int SumPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 6+base->getFieldCount() : 6;
}

unsigned int SumPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_data
        FD_ISEDITABLE,    // FIELD_sourcePort
        FD_ISEDITABLE,    // FIELD_destinationPort
        FD_ISEDITABLE,    // FIELD_senderName
        FD_ISEDITABLE,    // FIELD_recieverName
        FD_ISEDITABLE,    // FIELD_isTest
    };
    return (field >= 0 && field < 6) ? fieldTypeFlags[field] : 0;
}

const char *SumPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "data",
        "sourcePort",
        "destinationPort",
        "senderName",
        "recieverName",
        "isTest",
    };
    return (field >= 0 && field < 6) ? fieldNames[field] : nullptr;
}

int SumPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "data") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "sourcePort") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "destinationPort") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "senderName") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "recieverName") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "isTest") == 0) return baseIndex + 5;
    return base ? base->findField(fieldName) : -1;
}

const char *SumPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",    // FIELD_data
        "int",    // FIELD_sourcePort
        "int",    // FIELD_destinationPort
        "string",    // FIELD_senderName
        "string",    // FIELD_recieverName
        "bool",    // FIELD_isTest
    };
    return (field >= 0 && field < 6) ? fieldTypeStrings[field] : nullptr;
}

const char **SumPacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *SumPacketDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int SumPacketDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    SumPacket *pp = omnetpp::fromAnyPtr<SumPacket>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void SumPacketDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    SumPacket *pp = omnetpp::fromAnyPtr<SumPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'SumPacket'", field);
    }
}

const char *SumPacketDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    SumPacket *pp = omnetpp::fromAnyPtr<SumPacket>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SumPacketDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    SumPacket *pp = omnetpp::fromAnyPtr<SumPacket>(object); (void)pp;
    switch (field) {
        case FIELD_data: return oppstring2string(pp->getData());
        case FIELD_sourcePort: return long2string(pp->getSourcePort());
        case FIELD_destinationPort: return long2string(pp->getDestinationPort());
        case FIELD_senderName: return oppstring2string(pp->getSenderName());
        case FIELD_recieverName: return oppstring2string(pp->getRecieverName());
        case FIELD_isTest: return bool2string(pp->isTest());
        default: return "";
    }
}

void SumPacketDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    SumPacket *pp = omnetpp::fromAnyPtr<SumPacket>(object); (void)pp;
    switch (field) {
        case FIELD_data: pp->setData((value)); break;
        case FIELD_sourcePort: pp->setSourcePort(string2long(value)); break;
        case FIELD_destinationPort: pp->setDestinationPort(string2long(value)); break;
        case FIELD_senderName: pp->setSenderName((value)); break;
        case FIELD_recieverName: pp->setRecieverName((value)); break;
        case FIELD_isTest: pp->setIsTest(string2bool(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'SumPacket'", field);
    }
}

omnetpp::cValue SumPacketDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    SumPacket *pp = omnetpp::fromAnyPtr<SumPacket>(object); (void)pp;
    switch (field) {
        case FIELD_data: return pp->getData();
        case FIELD_sourcePort: return pp->getSourcePort();
        case FIELD_destinationPort: return pp->getDestinationPort();
        case FIELD_senderName: return pp->getSenderName();
        case FIELD_recieverName: return pp->getRecieverName();
        case FIELD_isTest: return pp->isTest();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'SumPacket' as cValue -- field index out of range?", field);
    }
}

void SumPacketDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    SumPacket *pp = omnetpp::fromAnyPtr<SumPacket>(object); (void)pp;
    switch (field) {
        case FIELD_data: pp->setData(value.stringValue()); break;
        case FIELD_sourcePort: pp->setSourcePort(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_destinationPort: pp->setDestinationPort(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_senderName: pp->setSenderName(value.stringValue()); break;
        case FIELD_recieverName: pp->setRecieverName(value.stringValue()); break;
        case FIELD_isTest: pp->setIsTest(value.boolValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'SumPacket'", field);
    }
}

const char *SumPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr SumPacketDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    SumPacket *pp = omnetpp::fromAnyPtr<SumPacket>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void SumPacketDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    SumPacket *pp = omnetpp::fromAnyPtr<SumPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'SumPacket'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp


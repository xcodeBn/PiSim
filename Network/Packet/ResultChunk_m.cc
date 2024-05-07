//
// Generated file, do not edit! Created by opp_msgtool 6.0 from Network/Packet/ResultChunk.msg.
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
#include "ResultChunk_m.h"

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

Register_Class(ResultChunk)

ResultChunk::ResultChunk() : ::inet::FieldsChunk()
{
}

ResultChunk::ResultChunk(const ResultChunk& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

ResultChunk::~ResultChunk()
{
}

ResultChunk& ResultChunk::operator=(const ResultChunk& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void ResultChunk::copy(const ResultChunk& other)
{
    this->resultData = other.resultData;
    this->sourcePort = other.sourcePort;
    this->destinationPort = other.destinationPort;
    this->distinationAdresses = other.distinationAdresses;
}

void ResultChunk::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->resultData);
    doParsimPacking(b,this->sourcePort);
    doParsimPacking(b,this->destinationPort);
    doParsimPacking(b,this->distinationAdresses);
}

void ResultChunk::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->resultData);
    doParsimUnpacking(b,this->sourcePort);
    doParsimUnpacking(b,this->destinationPort);
    doParsimUnpacking(b,this->distinationAdresses);
}

const char * ResultChunk::getResultData() const
{
    return this->resultData.c_str();
}

void ResultChunk::setResultData(const char * resultData)
{
    handleChange();
    this->resultData = resultData;
}

int ResultChunk::getSourcePort() const
{
    return this->sourcePort;
}

void ResultChunk::setSourcePort(int sourcePort)
{
    handleChange();
    this->sourcePort = sourcePort;
}

int ResultChunk::getDestinationPort() const
{
    return this->destinationPort;
}

void ResultChunk::setDestinationPort(int destinationPort)
{
    handleChange();
    this->destinationPort = destinationPort;
}

const char * ResultChunk::getDistinationAdresses() const
{
    return this->distinationAdresses.c_str();
}

void ResultChunk::setDistinationAdresses(const char * distinationAdresses)
{
    handleChange();
    this->distinationAdresses = distinationAdresses;
}

class ResultChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_resultData,
        FIELD_sourcePort,
        FIELD_destinationPort,
        FIELD_distinationAdresses,
    };
  public:
    ResultChunkDescriptor();
    virtual ~ResultChunkDescriptor();

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

Register_ClassDescriptor(ResultChunkDescriptor)

ResultChunkDescriptor::ResultChunkDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(ResultChunk)), "inet::FieldsChunk")
{
    propertyNames = nullptr;
}

ResultChunkDescriptor::~ResultChunkDescriptor()
{
    delete[] propertyNames;
}

bool ResultChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ResultChunk *>(obj)!=nullptr;
}

const char **ResultChunkDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *ResultChunkDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int ResultChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 4+base->getFieldCount() : 4;
}

unsigned int ResultChunkDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_resultData
        FD_ISEDITABLE,    // FIELD_sourcePort
        FD_ISEDITABLE,    // FIELD_destinationPort
        FD_ISEDITABLE,    // FIELD_distinationAdresses
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *ResultChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "resultData",
        "sourcePort",
        "destinationPort",
        "distinationAdresses",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int ResultChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "resultData") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "sourcePort") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "destinationPort") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "distinationAdresses") == 0) return baseIndex + 3;
    return base ? base->findField(fieldName) : -1;
}

const char *ResultChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",    // FIELD_resultData
        "int",    // FIELD_sourcePort
        "int",    // FIELD_destinationPort
        "string",    // FIELD_distinationAdresses
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **ResultChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *ResultChunkDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int ResultChunkDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    ResultChunk *pp = omnetpp::fromAnyPtr<ResultChunk>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void ResultChunkDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    ResultChunk *pp = omnetpp::fromAnyPtr<ResultChunk>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'ResultChunk'", field);
    }
}

const char *ResultChunkDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    ResultChunk *pp = omnetpp::fromAnyPtr<ResultChunk>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ResultChunkDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    ResultChunk *pp = omnetpp::fromAnyPtr<ResultChunk>(object); (void)pp;
    switch (field) {
        case FIELD_resultData: return oppstring2string(pp->getResultData());
        case FIELD_sourcePort: return long2string(pp->getSourcePort());
        case FIELD_destinationPort: return long2string(pp->getDestinationPort());
        case FIELD_distinationAdresses: return oppstring2string(pp->getDistinationAdresses());
        default: return "";
    }
}

void ResultChunkDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    ResultChunk *pp = omnetpp::fromAnyPtr<ResultChunk>(object); (void)pp;
    switch (field) {
        case FIELD_resultData: pp->setResultData((value)); break;
        case FIELD_sourcePort: pp->setSourcePort(string2long(value)); break;
        case FIELD_destinationPort: pp->setDestinationPort(string2long(value)); break;
        case FIELD_distinationAdresses: pp->setDistinationAdresses((value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ResultChunk'", field);
    }
}

omnetpp::cValue ResultChunkDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    ResultChunk *pp = omnetpp::fromAnyPtr<ResultChunk>(object); (void)pp;
    switch (field) {
        case FIELD_resultData: return pp->getResultData();
        case FIELD_sourcePort: return pp->getSourcePort();
        case FIELD_destinationPort: return pp->getDestinationPort();
        case FIELD_distinationAdresses: return pp->getDistinationAdresses();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'ResultChunk' as cValue -- field index out of range?", field);
    }
}

void ResultChunkDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    ResultChunk *pp = omnetpp::fromAnyPtr<ResultChunk>(object); (void)pp;
    switch (field) {
        case FIELD_resultData: pp->setResultData(value.stringValue()); break;
        case FIELD_sourcePort: pp->setSourcePort(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_destinationPort: pp->setDestinationPort(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_distinationAdresses: pp->setDistinationAdresses(value.stringValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ResultChunk'", field);
    }
}

const char *ResultChunkDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr ResultChunkDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    ResultChunk *pp = omnetpp::fromAnyPtr<ResultChunk>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void ResultChunkDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    ResultChunk *pp = omnetpp::fromAnyPtr<ResultChunk>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ResultChunk'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp


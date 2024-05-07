//
// Generated file, do not edit! Created by opp_msgtool 6.0 from Network/Packet/EvenOddChunk.msg.
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
#include "EvenOddChunk_m.h"

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

Register_Class(EvenOddChunk)

EvenOddChunk::EvenOddChunk() : ::inet::FieldsChunk()
{
}

EvenOddChunk::EvenOddChunk(const EvenOddChunk& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

EvenOddChunk::~EvenOddChunk()
{
}

EvenOddChunk& EvenOddChunk::operator=(const EvenOddChunk& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void EvenOddChunk::copy(const EvenOddChunk& other)
{
    this->data = other.data;
    this->isEven_ = other.isEven_;
    this->useJson = other.useJson;
    this->finalOdd = other.finalOdd;
    this->extraData = other.extraData;
    this->details = other.details;
}

void EvenOddChunk::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->data);
    doParsimPacking(b,this->isEven_);
    doParsimPacking(b,this->useJson);
    doParsimPacking(b,this->finalOdd);
    doParsimPacking(b,this->extraData);
    doParsimPacking(b,this->details);
}

void EvenOddChunk::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->data);
    doParsimUnpacking(b,this->isEven_);
    doParsimUnpacking(b,this->useJson);
    doParsimUnpacking(b,this->finalOdd);
    doParsimUnpacking(b,this->extraData);
    doParsimUnpacking(b,this->details);
}

const char * EvenOddChunk::getData() const
{
    return this->data.c_str();
}

void EvenOddChunk::setData(const char * data)
{
    handleChange();
    this->data = data;
}

bool EvenOddChunk::isEven() const
{
    return this->isEven_;
}

void EvenOddChunk::setIsEven(bool isEven)
{
    handleChange();
    this->isEven_ = isEven;
}

bool EvenOddChunk::getUseJson() const
{
    return this->useJson;
}

void EvenOddChunk::setUseJson(bool useJson)
{
    handleChange();
    this->useJson = useJson;
}

bool EvenOddChunk::getFinalOdd() const
{
    return this->finalOdd;
}

void EvenOddChunk::setFinalOdd(bool finalOdd)
{
    handleChange();
    this->finalOdd = finalOdd;
}

const char * EvenOddChunk::getExtraData() const
{
    return this->extraData.c_str();
}

void EvenOddChunk::setExtraData(const char * extraData)
{
    handleChange();
    this->extraData = extraData;
}

const char * EvenOddChunk::getDetails() const
{
    return this->details.c_str();
}

void EvenOddChunk::setDetails(const char * details)
{
    handleChange();
    this->details = details;
}

class EvenOddChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_data,
        FIELD_isEven,
        FIELD_useJson,
        FIELD_finalOdd,
        FIELD_extraData,
        FIELD_details,
    };
  public:
    EvenOddChunkDescriptor();
    virtual ~EvenOddChunkDescriptor();

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

Register_ClassDescriptor(EvenOddChunkDescriptor)

EvenOddChunkDescriptor::EvenOddChunkDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(EvenOddChunk)), "inet::FieldsChunk")
{
    propertyNames = nullptr;
}

EvenOddChunkDescriptor::~EvenOddChunkDescriptor()
{
    delete[] propertyNames;
}

bool EvenOddChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EvenOddChunk *>(obj)!=nullptr;
}

const char **EvenOddChunkDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *EvenOddChunkDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int EvenOddChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 6+base->getFieldCount() : 6;
}

unsigned int EvenOddChunkDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_data
        FD_ISEDITABLE,    // FIELD_isEven
        FD_ISEDITABLE,    // FIELD_useJson
        FD_ISEDITABLE,    // FIELD_finalOdd
        FD_ISEDITABLE,    // FIELD_extraData
        FD_ISEDITABLE,    // FIELD_details
    };
    return (field >= 0 && field < 6) ? fieldTypeFlags[field] : 0;
}

const char *EvenOddChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "data",
        "isEven",
        "useJson",
        "finalOdd",
        "extraData",
        "details",
    };
    return (field >= 0 && field < 6) ? fieldNames[field] : nullptr;
}

int EvenOddChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "data") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "isEven") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "useJson") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "finalOdd") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "extraData") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "details") == 0) return baseIndex + 5;
    return base ? base->findField(fieldName) : -1;
}

const char *EvenOddChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",    // FIELD_data
        "bool",    // FIELD_isEven
        "bool",    // FIELD_useJson
        "bool",    // FIELD_finalOdd
        "string",    // FIELD_extraData
        "string",    // FIELD_details
    };
    return (field >= 0 && field < 6) ? fieldTypeStrings[field] : nullptr;
}

const char **EvenOddChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *EvenOddChunkDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int EvenOddChunkDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    EvenOddChunk *pp = omnetpp::fromAnyPtr<EvenOddChunk>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void EvenOddChunkDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    EvenOddChunk *pp = omnetpp::fromAnyPtr<EvenOddChunk>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'EvenOddChunk'", field);
    }
}

const char *EvenOddChunkDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    EvenOddChunk *pp = omnetpp::fromAnyPtr<EvenOddChunk>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string EvenOddChunkDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    EvenOddChunk *pp = omnetpp::fromAnyPtr<EvenOddChunk>(object); (void)pp;
    switch (field) {
        case FIELD_data: return oppstring2string(pp->getData());
        case FIELD_isEven: return bool2string(pp->isEven());
        case FIELD_useJson: return bool2string(pp->getUseJson());
        case FIELD_finalOdd: return bool2string(pp->getFinalOdd());
        case FIELD_extraData: return oppstring2string(pp->getExtraData());
        case FIELD_details: return oppstring2string(pp->getDetails());
        default: return "";
    }
}

void EvenOddChunkDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    EvenOddChunk *pp = omnetpp::fromAnyPtr<EvenOddChunk>(object); (void)pp;
    switch (field) {
        case FIELD_data: pp->setData((value)); break;
        case FIELD_isEven: pp->setIsEven(string2bool(value)); break;
        case FIELD_useJson: pp->setUseJson(string2bool(value)); break;
        case FIELD_finalOdd: pp->setFinalOdd(string2bool(value)); break;
        case FIELD_extraData: pp->setExtraData((value)); break;
        case FIELD_details: pp->setDetails((value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EvenOddChunk'", field);
    }
}

omnetpp::cValue EvenOddChunkDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    EvenOddChunk *pp = omnetpp::fromAnyPtr<EvenOddChunk>(object); (void)pp;
    switch (field) {
        case FIELD_data: return pp->getData();
        case FIELD_isEven: return pp->isEven();
        case FIELD_useJson: return pp->getUseJson();
        case FIELD_finalOdd: return pp->getFinalOdd();
        case FIELD_extraData: return pp->getExtraData();
        case FIELD_details: return pp->getDetails();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'EvenOddChunk' as cValue -- field index out of range?", field);
    }
}

void EvenOddChunkDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    EvenOddChunk *pp = omnetpp::fromAnyPtr<EvenOddChunk>(object); (void)pp;
    switch (field) {
        case FIELD_data: pp->setData(value.stringValue()); break;
        case FIELD_isEven: pp->setIsEven(value.boolValue()); break;
        case FIELD_useJson: pp->setUseJson(value.boolValue()); break;
        case FIELD_finalOdd: pp->setFinalOdd(value.boolValue()); break;
        case FIELD_extraData: pp->setExtraData(value.stringValue()); break;
        case FIELD_details: pp->setDetails(value.stringValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EvenOddChunk'", field);
    }
}

const char *EvenOddChunkDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr EvenOddChunkDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    EvenOddChunk *pp = omnetpp::fromAnyPtr<EvenOddChunk>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void EvenOddChunkDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    EvenOddChunk *pp = omnetpp::fromAnyPtr<EvenOddChunk>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EvenOddChunk'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp


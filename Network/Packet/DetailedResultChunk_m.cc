//
// Generated file, do not edit! Created by opp_msgtool 6.0 from Network/Packet/DetailedResultChunk.msg.
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
#include "DetailedResultChunk_m.h"

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

Register_Class(DetailedResultChunk)

DetailedResultChunk::DetailedResultChunk() : ::inet::FieldsChunk()
{
}

DetailedResultChunk::DetailedResultChunk(const DetailedResultChunk& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

DetailedResultChunk::~DetailedResultChunk()
{
}

DetailedResultChunk& DetailedResultChunk::operator=(const DetailedResultChunk& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void DetailedResultChunk::copy(const DetailedResultChunk& other)
{
    this->data = other.data;
    this->details = other.details;
    this->Sumresults = other.Sumresults;
    this->isEven_ = other.isEven_;
    this->sentBy = other.sentBy;
}

void DetailedResultChunk::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->data);
    doParsimPacking(b,this->details);
    doParsimPacking(b,this->Sumresults);
    doParsimPacking(b,this->isEven_);
    doParsimPacking(b,this->sentBy);
}

void DetailedResultChunk::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->data);
    doParsimUnpacking(b,this->details);
    doParsimUnpacking(b,this->Sumresults);
    doParsimUnpacking(b,this->isEven_);
    doParsimUnpacking(b,this->sentBy);
}

const char * DetailedResultChunk::getData() const
{
    return this->data.c_str();
}

void DetailedResultChunk::setData(const char * data)
{
    handleChange();
    this->data = data;
}

const char * DetailedResultChunk::getDetails() const
{
    return this->details.c_str();
}

void DetailedResultChunk::setDetails(const char * details)
{
    handleChange();
    this->details = details;
}

int DetailedResultChunk::getSumresults() const
{
    return this->Sumresults;
}

void DetailedResultChunk::setSumresults(int Sumresults)
{
    handleChange();
    this->Sumresults = Sumresults;
}

bool DetailedResultChunk::isEven() const
{
    return this->isEven_;
}

void DetailedResultChunk::setIsEven(bool isEven)
{
    handleChange();
    this->isEven_ = isEven;
}

const char * DetailedResultChunk::getSentBy() const
{
    return this->sentBy.c_str();
}

void DetailedResultChunk::setSentBy(const char * sentBy)
{
    handleChange();
    this->sentBy = sentBy;
}

class DetailedResultChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_data,
        FIELD_details,
        FIELD_Sumresults,
        FIELD_isEven,
        FIELD_sentBy,
    };
  public:
    DetailedResultChunkDescriptor();
    virtual ~DetailedResultChunkDescriptor();

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

Register_ClassDescriptor(DetailedResultChunkDescriptor)

DetailedResultChunkDescriptor::DetailedResultChunkDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(DetailedResultChunk)), "inet::FieldsChunk")
{
    propertyNames = nullptr;
}

DetailedResultChunkDescriptor::~DetailedResultChunkDescriptor()
{
    delete[] propertyNames;
}

bool DetailedResultChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<DetailedResultChunk *>(obj)!=nullptr;
}

const char **DetailedResultChunkDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *DetailedResultChunkDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int DetailedResultChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 5+base->getFieldCount() : 5;
}

unsigned int DetailedResultChunkDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_data
        FD_ISEDITABLE,    // FIELD_details
        FD_ISEDITABLE,    // FIELD_Sumresults
        FD_ISEDITABLE,    // FIELD_isEven
        FD_ISEDITABLE,    // FIELD_sentBy
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *DetailedResultChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "data",
        "details",
        "Sumresults",
        "isEven",
        "sentBy",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int DetailedResultChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "data") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "details") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "Sumresults") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "isEven") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "sentBy") == 0) return baseIndex + 4;
    return base ? base->findField(fieldName) : -1;
}

const char *DetailedResultChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",    // FIELD_data
        "string",    // FIELD_details
        "int",    // FIELD_Sumresults
        "bool",    // FIELD_isEven
        "string",    // FIELD_sentBy
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **DetailedResultChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *DetailedResultChunkDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int DetailedResultChunkDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    DetailedResultChunk *pp = omnetpp::fromAnyPtr<DetailedResultChunk>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void DetailedResultChunkDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    DetailedResultChunk *pp = omnetpp::fromAnyPtr<DetailedResultChunk>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'DetailedResultChunk'", field);
    }
}

const char *DetailedResultChunkDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    DetailedResultChunk *pp = omnetpp::fromAnyPtr<DetailedResultChunk>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string DetailedResultChunkDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    DetailedResultChunk *pp = omnetpp::fromAnyPtr<DetailedResultChunk>(object); (void)pp;
    switch (field) {
        case FIELD_data: return oppstring2string(pp->getData());
        case FIELD_details: return oppstring2string(pp->getDetails());
        case FIELD_Sumresults: return long2string(pp->getSumresults());
        case FIELD_isEven: return bool2string(pp->isEven());
        case FIELD_sentBy: return oppstring2string(pp->getSentBy());
        default: return "";
    }
}

void DetailedResultChunkDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DetailedResultChunk *pp = omnetpp::fromAnyPtr<DetailedResultChunk>(object); (void)pp;
    switch (field) {
        case FIELD_data: pp->setData((value)); break;
        case FIELD_details: pp->setDetails((value)); break;
        case FIELD_Sumresults: pp->setSumresults(string2long(value)); break;
        case FIELD_isEven: pp->setIsEven(string2bool(value)); break;
        case FIELD_sentBy: pp->setSentBy((value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DetailedResultChunk'", field);
    }
}

omnetpp::cValue DetailedResultChunkDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    DetailedResultChunk *pp = omnetpp::fromAnyPtr<DetailedResultChunk>(object); (void)pp;
    switch (field) {
        case FIELD_data: return pp->getData();
        case FIELD_details: return pp->getDetails();
        case FIELD_Sumresults: return pp->getSumresults();
        case FIELD_isEven: return pp->isEven();
        case FIELD_sentBy: return pp->getSentBy();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'DetailedResultChunk' as cValue -- field index out of range?", field);
    }
}

void DetailedResultChunkDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DetailedResultChunk *pp = omnetpp::fromAnyPtr<DetailedResultChunk>(object); (void)pp;
    switch (field) {
        case FIELD_data: pp->setData(value.stringValue()); break;
        case FIELD_details: pp->setDetails(value.stringValue()); break;
        case FIELD_Sumresults: pp->setSumresults(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_isEven: pp->setIsEven(value.boolValue()); break;
        case FIELD_sentBy: pp->setSentBy(value.stringValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DetailedResultChunk'", field);
    }
}

const char *DetailedResultChunkDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr DetailedResultChunkDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    DetailedResultChunk *pp = omnetpp::fromAnyPtr<DetailedResultChunk>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void DetailedResultChunkDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    DetailedResultChunk *pp = omnetpp::fromAnyPtr<DetailedResultChunk>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DetailedResultChunk'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp


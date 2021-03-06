// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MsgHead.proto

#ifndef PROTOBUF_MsgHead_2eproto__INCLUDED
#define PROTOBUF_MsgHead_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2004001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_message_reflection.h>
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_MsgHead_2eproto();
void protobuf_AssignDesc_MsgHead_2eproto();
void protobuf_ShutdownFile_MsgHead_2eproto();

class MsgHead;

enum MsgType {
  C2S_MsgNull = 0,
  C2S_MsgLoginReq = 1,
  C2S_MsgCreateAcountReq = 2,
  C2S_MsgLoginMacReq = 3,
  C2S_MsgBindMailReq = 4,
  C2S_MsgUnbindMacReq = 5,
  C2S_MsgBindMacReq = 6,
  C2S_MsgMailLoginReq = 7,
  C2S_GSBegin = 300,
  C2S_MsgSeedCellReq = 301,
  C2S_MsgSpreadManureReq = 302,
  C2S_MsgGatherPloughCellReq = 303,
  C2S_MsgFarmStateReq = 304,
  C2S_MsgWaterCellReq = 305,
  C2S_MsgTechnologyStateReq = 306,
  C2S_MsgOpenTechLevelReq = 307,
  C2S_MsgApplyAddTechInfoReq = 308,
  C2S_MsgAddTechValueReq = 309,
  C2S_MsgBuildMillReq = 310,
  C2S_MsgBuildWaterWayReq = 311,
  C2S_MsgCreateFarmReq = 312,
  C2S_MsgCreateCellReq = 313,
  C2S_GSEnd = 500,
  C2S_END = 998,
  G2C_Begin = 999,
  G2C_LoginACK = 1000,
  G2C_MsgG2CErrorACK = 1001,
  G2C_End = 2000,
  Gate2LG_Begin = 2001,
  Gate2LG_MsgGate2LGLoginReq = 2002,
  Gate2LG_MsgGate2LGClientDisconnect = 2003,
  Gate2LG_MsgGate2LGLoginMailReq = 2004,
  Gate2LG_MsgGate2LGLoginUserInfoList = 2005,
  Gate2LG_End = 3000,
  LG2Gate_Begin = 3001,
  LG2Gate_MsgLG2GateLoginACK = 3002,
  LG2C_MsgBindMailACK = 3003,
  LG2Gate_MsgLG2GateReqLoginUserList = 3004,
  LG2Gate_End = 4000,
  GS_MsgGate2GSLoginReq = 4001,
  GS_MsgGaet2GSLoginOutReq = 4002,
  GS2Client_GS2GateLoginOKACK = 5001,
  GS2C_Begin = 5500,
  GS2C_MsgSeedCellACK = 5502,
  GS2C_MsgSpreadManureACK = 5503,
  GS2C_MsgGatherPloughCellACK = 5504,
  GS2C_MsgFarmErrorACK = 5505,
  GS2C_MsgFarmInfoACK = 5506,
  GS2C_MsgWaterCellACK = 5507,
  GS2C_MsgFarmEnd = 5507,
  GS2C_MsgTechnologyStateACK = 5508,
  GS2C_MsgOpenTechLevelACK = 5509,
  GS2C_MsgApplyAddTechInfoACK = 5510,
  GS2C_MsgAddTechValueACK = 5511,
  GS2C_MsgBuildMillACK = 5512,
  GS2C_MsgCreateFarmACK = 5513,
  GS2C_MsgCreateCellACK = 5514,
  GS2C_End = 6000
};
bool MsgType_IsValid(int value);
const MsgType MsgType_MIN = C2S_MsgNull;
const MsgType MsgType_MAX = GS2C_End;
const int MsgType_ARRAYSIZE = MsgType_MAX + 1;

const ::google::protobuf::EnumDescriptor* MsgType_descriptor();
inline const ::std::string& MsgType_Name(MsgType value) {
  return ::google::protobuf::internal::NameOfEnum(
    MsgType_descriptor(), value);
}
inline bool MsgType_Parse(
    const ::std::string& name, MsgType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<MsgType>(
    MsgType_descriptor(), name, value);
}
// ===================================================================

class MsgHead : public ::google::protobuf::Message {
 public:
  MsgHead();
  virtual ~MsgHead();
  
  MsgHead(const MsgHead& from);
  
  inline MsgHead& operator=(const MsgHead& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const MsgHead& default_instance();
  
  void Swap(MsgHead* other);
  
  // implements Message ----------------------------------------------
  
  MsgHead* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const MsgHead& from);
  void MergeFrom(const MsgHead& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required .MsgType Type = 1;
  inline bool has_type() const;
  inline void clear_type();
  static const int kTypeFieldNumber = 1;
  inline MsgType type() const;
  inline void set_type(MsgType value);
  
  // required int32 msgSize = 2;
  inline bool has_msgsize() const;
  inline void clear_msgsize();
  static const int kMsgSizeFieldNumber = 2;
  inline ::google::protobuf::int32 msgsize() const;
  inline void set_msgsize(::google::protobuf::int32 value);
  
  // required uint64 account = 3;
  inline bool has_account() const;
  inline void clear_account();
  static const int kAccountFieldNumber = 3;
  inline ::google::protobuf::uint64 account() const;
  inline void set_account(::google::protobuf::uint64 value);
  
  // required bytes body = 4;
  inline bool has_body() const;
  inline void clear_body();
  static const int kBodyFieldNumber = 4;
  inline const ::std::string& body() const;
  inline void set_body(const ::std::string& value);
  inline void set_body(const char* value);
  inline void set_body(const void* value, size_t size);
  inline ::std::string* mutable_body();
  inline ::std::string* release_body();
  
  // @@protoc_insertion_point(class_scope:MsgHead)
 private:
  inline void set_has_type();
  inline void clear_has_type();
  inline void set_has_msgsize();
  inline void clear_has_msgsize();
  inline void set_has_account();
  inline void clear_has_account();
  inline void set_has_body();
  inline void clear_has_body();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  int type_;
  ::google::protobuf::int32 msgsize_;
  ::google::protobuf::uint64 account_;
  ::std::string* body_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(4 + 31) / 32];
  
  friend void  protobuf_AddDesc_MsgHead_2eproto();
  friend void protobuf_AssignDesc_MsgHead_2eproto();
  friend void protobuf_ShutdownFile_MsgHead_2eproto();
  
  void InitAsDefaultInstance();
  static MsgHead* default_instance_;
};
// ===================================================================


// ===================================================================

// MsgHead

// required .MsgType Type = 1;
inline bool MsgHead::has_type() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void MsgHead::set_has_type() {
  _has_bits_[0] |= 0x00000001u;
}
inline void MsgHead::clear_has_type() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void MsgHead::clear_type() {
  type_ = 0;
  clear_has_type();
}
inline MsgType MsgHead::type() const {
  return static_cast< MsgType >(type_);
}
inline void MsgHead::set_type(MsgType value) {
  GOOGLE_DCHECK(MsgType_IsValid(value));
  set_has_type();
  type_ = value;
}

// required int32 msgSize = 2;
inline bool MsgHead::has_msgsize() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void MsgHead::set_has_msgsize() {
  _has_bits_[0] |= 0x00000002u;
}
inline void MsgHead::clear_has_msgsize() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void MsgHead::clear_msgsize() {
  msgsize_ = 0;
  clear_has_msgsize();
}
inline ::google::protobuf::int32 MsgHead::msgsize() const {
  return msgsize_;
}
inline void MsgHead::set_msgsize(::google::protobuf::int32 value) {
  set_has_msgsize();
  msgsize_ = value;
}

// required uint64 account = 3;
inline bool MsgHead::has_account() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void MsgHead::set_has_account() {
  _has_bits_[0] |= 0x00000004u;
}
inline void MsgHead::clear_has_account() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void MsgHead::clear_account() {
  account_ = GOOGLE_ULONGLONG(0);
  clear_has_account();
}
inline ::google::protobuf::uint64 MsgHead::account() const {
  return account_;
}
inline void MsgHead::set_account(::google::protobuf::uint64 value) {
  set_has_account();
  account_ = value;
}

// required bytes body = 4;
inline bool MsgHead::has_body() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void MsgHead::set_has_body() {
  _has_bits_[0] |= 0x00000008u;
}
inline void MsgHead::clear_has_body() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void MsgHead::clear_body() {
  if (body_ != &::google::protobuf::internal::kEmptyString) {
    body_->clear();
  }
  clear_has_body();
}
inline const ::std::string& MsgHead::body() const {
  return *body_;
}
inline void MsgHead::set_body(const ::std::string& value) {
  set_has_body();
  if (body_ == &::google::protobuf::internal::kEmptyString) {
    body_ = new ::std::string;
  }
  body_->assign(value);
}
inline void MsgHead::set_body(const char* value) {
  set_has_body();
  if (body_ == &::google::protobuf::internal::kEmptyString) {
    body_ = new ::std::string;
  }
  body_->assign(value);
}
inline void MsgHead::set_body(const void* value, size_t size) {
  set_has_body();
  if (body_ == &::google::protobuf::internal::kEmptyString) {
    body_ = new ::std::string;
  }
  body_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* MsgHead::mutable_body() {
  set_has_body();
  if (body_ == &::google::protobuf::internal::kEmptyString) {
    body_ = new ::std::string;
  }
  return body_;
}
inline ::std::string* MsgHead::release_body() {
  clear_has_body();
  if (body_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = body_;
    body_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {

template <>
inline const EnumDescriptor* GetEnumDescriptor< MsgType>() {
  return MsgType_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_MsgHead_2eproto__INCLUDED

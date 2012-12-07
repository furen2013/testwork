// Generated by the protocol buffer compiler.  DO NOT EDIT!

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "MsgHead.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* MsgHead_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  MsgHead_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* MsgType_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_MsgHead_2eproto() {
  protobuf_AddDesc_MsgHead_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "MsgHead.proto");
  GOOGLE_CHECK(file != NULL);
  MsgHead_descriptor_ = file->message_type(0);
  static const int MsgHead_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MsgHead, type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MsgHead, msgsize_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MsgHead, account_),
  };
  MsgHead_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      MsgHead_descriptor_,
      MsgHead::default_instance_,
      MsgHead_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MsgHead, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MsgHead, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(MsgHead));
  MsgType_descriptor_ = file->enum_type(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_MsgHead_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    MsgHead_descriptor_, &MsgHead::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_MsgHead_2eproto() {
  delete MsgHead::default_instance_;
  delete MsgHead_reflection_;
}

void protobuf_AddDesc_MsgHead_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\rMsgHead.proto\"C\n\007MsgHead\022\026\n\004Type\030\001 \002(\016"
    "2\010.MsgType\022\017\n\007msgSize\030\002 \002(\005\022\017\n\007account\030\003"
    " \002(\004*\271\003\n\007MsgType\022\022\n\016C2Gate_MsgNull\020\000\022\026\n\022"
    "C2Gate_MsgLoginReq\020\001\022\035\n\031C2Gate_MsgCreate"
    "AcountReq\020\002\022\031\n\025C2Gate_MsgLoginMacReq\020\003\022\031"
    "\n\025C2Gate_MsgBindMailReq\020\004\022\017\n\nC2Gate_END\020"
    "\346\007\022\016\n\tG2C_Begin\020\347\007\022\024\n\017G2C_LoginMacACK\020\350\007"
    "\022\027\n\022G2C_MsgG2CErrorACK\020\351\007\022\014\n\007G2C_End\020\320\017\022"
    "\022\n\rGate2LG_Begin\020\321\017\022\037\n\032Gate2LG_MsgGate2L"
    "GLoginReq\020\322\017\022\'\n\"Gate2LG_MsgGate2LGClient"
    "Disconnect\020\323\017\022\020\n\013Gate2LG_End\020\270\027\022\022\n\rLG2Ga"
    "te_Begin\020\271\027\022\037\n\032LG2Gate_MsgLG2GateLoginAC"
    "K\020\272\027\022\030\n\023LG2C_MsgBindMailACK\020\273\027\022\020\n\013LG2Gat"
    "e_End\020\240\037", 528);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "MsgHead.proto", &protobuf_RegisterTypes);
  MsgHead::default_instance_ = new MsgHead();
  MsgHead::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_MsgHead_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_MsgHead_2eproto {
  StaticDescriptorInitializer_MsgHead_2eproto() {
    protobuf_AddDesc_MsgHead_2eproto();
  }
} static_descriptor_initializer_MsgHead_2eproto_;

const ::google::protobuf::EnumDescriptor* MsgType_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MsgType_descriptor_;
}
bool MsgType_IsValid(int value) {
  switch(value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 998:
    case 999:
    case 1000:
    case 1001:
    case 2000:
    case 2001:
    case 2002:
    case 2003:
    case 3000:
    case 3001:
    case 3002:
    case 3003:
    case 4000:
      return true;
    default:
      return false;
  }
}


// ===================================================================

#ifndef _MSC_VER
const int MsgHead::kTypeFieldNumber;
const int MsgHead::kMsgSizeFieldNumber;
const int MsgHead::kAccountFieldNumber;
#endif  // !_MSC_VER

MsgHead::MsgHead()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void MsgHead::InitAsDefaultInstance() {
}

MsgHead::MsgHead(const MsgHead& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void MsgHead::SharedCtor() {
  _cached_size_ = 0;
  type_ = 0;
  msgsize_ = 0;
  account_ = GOOGLE_ULONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

MsgHead::~MsgHead() {
  SharedDtor();
}

void MsgHead::SharedDtor() {
  if (this != default_instance_) {
  }
}

void MsgHead::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MsgHead::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MsgHead_descriptor_;
}

const MsgHead& MsgHead::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MsgHead_2eproto();  return *default_instance_;
}

MsgHead* MsgHead::default_instance_ = NULL;

MsgHead* MsgHead::New() const {
  return new MsgHead;
}

void MsgHead::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    type_ = 0;
    msgsize_ = 0;
    account_ = GOOGLE_ULONGLONG(0);
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool MsgHead::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .MsgType Type = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (MsgType_IsValid(value)) {
            set_type(static_cast< MsgType >(value));
          } else {
            mutable_unknown_fields()->AddVarint(1, value);
          }
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_msgSize;
        break;
      }
      
      // required int32 msgSize = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_msgSize:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &msgsize_)));
          set_has_msgsize();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_account;
        break;
      }
      
      // required uint64 account = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_account:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &account_)));
          set_has_account();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }
      
      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void MsgHead::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required .MsgType Type = 1;
  if (has_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->type(), output);
  }
  
  // required int32 msgSize = 2;
  if (has_msgsize()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->msgsize(), output);
  }
  
  // required uint64 account = 3;
  if (has_account()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(3, this->account(), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* MsgHead::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required .MsgType Type = 1;
  if (has_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->type(), target);
  }
  
  // required int32 msgSize = 2;
  if (has_msgsize()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->msgsize(), target);
  }
  
  // required uint64 account = 3;
  if (has_account()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(3, this->account(), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int MsgHead::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .MsgType Type = 1;
    if (has_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->type());
    }
    
    // required int32 msgSize = 2;
    if (has_msgsize()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->msgsize());
    }
    
    // required uint64 account = 3;
    if (has_account()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->account());
    }
    
  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void MsgHead::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const MsgHead* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const MsgHead*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void MsgHead::MergeFrom(const MsgHead& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_type()) {
      set_type(from.type());
    }
    if (from.has_msgsize()) {
      set_msgsize(from.msgsize());
    }
    if (from.has_account()) {
      set_account(from.account());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void MsgHead::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MsgHead::CopyFrom(const MsgHead& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MsgHead::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000007) != 0x00000007) return false;
  
  return true;
}

void MsgHead::Swap(MsgHead* other) {
  if (other != this) {
    std::swap(type_, other->type_);
    std::swap(msgsize_, other->msgsize_);
    std::swap(account_, other->account_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata MsgHead::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = MsgHead_descriptor_;
  metadata.reflection = MsgHead_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)

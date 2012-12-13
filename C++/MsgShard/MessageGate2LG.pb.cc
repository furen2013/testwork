// Generated by the protocol buffer compiler.  DO NOT EDIT!

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "MessageGate2LG.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* MsgGate2LGLoginReq_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  MsgGate2LGLoginReq_reflection_ = NULL;
const ::google::protobuf::Descriptor* MsgGate2LGMailLoginReq_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  MsgGate2LGMailLoginReq_reflection_ = NULL;
const ::google::protobuf::Descriptor* MsgGate2LGClientDisconnect_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  MsgGate2LGClientDisconnect_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_MessageGate2LG_2eproto() {
  protobuf_AddDesc_MessageGate2LG_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "MessageGate2LG.proto");
  GOOGLE_CHECK(file != NULL);
  MsgGate2LGLoginReq_descriptor_ = file->message_type(0);
  static const int MsgGate2LGLoginReq_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MsgGate2LGLoginReq, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MsgGate2LGLoginReq, mac_),
  };
  MsgGate2LGLoginReq_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      MsgGate2LGLoginReq_descriptor_,
      MsgGate2LGLoginReq::default_instance_,
      MsgGate2LGLoginReq_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MsgGate2LGLoginReq, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MsgGate2LGLoginReq, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(MsgGate2LGLoginReq));
  MsgGate2LGMailLoginReq_descriptor_ = file->message_type(1);
  static const int MsgGate2LGMailLoginReq_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MsgGate2LGMailLoginReq, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MsgGate2LGMailLoginReq, mail_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MsgGate2LGMailLoginReq, password_),
  };
  MsgGate2LGMailLoginReq_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      MsgGate2LGMailLoginReq_descriptor_,
      MsgGate2LGMailLoginReq::default_instance_,
      MsgGate2LGMailLoginReq_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MsgGate2LGMailLoginReq, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MsgGate2LGMailLoginReq, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(MsgGate2LGMailLoginReq));
  MsgGate2LGClientDisconnect_descriptor_ = file->message_type(2);
  static const int MsgGate2LGClientDisconnect_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MsgGate2LGClientDisconnect, id_),
  };
  MsgGate2LGClientDisconnect_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      MsgGate2LGClientDisconnect_descriptor_,
      MsgGate2LGClientDisconnect::default_instance_,
      MsgGate2LGClientDisconnect_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MsgGate2LGClientDisconnect, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MsgGate2LGClientDisconnect, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(MsgGate2LGClientDisconnect));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_MessageGate2LG_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    MsgGate2LGLoginReq_descriptor_, &MsgGate2LGLoginReq::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    MsgGate2LGMailLoginReq_descriptor_, &MsgGate2LGMailLoginReq::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    MsgGate2LGClientDisconnect_descriptor_, &MsgGate2LGClientDisconnect::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_MessageGate2LG_2eproto() {
  delete MsgGate2LGLoginReq::default_instance_;
  delete MsgGate2LGLoginReq_reflection_;
  delete MsgGate2LGMailLoginReq::default_instance_;
  delete MsgGate2LGMailLoginReq_reflection_;
  delete MsgGate2LGClientDisconnect::default_instance_;
  delete MsgGate2LGClientDisconnect_reflection_;
}

void protobuf_AddDesc_MessageGate2LG_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::protobuf_AddDesc_MsgHead_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\024MessageGate2LG.proto\032\rMsgHead.proto\"-\n"
    "\022MsgGate2LGLoginReq\022\n\n\002id\030\001 \002(\004\022\013\n\003mac\030\002"
    " \002(\t\"D\n\026MsgGate2LGMailLoginReq\022\n\n\002id\030\001 \002"
    "(\004\022\014\n\004mail\030\002 \002(\t\022\020\n\010password\030\003 \002(\t\"(\n\032Ms"
    "gGate2LGClientDisconnect\022\n\n\002id\030\001 \002(\004", 196);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "MessageGate2LG.proto", &protobuf_RegisterTypes);
  MsgGate2LGLoginReq::default_instance_ = new MsgGate2LGLoginReq();
  MsgGate2LGMailLoginReq::default_instance_ = new MsgGate2LGMailLoginReq();
  MsgGate2LGClientDisconnect::default_instance_ = new MsgGate2LGClientDisconnect();
  MsgGate2LGLoginReq::default_instance_->InitAsDefaultInstance();
  MsgGate2LGMailLoginReq::default_instance_->InitAsDefaultInstance();
  MsgGate2LGClientDisconnect::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_MessageGate2LG_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_MessageGate2LG_2eproto {
  StaticDescriptorInitializer_MessageGate2LG_2eproto() {
    protobuf_AddDesc_MessageGate2LG_2eproto();
  }
} static_descriptor_initializer_MessageGate2LG_2eproto_;


// ===================================================================

#ifndef _MSC_VER
const int MsgGate2LGLoginReq::kIdFieldNumber;
const int MsgGate2LGLoginReq::kMacFieldNumber;
#endif  // !_MSC_VER

MsgGate2LGLoginReq::MsgGate2LGLoginReq()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void MsgGate2LGLoginReq::InitAsDefaultInstance() {
}

MsgGate2LGLoginReq::MsgGate2LGLoginReq(const MsgGate2LGLoginReq& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void MsgGate2LGLoginReq::SharedCtor() {
  _cached_size_ = 0;
  id_ = GOOGLE_ULONGLONG(0);
  mac_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

MsgGate2LGLoginReq::~MsgGate2LGLoginReq() {
  SharedDtor();
}

void MsgGate2LGLoginReq::SharedDtor() {
  if (mac_ != &::google::protobuf::internal::kEmptyString) {
    delete mac_;
  }
  if (this != default_instance_) {
  }
}

void MsgGate2LGLoginReq::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MsgGate2LGLoginReq::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MsgGate2LGLoginReq_descriptor_;
}

const MsgGate2LGLoginReq& MsgGate2LGLoginReq::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MessageGate2LG_2eproto();  return *default_instance_;
}

MsgGate2LGLoginReq* MsgGate2LGLoginReq::default_instance_ = NULL;

MsgGate2LGLoginReq* MsgGate2LGLoginReq::New() const {
  return new MsgGate2LGLoginReq;
}

void MsgGate2LGLoginReq::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    id_ = GOOGLE_ULONGLONG(0);
    if (has_mac()) {
      if (mac_ != &::google::protobuf::internal::kEmptyString) {
        mac_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool MsgGate2LGLoginReq::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint64 id = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_mac;
        break;
      }
      
      // required string mac = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_mac:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_mac()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->mac().data(), this->mac().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
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

void MsgGate2LGLoginReq::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required uint64 id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(1, this->id(), output);
  }
  
  // required string mac = 2;
  if (has_mac()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->mac().data(), this->mac().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->mac(), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* MsgGate2LGLoginReq::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required uint64 id = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(1, this->id(), target);
  }
  
  // required string mac = 2;
  if (has_mac()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->mac().data(), this->mac().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->mac(), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int MsgGate2LGLoginReq::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint64 id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->id());
    }
    
    // required string mac = 2;
    if (has_mac()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->mac());
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

void MsgGate2LGLoginReq::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const MsgGate2LGLoginReq* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const MsgGate2LGLoginReq*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void MsgGate2LGLoginReq::MergeFrom(const MsgGate2LGLoginReq& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_mac()) {
      set_mac(from.mac());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void MsgGate2LGLoginReq::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MsgGate2LGLoginReq::CopyFrom(const MsgGate2LGLoginReq& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MsgGate2LGLoginReq::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;
  
  return true;
}

void MsgGate2LGLoginReq::Swap(MsgGate2LGLoginReq* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(mac_, other->mac_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata MsgGate2LGLoginReq::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = MsgGate2LGLoginReq_descriptor_;
  metadata.reflection = MsgGate2LGLoginReq_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int MsgGate2LGMailLoginReq::kIdFieldNumber;
const int MsgGate2LGMailLoginReq::kMailFieldNumber;
const int MsgGate2LGMailLoginReq::kPasswordFieldNumber;
#endif  // !_MSC_VER

MsgGate2LGMailLoginReq::MsgGate2LGMailLoginReq()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void MsgGate2LGMailLoginReq::InitAsDefaultInstance() {
}

MsgGate2LGMailLoginReq::MsgGate2LGMailLoginReq(const MsgGate2LGMailLoginReq& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void MsgGate2LGMailLoginReq::SharedCtor() {
  _cached_size_ = 0;
  id_ = GOOGLE_ULONGLONG(0);
  mail_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  password_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

MsgGate2LGMailLoginReq::~MsgGate2LGMailLoginReq() {
  SharedDtor();
}

void MsgGate2LGMailLoginReq::SharedDtor() {
  if (mail_ != &::google::protobuf::internal::kEmptyString) {
    delete mail_;
  }
  if (password_ != &::google::protobuf::internal::kEmptyString) {
    delete password_;
  }
  if (this != default_instance_) {
  }
}

void MsgGate2LGMailLoginReq::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MsgGate2LGMailLoginReq::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MsgGate2LGMailLoginReq_descriptor_;
}

const MsgGate2LGMailLoginReq& MsgGate2LGMailLoginReq::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MessageGate2LG_2eproto();  return *default_instance_;
}

MsgGate2LGMailLoginReq* MsgGate2LGMailLoginReq::default_instance_ = NULL;

MsgGate2LGMailLoginReq* MsgGate2LGMailLoginReq::New() const {
  return new MsgGate2LGMailLoginReq;
}

void MsgGate2LGMailLoginReq::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    id_ = GOOGLE_ULONGLONG(0);
    if (has_mail()) {
      if (mail_ != &::google::protobuf::internal::kEmptyString) {
        mail_->clear();
      }
    }
    if (has_password()) {
      if (password_ != &::google::protobuf::internal::kEmptyString) {
        password_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool MsgGate2LGMailLoginReq::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint64 id = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_mail;
        break;
      }
      
      // required string mail = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_mail:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_mail()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->mail().data(), this->mail().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_password;
        break;
      }
      
      // required string password = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_password:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_password()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->password().data(), this->password().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
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

void MsgGate2LGMailLoginReq::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required uint64 id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(1, this->id(), output);
  }
  
  // required string mail = 2;
  if (has_mail()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->mail().data(), this->mail().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->mail(), output);
  }
  
  // required string password = 3;
  if (has_password()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->password().data(), this->password().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      3, this->password(), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* MsgGate2LGMailLoginReq::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required uint64 id = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(1, this->id(), target);
  }
  
  // required string mail = 2;
  if (has_mail()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->mail().data(), this->mail().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->mail(), target);
  }
  
  // required string password = 3;
  if (has_password()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->password().data(), this->password().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->password(), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int MsgGate2LGMailLoginReq::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint64 id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->id());
    }
    
    // required string mail = 2;
    if (has_mail()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->mail());
    }
    
    // required string password = 3;
    if (has_password()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->password());
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

void MsgGate2LGMailLoginReq::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const MsgGate2LGMailLoginReq* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const MsgGate2LGMailLoginReq*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void MsgGate2LGMailLoginReq::MergeFrom(const MsgGate2LGMailLoginReq& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_mail()) {
      set_mail(from.mail());
    }
    if (from.has_password()) {
      set_password(from.password());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void MsgGate2LGMailLoginReq::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MsgGate2LGMailLoginReq::CopyFrom(const MsgGate2LGMailLoginReq& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MsgGate2LGMailLoginReq::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000007) != 0x00000007) return false;
  
  return true;
}

void MsgGate2LGMailLoginReq::Swap(MsgGate2LGMailLoginReq* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(mail_, other->mail_);
    std::swap(password_, other->password_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata MsgGate2LGMailLoginReq::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = MsgGate2LGMailLoginReq_descriptor_;
  metadata.reflection = MsgGate2LGMailLoginReq_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int MsgGate2LGClientDisconnect::kIdFieldNumber;
#endif  // !_MSC_VER

MsgGate2LGClientDisconnect::MsgGate2LGClientDisconnect()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void MsgGate2LGClientDisconnect::InitAsDefaultInstance() {
}

MsgGate2LGClientDisconnect::MsgGate2LGClientDisconnect(const MsgGate2LGClientDisconnect& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void MsgGate2LGClientDisconnect::SharedCtor() {
  _cached_size_ = 0;
  id_ = GOOGLE_ULONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

MsgGate2LGClientDisconnect::~MsgGate2LGClientDisconnect() {
  SharedDtor();
}

void MsgGate2LGClientDisconnect::SharedDtor() {
  if (this != default_instance_) {
  }
}

void MsgGate2LGClientDisconnect::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MsgGate2LGClientDisconnect::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MsgGate2LGClientDisconnect_descriptor_;
}

const MsgGate2LGClientDisconnect& MsgGate2LGClientDisconnect::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MessageGate2LG_2eproto();  return *default_instance_;
}

MsgGate2LGClientDisconnect* MsgGate2LGClientDisconnect::default_instance_ = NULL;

MsgGate2LGClientDisconnect* MsgGate2LGClientDisconnect::New() const {
  return new MsgGate2LGClientDisconnect;
}

void MsgGate2LGClientDisconnect::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    id_ = GOOGLE_ULONGLONG(0);
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool MsgGate2LGClientDisconnect::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint64 id = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &id_)));
          set_has_id();
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

void MsgGate2LGClientDisconnect::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required uint64 id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(1, this->id(), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* MsgGate2LGClientDisconnect::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required uint64 id = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(1, this->id(), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int MsgGate2LGClientDisconnect::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint64 id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->id());
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

void MsgGate2LGClientDisconnect::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const MsgGate2LGClientDisconnect* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const MsgGate2LGClientDisconnect*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void MsgGate2LGClientDisconnect::MergeFrom(const MsgGate2LGClientDisconnect& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void MsgGate2LGClientDisconnect::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MsgGate2LGClientDisconnect::CopyFrom(const MsgGate2LGClientDisconnect& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MsgGate2LGClientDisconnect::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;
  
  return true;
}

void MsgGate2LGClientDisconnect::Swap(MsgGate2LGClientDisconnect* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata MsgGate2LGClientDisconnect::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = MsgGate2LGClientDisconnect_descriptor_;
  metadata.reflection = MsgGate2LGClientDisconnect_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)

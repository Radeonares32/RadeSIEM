// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: network.proto

#include "network.pb.h"

#include <algorithm>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
#include "google/protobuf/generated_message_tctable_impl.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;
namespace network {

inline constexpr Data::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : value_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR Data::Data(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct DataDefaultTypeInternal {
  PROTOBUF_CONSTEXPR DataDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~DataDefaultTypeInternal() {}
  union {
    Data _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 DataDefaultTypeInternal _Data_default_instance_;
}  // namespace network
static ::_pb::Metadata file_level_metadata_network_2eproto[1];
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_network_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_network_2eproto = nullptr;
const ::uint32_t TableStruct_network_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(
    protodesc_cold) = {
    ~0u,  // no _has_bits_
    PROTOBUF_FIELD_OFFSET(::network::Data, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    PROTOBUF_FIELD_OFFSET(::network::Data, _impl_.value_),
};

static const ::_pbi::MigrationSchema
    schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
        {0, -1, -1, sizeof(::network::Data)},
};

static const ::_pb::Message* const file_default_instances[] = {
    &::network::_Data_default_instance_._instance,
};
const char descriptor_table_protodef_network_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
    "\n\rnetwork.proto\022\007network\"\025\n\004Data\022\r\n\005valu"
    "e\030\001 \001(\t2A\n\016NetworkService\022/\n\013NetworkData"
    "\022\r.network.Data\032\r.network.Data(\0010\001b\006prot"
    "o3"
};
static ::absl::once_flag descriptor_table_network_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_network_2eproto = {
    false,
    false,
    122,
    descriptor_table_protodef_network_2eproto,
    "network.proto",
    &descriptor_table_network_2eproto_once,
    nullptr,
    0,
    1,
    schemas,
    file_default_instances,
    TableStruct_network_2eproto::offsets,
    file_level_metadata_network_2eproto,
    file_level_enum_descriptors_network_2eproto,
    file_level_service_descriptors_network_2eproto,
};

// This function exists to be marked as weak.
// It can significantly speed up compilation by breaking up LLVM's SCC
// in the .pb.cc translation units. Large translation units see a
// reduction of more than 35% of walltime for optimized builds. Without
// the weak attribute all the messages in the file, including all the
// vtables and everything they use become part of the same SCC through
// a cycle like:
// GetMetadata -> descriptor table -> default instances ->
//   vtables -> GetMetadata
// By adding a weak function here we break the connection from the
// individual vtables back into the descriptor table.
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_network_2eproto_getter() {
  return &descriptor_table_network_2eproto;
}
// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2
static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_network_2eproto(&descriptor_table_network_2eproto);
namespace network {
// ===================================================================

class Data::_Internal {
 public:
};

Data::Data(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:network.Data)
}
inline PROTOBUF_NDEBUG_INLINE Data::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from)
      : value_(arena, from.value_),
        _cached_size_{0} {}

Data::Data(
    ::google::protobuf::Arena* arena,
    const Data& from)
    : ::google::protobuf::Message(arena) {
  Data* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_);

  // @@protoc_insertion_point(copy_constructor:network.Data)
}
inline PROTOBUF_NDEBUG_INLINE Data::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : value_(arena),
        _cached_size_{0} {}

inline void Data::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
}
Data::~Data() {
  // @@protoc_insertion_point(destructor:network.Data)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void Data::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.value_.Destroy();
  _impl_.~Impl_();
}

PROTOBUF_NOINLINE void Data::Clear() {
// @@protoc_insertion_point(message_clear_start:network.Data)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.value_.ClearToEmpty();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* Data::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<0, 1, 0, 26, 2> Data::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    1, 0,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967294,  // skipmap
    offsetof(decltype(_table_), field_entries),
    1,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_Data_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
  }, {{
    // string value = 1;
    {::_pbi::TcParser::FastUS1,
     {10, 63, 0, PROTOBUF_FIELD_OFFSET(Data, _impl_.value_)}},
  }}, {{
    65535, 65535
  }}, {{
    // string value = 1;
    {PROTOBUF_FIELD_OFFSET(Data, _impl_.value_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
  }},
  // no aux_entries
  {{
    "\14\5\0\0\0\0\0\0"
    "network.Data"
    "value"
  }},
};

::uint8_t* Data::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:network.Data)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // string value = 1;
  if (!this->_internal_value().empty()) {
    const std::string& _s = this->_internal_value();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "network.Data.value");
    target = stream->WriteStringMaybeAliased(1, _s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:network.Data)
  return target;
}

::size_t Data::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:network.Data)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string value = 1;
  if (!this->_internal_value().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_value());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::google::protobuf::Message::ClassData Data::_class_data_ = {
    Data::MergeImpl,
    nullptr,  // OnDemandRegisterArenaDtor
};
const ::google::protobuf::Message::ClassData* Data::GetClassData() const {
  return &_class_data_;
}

void Data::MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg) {
  auto* const _this = static_cast<Data*>(&to_msg);
  auto& from = static_cast<const Data&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:network.Data)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_value().empty()) {
    _this->_internal_set_value(from._internal_value());
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void Data::CopyFrom(const Data& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:network.Data)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool Data::IsInitialized() const {
  return true;
}

::_pbi::CachedSize* Data::AccessCachedSize() const {
  return &_impl_._cached_size_;
}
void Data::InternalSwap(Data* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.value_, &other->_impl_.value_, arena);
}

::google::protobuf::Metadata Data::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_network_2eproto_getter, &descriptor_table_network_2eproto_once,
      file_level_metadata_network_2eproto[0]);
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace network
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
#include "google/protobuf/port_undef.inc"

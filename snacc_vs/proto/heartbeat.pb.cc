// proto/heartbeat.pb.cc

// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: heartbeat.proto
// Protobuf C++ Version: 5.29.1

#include "heartbeat.pb.h"

#include <algorithm>
#include <type_traits>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/generated_message_tctable_impl.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;
namespace heartbeat {

	inline constexpr HeartbeatRequest::Impl_::Impl_(
		::_pbi::ConstantInitialized) noexcept
		: worker_hostname_(
			&::google::protobuf::internal::fixed_address_empty_string,
			::_pbi::ConstantInitialized()),
		worker_id_{ 0 },
		cpu_usage_{ 0 },
		memory_usage_{ 0 },
		_cached_size_{ 0 } {}

	template <typename>
	PROTOBUF_CONSTEXPR HeartbeatRequest::HeartbeatRequest(::_pbi::ConstantInitialized)
#if defined(PROTOBUF_CUSTOM_VTABLE)
		: ::google::protobuf::Message(_class_data_.base()),
#else   // PROTOBUF_CUSTOM_VTABLE
		: ::google::protobuf::Message(),
#endif  // PROTOBUF_CUSTOM_VTABLE
		_impl_(::_pbi::ConstantInitialized()) {
	}
	struct HeartbeatRequestDefaultTypeInternal {
		PROTOBUF_CONSTEXPR HeartbeatRequestDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
		~HeartbeatRequestDefaultTypeInternal() {}
		union {
			HeartbeatRequest _instance;
		};
	};

	PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
		PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 HeartbeatRequestDefaultTypeInternal _HeartbeatRequest_default_instance_;

	inline constexpr HeartbeatReply::Impl_::Impl_(
		::_pbi::ConstantInitialized) noexcept
		: acknowledged_{ 0 },
		_cached_size_{ 0 } {}

	template <typename>
	PROTOBUF_CONSTEXPR HeartbeatReply::HeartbeatReply(::_pbi::ConstantInitialized)
#if defined(PROTOBUF_CUSTOM_VTABLE)
		: ::google::protobuf::Message(_class_data_.base()),
#else   // PROTOBUF_CUSTOM_VTABLE
		: ::google::protobuf::Message(),
#endif  // PROTOBUF_CUSTOM_VTABLE
		_impl_(::_pbi::ConstantInitialized()) {
	}
	struct HeartbeatReplyDefaultTypeInternal {
		PROTOBUF_CONSTEXPR HeartbeatReplyDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
		~HeartbeatReplyDefaultTypeInternal() {}
		union {
			HeartbeatReply _instance;
		};
	};

	PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
		PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 HeartbeatReplyDefaultTypeInternal _HeartbeatReply_default_instance_;
}  // namespace heartbeat
static constexpr const ::_pb::EnumDescriptor**
file_level_enum_descriptors_heartbeat_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
file_level_service_descriptors_heartbeat_2eproto = nullptr;
const ::uint32_t
TableStruct_heartbeat_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
	protodesc_cold) = {
	~0u,  // no _has_bits_
	PROTOBUF_FIELD_OFFSET(::heartbeat::HeartbeatRequest, _internal_metadata_),
	~0u,  // no _extensions_
	~0u,  // no _oneof_case_
	~0u,  // no _weak_field_map_
	~0u,  // no _inlined_string_donated_
	~0u,  // no _split_
	~0u,  // no sizeof(Split)
	PROTOBUF_FIELD_OFFSET(::heartbeat::HeartbeatRequest, _impl_.worker_hostname_),
	PROTOBUF_FIELD_OFFSET(::heartbeat::HeartbeatRequest, _impl_.worker_id_),
	PROTOBUF_FIELD_OFFSET(::heartbeat::HeartbeatRequest, _impl_.cpu_usage_),
	PROTOBUF_FIELD_OFFSET(::heartbeat::HeartbeatRequest, _impl_.memory_usage_),
	~0u,  // no _has_bits_
	PROTOBUF_FIELD_OFFSET(::heartbeat::HeartbeatReply, _internal_metadata_),
	~0u,  // no _extensions_
	~0u,  // no _oneof_case_
	~0u,  // no _weak_field_map_
	~0u,  // no _inlined_string_donated_
	~0u,  // no _split_
	~0u,  // no sizeof(Split)
	PROTOBUF_FIELD_OFFSET(::heartbeat::HeartbeatReply, _impl_.acknowledged_),
};

static const ::_pbi::MigrationSchema
schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
	{0, -1, -1, sizeof(::heartbeat::HeartbeatRequest)},
	{12, -1, -1, sizeof(::heartbeat::HeartbeatReply)},
};
static const ::_pb::Message* const file_default_instances[] = {
	&::heartbeat::_HeartbeatRequest_default_instance_._instance,
	&::heartbeat::_HeartbeatReply_default_instance_._instance,
};
const char descriptor_table_protodef_heartbeat_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
	protodesc_cold) = {
	"\n\017heartbeat.proto\022\theartbeat\"g\n\020Heartbea"
	"tRequest\022\027\n\017worker_hostname\030\001 \001(\t\022\021\n\twor"
	"ker_id\030\002 \001(\005\022\021\n\tcpu_usage\030\003 \001(\002\022\024\n\014memor"
	"y_usage\030\004 \001(\002\"&\n\016HeartbeatReply\022\024\n\014ackno"
	"wledged\030\001 \001(\0052[\n\020HeartbeatService\022G\n\rSen"
	"dHeartbeat\022\033.heartbeat.HeartbeatRequest\032"
	"\031.heartbeat.HeartbeatReplyb\006proto3"
};
static ::absl::once_flag descriptor_table_heartbeat_2eproto_once;
PROTOBUF_CONSTINIT const ::_pbi::DescriptorTable descriptor_table_heartbeat_2eproto = {
	false,
	false,
	274,
	descriptor_table_protodef_heartbeat_2eproto,
	"heartbeat.proto",
	&descriptor_table_heartbeat_2eproto_once,
	nullptr,
	0,
	2,
	schemas,
	file_default_instances,
	TableStruct_heartbeat_2eproto::offsets,
	file_level_enum_descriptors_heartbeat_2eproto,
	file_level_service_descriptors_heartbeat_2eproto,
};
namespace heartbeat {
	// ===================================================================

	class HeartbeatRequest::_Internal {
	public:
	};

	HeartbeatRequest::HeartbeatRequest(::google::protobuf::Arena* arena)
#if defined(PROTOBUF_CUSTOM_VTABLE)
		: ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
		: ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
		SharedCtor(arena);
		// @@protoc_insertion_point(arena_constructor:heartbeat.HeartbeatRequest)
	}
	inline PROTOBUF_NDEBUG_INLINE HeartbeatRequest::Impl_::Impl_(
		::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena * arena,
		const Impl_ & from, const ::heartbeat::HeartbeatRequest & from_msg)
		: worker_hostname_(arena, from.worker_hostname_),
		_cached_size_{ 0 } {}

	HeartbeatRequest::HeartbeatRequest(
		::google::protobuf::Arena * arena,
		const HeartbeatRequest & from)
#if defined(PROTOBUF_CUSTOM_VTABLE)
		: ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
		: ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
		HeartbeatRequest* const _this = this;
		(void)_this;
		_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
			from._internal_metadata_);
		new (&_impl_) Impl_(internal_visibility(), arena, from._impl_, from);
		::memcpy(reinterpret_cast<char*>(&_impl_) +
			offsetof(Impl_, worker_id_),
			reinterpret_cast<const char*>(&from._impl_) +
			offsetof(Impl_, worker_id_),
			offsetof(Impl_, memory_usage_) -
			offsetof(Impl_, worker_id_) +
			sizeof(Impl_::memory_usage_));

		// @@protoc_insertion_point(copy_constructor:heartbeat.HeartbeatRequest)
	}
	inline PROTOBUF_NDEBUG_INLINE HeartbeatRequest::Impl_::Impl_(
		::google::protobuf::internal::InternalVisibility visibility,
		::google::protobuf::Arena * arena)
		: worker_hostname_(arena),
		_cached_size_{ 0 } {}

	inline void HeartbeatRequest::SharedCtor(::_pb::Arena * arena) {
		new (&_impl_) Impl_(internal_visibility(), arena);
		::memset(reinterpret_cast<char*>(&_impl_) +
			offsetof(Impl_, worker_id_),
			0,
			offsetof(Impl_, memory_usage_) -
			offsetof(Impl_, worker_id_) +
			sizeof(Impl_::memory_usage_));
	}
	HeartbeatRequest::~HeartbeatRequest() {
		// @@protoc_insertion_point(destructor:heartbeat.HeartbeatRequest)
		SharedDtor(*this);
	}
	inline void HeartbeatRequest::SharedDtor(MessageLite & self) {
		HeartbeatRequest& this_ = static_cast<HeartbeatRequest&>(self);
		this_._internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
		ABSL_DCHECK(this_.GetArena() == nullptr);
		this_._impl_.worker_hostname_.Destroy();
		this_._impl_.~Impl_();
	}

	inline void* HeartbeatRequest::PlacementNew_(const void*, void* mem,
		::google::protobuf::Arena * arena) {
		return ::new (mem) HeartbeatRequest(arena);
	}
	constexpr auto HeartbeatRequest::InternalNewImpl_() {
		return ::google::protobuf::internal::MessageCreator::CopyInit(sizeof(HeartbeatRequest),
			alignof(HeartbeatRequest));
	}
	PROTOBUF_CONSTINIT
		PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
		const ::google::protobuf::internal::ClassDataFull HeartbeatRequest::_class_data_ = {
			::google::protobuf::internal::ClassData{
				&_HeartbeatRequest_default_instance_._instance,
				&_table_.header,
				nullptr,  // OnDemandRegisterArenaDtor
				nullptr,  // IsInitialized
				&HeartbeatRequest::MergeImpl,
				::google::protobuf::Message::GetNewImpl<HeartbeatRequest>(),
		#if defined(PROTOBUF_CUSTOM_VTABLE)
				&HeartbeatRequest::SharedDtor,
				::google::protobuf::Message::GetClearImpl<HeartbeatRequest>(), &HeartbeatRequest::ByteSizeLong,
					&HeartbeatRequest::_InternalSerialize,
		#endif  // PROTOBUF_CUSTOM_VTABLE
				PROTOBUF_FIELD_OFFSET(HeartbeatRequest, _impl_._cached_size_),
				false,
			},
			&HeartbeatRequest::kDescriptorMethods,
			&descriptor_table_heartbeat_2eproto,
			nullptr,  // tracker
	};
	const ::google::protobuf::internal::ClassData* HeartbeatRequest::GetClassData() const {
		::google::protobuf::internal::PrefetchToLocalCache(&_class_data_);
		::google::protobuf::internal::PrefetchToLocalCache(_class_data_.tc_table);
		return _class_data_.base();
	}
	PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
		const ::_pbi::TcParseTable<2, 4, 0, 50, 2> HeartbeatRequest::_table_ = {
		  {
			0,  // no _has_bits_
			0, // no _extensions_
			4, 24,  // max_field_number, fast_idx_mask
			offsetof(decltype(_table_), field_lookup_table),
			4294967280,  // skipmap
			offsetof(decltype(_table_), field_entries),
			4,  // num_field_entries
			0,  // num_aux_entries
			offsetof(decltype(_table_), field_names),  // no aux_entries
			_class_data_.base(),
			nullptr,  // post_loop_handler
			::_pbi::TcParser::GenericFallback,  // fallback
			#ifdef PROTOBUF_PREFETCH_PARSE_TABLE
			::_pbi::TcParser::GetTable<::heartbeat::HeartbeatRequest>(),  // to_prefetch
			#endif  // PROTOBUF_PREFETCH_PARSE_TABLE
		  }, {{
				  // float memory_usage = 4;
				  {::_pbi::TcParser::FastF32S1,
				   {37, 63, 0, PROTOBUF_FIELD_OFFSET(HeartbeatRequest, _impl_.memory_usage_)}},
				   // string worker_hostname = 1;
				   {::_pbi::TcParser::FastUS1,
					{10, 63, 0, PROTOBUF_FIELD_OFFSET(HeartbeatRequest, _impl_.worker_hostname_)}},
					// int32 worker_id = 2;
					{::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(HeartbeatRequest, _impl_.worker_id_), 63>(),
					 {16, 63, 0, PROTOBUF_FIELD_OFFSET(HeartbeatRequest, _impl_.worker_id_)}},
					 // float cpu_usage = 3;
					 {::_pbi::TcParser::FastF32S1,
					  {29, 63, 0, PROTOBUF_FIELD_OFFSET(HeartbeatRequest, _impl_.cpu_usage_)}},
				   }}, {{
					 65535, 65535
				   }}, {{
						   // string worker_hostname = 1;
						   {PROTOBUF_FIELD_OFFSET(HeartbeatRequest, _impl_.worker_hostname_), 0, 0,
						   (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
						   // int32 worker_id = 2;
						   {PROTOBUF_FIELD_OFFSET(HeartbeatRequest, _impl_.worker_id_), 0, 0,
						   (0 | ::_fl::kFcSingular | ::_fl::kInt32)},
						   // float cpu_usage = 3;
						   {PROTOBUF_FIELD_OFFSET(HeartbeatRequest, _impl_.cpu_usage_), 0, 0,
						   (0 | ::_fl::kFcSingular | ::_fl::kFloat)},
						   // float memory_usage = 4;
						   {PROTOBUF_FIELD_OFFSET(HeartbeatRequest, _impl_.memory_usage_), 0, 0,
						   (0 | ::_fl::kFcSingular | ::_fl::kFloat)},
						 }},
						 // no aux_entries
						 {{
						   "\32\17\0\0\0\0\0\0"
						   "heartbeat.HeartbeatRequest"
						   "worker_hostname"
						 }},
	};

	PROTOBUF_NOINLINE void HeartbeatRequest::Clear() {
		// @@protoc_insertion_point(message_clear_start:heartbeat.HeartbeatRequest)
		::google::protobuf::internal::TSanWrite(&_impl_);
		::uint32_t cached_has_bits = 0;
		// Prevent compiler warnings about cached_has_bits being unused
		(void)cached_has_bits;

		_impl_.worker_hostname_.ClearToEmpty();
		::memset(&_impl_.worker_id_, 0, static_cast<::size_t>(
			reinterpret_cast<char*>(&_impl_.memory_usage_) -
			reinterpret_cast<char*>(&_impl_.worker_id_)) + sizeof(_impl_.memory_usage_));
		_internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
	}

#if defined(PROTOBUF_CUSTOM_VTABLE)
	::uint8_t* HeartbeatRequest::_InternalSerialize(
		const MessageLite & base, ::uint8_t * target,
		::google::protobuf::io::EpsCopyOutputStream * stream) {
		const HeartbeatRequest& this_ = static_cast<const HeartbeatRequest&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
	::uint8_t* HeartbeatRequest::_InternalSerialize(
		::uint8_t * target,
		::google::protobuf::io::EpsCopyOutputStream * stream) const {
		const HeartbeatRequest& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
		// @@protoc_insertion_point(serialize_to_array_start:heartbeat.HeartbeatRequest)
		::uint32_t cached_has_bits = 0;
		(void)cached_has_bits;

		// string worker_hostname = 1;
		if (!this_._internal_worker_hostname().empty()) {
			const std::string& _s = this_._internal_worker_hostname();
			::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
				_s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "heartbeat.HeartbeatRequest.worker_hostname");
			target = stream->WriteStringMaybeAliased(1, _s, target);
		}

		// int32 worker_id = 2;
		if (this_._internal_worker_id() != 0) {
			target = ::google::protobuf::internal::WireFormatLite::
				WriteInt32ToArrayWithField<2>(
					stream, this_._internal_worker_id(), target);
		}

		// float cpu_usage = 3;
		if (::absl::bit_cast<::uint32_t>(this_._internal_cpu_usage()) != 0) {
			target = stream->EnsureSpace(target);
			target = ::_pbi::WireFormatLite::WriteFloatToArray(
				3, this_._internal_cpu_usage(), target);
		}

		// float memory_usage = 4;
		if (::absl::bit_cast<::uint32_t>(this_._internal_memory_usage()) != 0) {
			target = stream->EnsureSpace(target);
			target = ::_pbi::WireFormatLite::WriteFloatToArray(
				4, this_._internal_memory_usage(), target);
		}

		if (PROTOBUF_PREDICT_FALSE(this_._internal_metadata_.have_unknown_fields())) {
			target =
				::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
					this_._internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
		}
		// @@protoc_insertion_point(serialize_to_array_end:heartbeat.HeartbeatRequest)
		return target;
	}

#if defined(PROTOBUF_CUSTOM_VTABLE)
	::size_t HeartbeatRequest::ByteSizeLong(const MessageLite & base) {
		const HeartbeatRequest& this_ = static_cast<const HeartbeatRequest&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
	::size_t HeartbeatRequest::ByteSizeLong() const {
		const HeartbeatRequest& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
		// @@protoc_insertion_point(message_byte_size_start:heartbeat.HeartbeatRequest)
		::size_t total_size = 0;

		::uint32_t cached_has_bits = 0;
		// Prevent compiler warnings about cached_has_bits being unused
		(void)cached_has_bits;

		::_pbi::Prefetch5LinesFrom7Lines(&this_);
		{
			// string worker_hostname = 1;
			if (!this_._internal_worker_hostname().empty()) {
				total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
					this_._internal_worker_hostname());
			}
			// int32 worker_id = 2;
			if (this_._internal_worker_id() != 0) {
				total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
					this_._internal_worker_id());
			}
			// float cpu_usage = 3;
			if (::absl::bit_cast<::uint32_t>(this_._internal_cpu_usage()) != 0) {
				total_size += 5;
			}
			// float memory_usage = 4;
			if (::absl::bit_cast<::uint32_t>(this_._internal_memory_usage()) != 0) {
				total_size += 5;
			}
		}
		return this_.MaybeComputeUnknownFieldsSize(total_size,
			&this_._impl_._cached_size_);
	}

	void HeartbeatRequest::MergeImpl(::google::protobuf::MessageLite & to_msg, const ::google::protobuf::MessageLite & from_msg) {
		auto* const _this = static_cast<HeartbeatRequest*>(&to_msg);
		auto& from = static_cast<const HeartbeatRequest&>(from_msg);
		// @@protoc_insertion_point(class_specific_merge_from_start:heartbeat.HeartbeatRequest)
		ABSL_DCHECK_NE(&from, _this);
		::uint32_t cached_has_bits = 0;
		(void)cached_has_bits;

		if (!from._internal_worker_hostname().empty()) {
			_this->_internal_set_worker_hostname(from._internal_worker_hostname());
		}
		if (from._internal_worker_id() != 0) {
			_this->_impl_.worker_id_ = from._impl_.worker_id_;
		}
		if (::absl::bit_cast<::uint32_t>(from._internal_cpu_usage()) != 0) {
			_this->_impl_.cpu_usage_ = from._impl_.cpu_usage_;
		}
		if (::absl::bit_cast<::uint32_t>(from._internal_memory_usage()) != 0) {
			_this->_impl_.memory_usage_ = from._impl_.memory_usage_;
		}
		_this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
	}

	void HeartbeatRequest::CopyFrom(const HeartbeatRequest & from) {
		// @@protoc_insertion_point(class_specific_copy_from_start:heartbeat.HeartbeatRequest)
		if (&from == this) return;
		Clear();
		MergeFrom(from);
	}


	void HeartbeatRequest::InternalSwap(HeartbeatRequest * PROTOBUF_RESTRICT other) {
		using std::swap;
		auto* arena = GetArena();
		ABSL_DCHECK_EQ(arena, other->GetArena());
		_internal_metadata_.InternalSwap(&other->_internal_metadata_);
		::_pbi::ArenaStringPtr::InternalSwap(&_impl_.worker_hostname_, &other->_impl_.worker_hostname_, arena);
		::google::protobuf::internal::memswap<
			PROTOBUF_FIELD_OFFSET(HeartbeatRequest, _impl_.memory_usage_)
			+ sizeof(HeartbeatRequest::_impl_.memory_usage_)
			- PROTOBUF_FIELD_OFFSET(HeartbeatRequest, _impl_.worker_id_)>(
				reinterpret_cast<char*>(&_impl_.worker_id_),
				reinterpret_cast<char*>(&other->_impl_.worker_id_));
	}

	::google::protobuf::Metadata HeartbeatRequest::GetMetadata() const {
		return ::google::protobuf::Message::GetMetadataImpl(GetClassData()->full());
	}
	// ===================================================================

	class HeartbeatReply::_Internal {
	public:
	};

	HeartbeatReply::HeartbeatReply(::google::protobuf::Arena * arena)
#if defined(PROTOBUF_CUSTOM_VTABLE)
		: ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
		: ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
		SharedCtor(arena);
		// @@protoc_insertion_point(arena_constructor:heartbeat.HeartbeatReply)
	}
	HeartbeatReply::HeartbeatReply(
		::google::protobuf::Arena * arena, const HeartbeatReply & from)
		: HeartbeatReply(arena) {
		MergeFrom(from);
	}
	inline PROTOBUF_NDEBUG_INLINE HeartbeatReply::Impl_::Impl_(
		::google::protobuf::internal::InternalVisibility visibility,
		::google::protobuf::Arena * arena)
		: _cached_size_{ 0 } {}

	inline void HeartbeatReply::SharedCtor(::_pb::Arena * arena) {
		new (&_impl_) Impl_(internal_visibility(), arena);
		_impl_.acknowledged_ = {};
	}
	HeartbeatReply::~HeartbeatReply() {
		// @@protoc_insertion_point(destructor:heartbeat.HeartbeatReply)
		SharedDtor(*this);
	}
	inline void HeartbeatReply::SharedDtor(MessageLite & self) {
		HeartbeatReply& this_ = static_cast<HeartbeatReply&>(self);
		this_._internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
		ABSL_DCHECK(this_.GetArena() == nullptr);
		this_._impl_.~Impl_();
	}

	inline void* HeartbeatReply::PlacementNew_(const void*, void* mem,
		::google::protobuf::Arena * arena) {
		return ::new (mem) HeartbeatReply(arena);
	}
	constexpr auto HeartbeatReply::InternalNewImpl_() {
		return ::google::protobuf::internal::MessageCreator::ZeroInit(sizeof(HeartbeatReply),
			alignof(HeartbeatReply));
	}
	PROTOBUF_CONSTINIT
		PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
		const ::google::protobuf::internal::ClassDataFull HeartbeatReply::_class_data_ = {
			::google::protobuf::internal::ClassData{
				&_HeartbeatReply_default_instance_._instance,
				&_table_.header,
				nullptr,  // OnDemandRegisterArenaDtor
				nullptr,  // IsInitialized
				&HeartbeatReply::MergeImpl,
				::google::protobuf::Message::GetNewImpl<HeartbeatReply>(),
		#if defined(PROTOBUF_CUSTOM_VTABLE)
				&HeartbeatReply::SharedDtor,
				::google::protobuf::Message::GetClearImpl<HeartbeatReply>(), &HeartbeatReply::ByteSizeLong,
					&HeartbeatReply::_InternalSerialize,
		#endif  // PROTOBUF_CUSTOM_VTABLE
				PROTOBUF_FIELD_OFFSET(HeartbeatReply, _impl_._cached_size_),
				false,
			},
			&HeartbeatReply::kDescriptorMethods,
			&descriptor_table_heartbeat_2eproto,
			nullptr,  // tracker
	};
	const ::google::protobuf::internal::ClassData* HeartbeatReply::GetClassData() const {
		::google::protobuf::internal::PrefetchToLocalCache(&_class_data_);
		::google::protobuf::internal::PrefetchToLocalCache(_class_data_.tc_table);
		return _class_data_.base();
	}
	PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
		const ::_pbi::TcParseTable<0, 1, 0, 0, 2> HeartbeatReply::_table_ = {
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
			_class_data_.base(),
			nullptr,  // post_loop_handler
			::_pbi::TcParser::GenericFallback,  // fallback
			#ifdef PROTOBUF_PREFETCH_PARSE_TABLE
			::_pbi::TcParser::GetTable<::heartbeat::HeartbeatReply>(),  // to_prefetch
			#endif  // PROTOBUF_PREFETCH_PARSE_TABLE
		  }, {{
				  // int32 acknowledged = 1;
				  {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(HeartbeatReply, _impl_.acknowledged_), 63>(),
				   {8, 63, 0, PROTOBUF_FIELD_OFFSET(HeartbeatReply, _impl_.acknowledged_)}},
				}}, {{
				  65535, 65535
				}}, {{
						// int32 acknowledged = 1;
						{PROTOBUF_FIELD_OFFSET(HeartbeatReply, _impl_.acknowledged_), 0, 0,
						(0 | ::_fl::kFcSingular | ::_fl::kInt32)},
					  }},
					  // no aux_entries
					  {{
					  }},
	};

	PROTOBUF_NOINLINE void HeartbeatReply::Clear() {
		// @@protoc_insertion_point(message_clear_start:heartbeat.HeartbeatReply)
		::google::protobuf::internal::TSanWrite(&_impl_);
		::uint32_t cached_has_bits = 0;
		// Prevent compiler warnings about cached_has_bits being unused
		(void)cached_has_bits;

		_impl_.acknowledged_ = 0;
		_internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
	}

#if defined(PROTOBUF_CUSTOM_VTABLE)
	::uint8_t* HeartbeatReply::_InternalSerialize(
		const MessageLite & base, ::uint8_t * target,
		::google::protobuf::io::EpsCopyOutputStream * stream) {
		const HeartbeatReply& this_ = static_cast<const HeartbeatReply&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
	::uint8_t* HeartbeatReply::_InternalSerialize(
		::uint8_t * target,
		::google::protobuf::io::EpsCopyOutputStream * stream) const {
		const HeartbeatReply& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
		// @@protoc_insertion_point(serialize_to_array_start:heartbeat.HeartbeatReply)
		::uint32_t cached_has_bits = 0;
		(void)cached_has_bits;

		// int32 acknowledged = 1;
		if (this_._internal_acknowledged() != 0) {
			target = ::google::protobuf::internal::WireFormatLite::
				WriteInt32ToArrayWithField<1>(
					stream, this_._internal_acknowledged(), target);
		}

		if (PROTOBUF_PREDICT_FALSE(this_._internal_metadata_.have_unknown_fields())) {
			target =
				::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
					this_._internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
		}
		// @@protoc_insertion_point(serialize_to_array_end:heartbeat.HeartbeatReply)
		return target;
	}

#if defined(PROTOBUF_CUSTOM_VTABLE)
	::size_t HeartbeatReply::ByteSizeLong(const MessageLite & base) {
		const HeartbeatReply& this_ = static_cast<const HeartbeatReply&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
	::size_t HeartbeatReply::ByteSizeLong() const {
		const HeartbeatReply& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
		// @@protoc_insertion_point(message_byte_size_start:heartbeat.HeartbeatReply)
		::size_t total_size = 0;

		::uint32_t cached_has_bits = 0;
		// Prevent compiler warnings about cached_has_bits being unused
		(void)cached_has_bits;

		{
			// int32 acknowledged = 1;
			if (this_._internal_acknowledged() != 0) {
				total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
					this_._internal_acknowledged());
			}
		}
		return this_.MaybeComputeUnknownFieldsSize(total_size,
			&this_._impl_._cached_size_);
	}

	void HeartbeatReply::MergeImpl(::google::protobuf::MessageLite & to_msg, const ::google::protobuf::MessageLite & from_msg) {
		auto* const _this = static_cast<HeartbeatReply*>(&to_msg);
		auto& from = static_cast<const HeartbeatReply&>(from_msg);
		// @@protoc_insertion_point(class_specific_merge_from_start:heartbeat.HeartbeatReply)
		ABSL_DCHECK_NE(&from, _this);
		::uint32_t cached_has_bits = 0;
		(void)cached_has_bits;

		if (from._internal_acknowledged() != 0) {
			_this->_impl_.acknowledged_ = from._impl_.acknowledged_;
		}
		_this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
	}

	void HeartbeatReply::CopyFrom(const HeartbeatReply & from) {
		// @@protoc_insertion_point(class_specific_copy_from_start:heartbeat.HeartbeatReply)
		if (&from == this) return;
		Clear();
		MergeFrom(from);
	}


	void HeartbeatReply::InternalSwap(HeartbeatReply * PROTOBUF_RESTRICT other) {
		using std::swap;
		_internal_metadata_.InternalSwap(&other->_internal_metadata_);
		swap(_impl_.acknowledged_, other->_impl_.acknowledged_);
	}

	::google::protobuf::Metadata HeartbeatReply::GetMetadata() const {
		return ::google::protobuf::Message::GetMetadataImpl(GetClassData()->full());
	}
	// @@protoc_insertion_point(namespace_scope)
	}  // namespace heartbeat
namespace google {
	namespace protobuf {
	}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::std::false_type
_static_init2_ PROTOBUF_UNUSED =
(::_pbi::AddDescriptors(&descriptor_table_heartbeat_2eproto),
	::std::false_type{});
#include "google/protobuf/port_undef.inc"

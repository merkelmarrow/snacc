// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: student.proto
// Protobuf C++ Version: 5.29.1

#ifndef student_2eproto_2epb_2eh
#define student_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/runtime_version.h"
#if PROTOBUF_VERSION != 5029001
#error "Protobuf C++ gencode is built with an incompatible version of"
#error "Protobuf C++ headers/runtime. See"
#error "https://protobuf.dev/support/cross-version-runtime-guarantee/#cpp"
#endif
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/message_lite.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/unknown_field_set.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_student_2eproto

namespace google {
namespace protobuf {
namespace internal {
template <typename T>
::absl::string_view GetAnyMessageName();
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_student_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_student_2eproto;
class Student;
struct StudentDefaultTypeInternal;
extern StudentDefaultTypeInternal _Student_default_instance_;
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google


// ===================================================================


// -------------------------------------------------------------------

class Student final
    : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:Student) */ {
 public:
  inline Student() : Student(nullptr) {}
  ~Student() PROTOBUF_FINAL;

#if defined(PROTOBUF_CUSTOM_VTABLE)
  void operator delete(Student* msg, std::destroying_delete_t) {
    SharedDtor(*msg);
    ::google::protobuf::internal::SizedDelete(msg, sizeof(Student));
  }
#endif

  template <typename = void>
  explicit PROTOBUF_CONSTEXPR Student(
      ::google::protobuf::internal::ConstantInitialized);

  inline Student(const Student& from) : Student(nullptr, from) {}
  inline Student(Student&& from) noexcept
      : Student(nullptr, std::move(from)) {}
  inline Student& operator=(const Student& from) {
    CopyFrom(from);
    return *this;
  }
  inline Student& operator=(Student&& from) noexcept {
    if (this == &from) return *this;
    if (::google::protobuf::internal::CanMoveWithInternalSwap(GetArena(), from.GetArena())) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Student& default_instance() {
    return *internal_default_instance();
  }
  static inline const Student* internal_default_instance() {
    return reinterpret_cast<const Student*>(
        &_Student_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 0;
  friend void swap(Student& a, Student& b) { a.Swap(&b); }
  inline void Swap(Student* other) {
    if (other == this) return;
    if (::google::protobuf::internal::CanUseInternalSwap(GetArena(), other->GetArena())) {
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Student* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Student* New(::google::protobuf::Arena* arena = nullptr) const {
    return ::google::protobuf::Message::DefaultConstruct<Student>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const Student& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const Student& from) { Student::MergeImpl(*this, from); }

  private:
  static void MergeImpl(
      ::google::protobuf::MessageLite& to_msg,
      const ::google::protobuf::MessageLite& from_msg);

  public:
  bool IsInitialized() const {
    return true;
  }
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() PROTOBUF_FINAL;
  #if defined(PROTOBUF_CUSTOM_VTABLE)
  private:
  static ::size_t ByteSizeLong(const ::google::protobuf::MessageLite& msg);
  static ::uint8_t* _InternalSerialize(
      const MessageLite& msg, ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream);

  public:
  ::size_t ByteSizeLong() const { return ByteSizeLong(*this); }
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const {
    return _InternalSerialize(*this, target, stream);
  }
  #else   // PROTOBUF_CUSTOM_VTABLE
  ::size_t ByteSizeLong() const final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  #endif  // PROTOBUF_CUSTOM_VTABLE
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  static void SharedDtor(MessageLite& self);
  void InternalSwap(Student* other);
 private:
  template <typename T>
  friend ::absl::string_view(
      ::google::protobuf::internal::GetAnyMessageName)();
  static ::absl::string_view FullMessageName() { return "Student"; }

 protected:
  explicit Student(::google::protobuf::Arena* arena);
  Student(::google::protobuf::Arena* arena, const Student& from);
  Student(::google::protobuf::Arena* arena, Student&& from) noexcept
      : Student(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::internal::ClassData* GetClassData() const PROTOBUF_FINAL;
  static void* PlacementNew_(const void*, void* mem,
                             ::google::protobuf::Arena* arena);
  static constexpr auto InternalNewImpl_();
  static const ::google::protobuf::internal::ClassDataFull _class_data_;

 public:
  ::google::protobuf::Metadata GetMetadata() const;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kNameFieldNumber = 1,
    kAgeFieldNumber = 2,
    kGpaFieldNumber = 3,
  };
  // string name = 1;
  void clear_name() ;
  const std::string& name() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_name(Arg_&& arg, Args_... args);
  std::string* mutable_name();
  PROTOBUF_NODISCARD std::string* release_name();
  void set_allocated_name(std::string* value);

  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(
      const std::string& value);
  std::string* _internal_mutable_name();

  public:
  // int32 age = 2;
  void clear_age() ;
  ::int32_t age() const;
  void set_age(::int32_t value);

  private:
  ::int32_t _internal_age() const;
  void _internal_set_age(::int32_t value);

  public:
  // float gpa = 3;
  void clear_gpa() ;
  float gpa() const;
  void set_gpa(float value);

  private:
  float _internal_gpa() const;
  void _internal_set_gpa(float value);

  public:
  // @@protoc_insertion_point(class_scope:Student)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      2, 3, 0,
      20, 2>
      _table_;

  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from,
                          const Student& from_msg);
    ::google::protobuf::internal::ArenaStringPtr name_;
    ::int32_t age_;
    float gpa_;
    ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_student_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// Student

// string name = 1;
inline void Student::clear_name() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.name_.ClearToEmpty();
}
inline const std::string& Student::name() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:Student.name)
  return _internal_name();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void Student::set_name(Arg_&& arg,
                                                     Args_... args) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.name_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:Student.name)
}
inline std::string* Student::mutable_name() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:Student.name)
  return _s;
}
inline const std::string& Student::_internal_name() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.name_.Get();
}
inline void Student::_internal_set_name(const std::string& value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.name_.Set(value, GetArena());
}
inline std::string* Student::_internal_mutable_name() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  return _impl_.name_.Mutable( GetArena());
}
inline std::string* Student::release_name() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  // @@protoc_insertion_point(field_release:Student.name)
  return _impl_.name_.Release();
}
inline void Student::set_allocated_name(std::string* value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.name_.SetAllocated(value, GetArena());
  if (::google::protobuf::internal::DebugHardenForceCopyDefaultString() && _impl_.name_.IsDefault()) {
    _impl_.name_.Set("", GetArena());
  }
  // @@protoc_insertion_point(field_set_allocated:Student.name)
}

// int32 age = 2;
inline void Student::clear_age() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.age_ = 0;
}
inline ::int32_t Student::age() const {
  // @@protoc_insertion_point(field_get:Student.age)
  return _internal_age();
}
inline void Student::set_age(::int32_t value) {
  _internal_set_age(value);
  // @@protoc_insertion_point(field_set:Student.age)
}
inline ::int32_t Student::_internal_age() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.age_;
}
inline void Student::_internal_set_age(::int32_t value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.age_ = value;
}

// float gpa = 3;
inline void Student::clear_gpa() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.gpa_ = 0;
}
inline float Student::gpa() const {
  // @@protoc_insertion_point(field_get:Student.gpa)
  return _internal_gpa();
}
inline void Student::set_gpa(float value) {
  _internal_set_gpa(value);
  // @@protoc_insertion_point(field_set:Student.gpa)
}
inline float Student::_internal_gpa() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.gpa_;
}
inline void Student::_internal_set_gpa(float value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.gpa_ = value;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // student_2eproto_2epb_2eh

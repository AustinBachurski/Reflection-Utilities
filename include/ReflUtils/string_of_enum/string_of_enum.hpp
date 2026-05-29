#ifndef REFLECTION_UTILITIES_STRING_OF_ENUM_HPP
#define REFLECTION_UTILITIES_STRING_OF_ENUM_HPP

#include <concepts>
#include <meta>
#include <string_view>
#include <type_traits>

namespace ReflUtils {

template <typename ScopedEnum>
  requires std::is_scoped_enum_v<ScopedEnum>
constexpr std::string_view string_of_enum(ScopedEnum value) {
  static constexpr auto enum_values{
      std::define_static_array(std::meta::enumerators_of(^^ScopedEnum))};

  template for (constexpr auto enum_value : enum_values) {
    if ([:enum_value:] == value) {
      return std::meta::identifier_of(enum_value);
    }
  }

  return "UNMATCHED ENUM VALUE";
}

} // namespace ReflUtils

#endif

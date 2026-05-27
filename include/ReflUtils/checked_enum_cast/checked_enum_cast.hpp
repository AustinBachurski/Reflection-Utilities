#ifndef REFLECTION_UTILITIES_CHECKED_ENUM_CAST_HPP
#define REFLECTION_UTILITIES_CHECKED_ENUM_CAST_HPP

#include <concepts>
#include <format>
#include <meta>
#include <print>
#include <stdexcept>
#include <type_traits>
#include <utility>

namespace ReflUtils {

template <typename ScopedEnum, std::integral Integral>
  requires std::is_scoped_enum_v<ScopedEnum>
constexpr ScopedEnum checked_enum_cast(Integral value) {
  template for (constexpr auto enum_value : std::define_static_array(
                    std::meta::enumerators_of(^^ScopedEnum))) {
    if (std::cmp_equal(std::to_underlying([:enum_value:]), value)) {
      return [:enum_value:];
    }
  }

  if consteval {
    throw std::out_of_range("In call to 'checked_enum_cast<ENUM>(VALUE)' "
                            "-- VALUE is not a valid member of ENUM.");
  } else {
    throw std::out_of_range(std::format(
        "The numeric value '{}' is not a valid member of scoped enum '{}'.",
        value, std::meta::identifier_of(^^E)));
  }
}

} // namespace ReflUtils

#endif

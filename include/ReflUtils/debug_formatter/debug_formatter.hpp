#ifndef REFLECTION_UTILITIES_DEBUG_FORMATTER_HPP
#define REFLECTION_UTILITIES_DEBUG_FORMATTER_HPP

#include "ReflUtils/annotations/annotations.hpp"

#include <algorithm>
#include <format>
#include <meta>

namespace ReflUtils {

template <typename Annotation>
consteval auto is_annotated_with(std::meta::info reflected,
                                 Annotation annotation) -> bool {
  return std::ranges::contains(
      std::meta::annotations_of_with_type(reflected, ^^Annotation),
      std::meta::reflect_constant(annotation), std::meta::constant_of);
}

} // namespace ReflUtils

template <typename T>
  requires(ReflUtils::is_annotated_with(^^T, ReflUtils::debug_formatter))
struct std::formatter<T> {
  constexpr auto parse(std::format_parse_context &context) {
    return context.begin();
  }

  auto format(T const &object, std::format_context &context) const {
    auto out{std::format_to(context.out(), "{} {{\n",
                            std::meta::display_string_of(^^T))};

    static constexpr auto members{
        std::define_static_array(std::meta::nonstatic_data_members_of(
            ^^T, std::meta::access_context::unchecked()))};

    template for (constexpr auto member : members) {
      out = std::format_to(
          out, "  {} {}={}\n",
          std::meta::display_string_of(^^decltype(object.[:member:])),
          std::meta::identifier_of(member), object.[:member:]);
    }

    *out++ = "}";

    return out;
  }
};

#endif

#ifndef REFLECTION_UTILITIES_DEBUG_FORMATTER_HPP
#define REFLECTION_UTILITIES_DEBUG_FORMATTER_HPP

#include "ReflUtils/annotations/annotations.hpp"

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <meta>
#include <stdexcept>

namespace ReflUtils {

template <typename Annotation>
consteval auto is_annotated_with(std::meta::info reflected,
                                 Annotation annotation) -> bool {
  return std::ranges::contains(
      std::meta::annotations_of_with_type(reflected, ^^Annotation),
      std::meta::reflect_constant(annotation), std::meta::constant_of);
}

} // namespace ReflUtils

#endif

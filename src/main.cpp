#include "ReflUtils/annotations/annotations.hpp"
#include "ReflUtils/debug_formatter/debug_formatter.hpp"

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <meta>
#include <stdexcept>

struct[[= ReflUtils::debug_formatter]] Object {
  int x = 0;
  int y = 1;
};

auto main() -> int {
  Object thing;

  if (ReflUtils::is_annotated_with(^^decltype(thing),
                                   ReflUtils::debug_formatter)) {
    std::puts("Yep.");
  } else {
    std::puts("Nope...");
  }
}

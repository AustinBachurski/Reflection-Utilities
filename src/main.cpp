#include <print>
#include <string>
#include <string_view>
#include <vector>

#include "ReflUtils/annotations/annotations.hpp"
#include "ReflUtils/debug_formatter/debug_formatter.hpp"

struct[[= ReflUtils::debug_formatter]] Object {
  int x = 0;
  int y = 1;
  std::string stringy{"Be it a string?"};
  std::string_view thingy{"It do be a string!"};
  std::vector<double> vec{1.2, 3.4, 5.6, 7.8, 9.0};
};

auto main() -> int {
  Object thing;

  std::println("{}", thing);
}

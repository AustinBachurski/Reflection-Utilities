#include <print>
#include <unordered_map>

#include "ReflUtils/annotations/annotations.hpp"
#include "ReflUtils/debug_formatter/debug_formatter.hpp"

struct[[= ReflUtils::debug_formatter]] Object {
  std::unordered_map<float, std::size_t> map_member;
};

auto main() -> int {
  Object thing;
  std::println("{}", thing);
}

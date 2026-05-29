#include "ReflUtils/annotations/annotations.hpp"
#include "ReflUtils/checked_enum_cast/checked_enum_cast.hpp"
#include "ReflUtils/debug_formatter/debug_formatter.hpp"
#include "ReflUtils/string_of_enum/string_of_enum.hpp"

#include <print>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

struct[[= ReflUtils::debug_formatter]] Object {
  int meaning{42};
  float f{6.9F};
  std::string str{"Is that you?"};
  std::string_view view{"Huh?"};
  std::unordered_map<float, std::size_t> map;
  std::vector<double> vec;
};

enum class Values {
  Zero,
  One,
  Two,
  Three,
};

auto main() -> int {
  Object thing;
  std::println("{}", thing);

  constexpr auto three{ReflUtils::checked_enum_cast<Values>(0)};

  std::println("Enum: {}", ReflUtils::string_of_enum(three));

  try {
    [[maybe_unused]] auto five{ReflUtils::checked_enum_cast<Values>(5)};
    // std::println("Enum: {}", five);
  } catch (std::out_of_range &e) {
    std::println("Exception caught: {}", e.what());
  }
}

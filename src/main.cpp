#include "ReflUtils/annotations/annotations.hpp"
#include "ReflUtils/checked_enum_cast/checked_enum_cast.hpp"
#include "ReflUtils/debug_formatter/debug_formatter.hpp"
#include "ReflUtils/string_of_enum/string_of_enum.hpp"

#include <iostream>
#include <meta>
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

template <typename T>
  requires std::is_scoped_enum_v<T>
constexpr void print_enum_values() {
  static constexpr auto members{
      std::define_static_array(std::meta::enumerators_of(^^T))};

  std::println("Enum Class: {}", std::meta::display_string_of(^^T));

  template for (constexpr auto member : members) {
    std::println("  {}", std::meta::identifier_of(member));
  }
}

auto main() -> int {
  std::println("** Print an object annotated with `debug_formatter`. **");
  Object thing;
  std::println("{}", thing);

  std::println("\n** Print the values of an enum class. **");
  print_enum_values<Values>();

  std::println("\n** Cast a valid integer to the enum type. **");

  constexpr auto zero{ReflUtils::checked_enum_cast<Values>(0)};
  std::println("Enum: {}", ReflUtils::string_of_enum(zero));

  std::println("\n** Cast an invalid integer to an enum type. **");

  try {
    [[maybe_unused]] auto five{ReflUtils::checked_enum_cast<Values>(5)};
    // std::println("Enum: {}", five);
  } catch (std::out_of_range &e) {
    std::println("Exception caught: {}", e.what());
  }
}

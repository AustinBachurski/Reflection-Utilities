# Reflection Utilities
Learning C++26 reflection and trying to make some useful utilities.

!["A diseased rat missing his foot from a C++ footgun looks into the mirror of C++26 reflection, seeing the gentleman-rat he could be."](images/reflection.png)

## Examples

**Print an object annotated with `debug_formatter`.**

```console
Object {
  int meaning = 42
  float f = 6.9
  std::string {aka std::__cxx11::basic_string<char>} str = Is that you?
  std::string_view {aka std::basic_string_view<char>} view = Huh?
  std::unordered_map<float, long unsigned int> map = {}
  std::vector<double> vec = []
}
```

**Print the values of an enum class.**


```console
Enum Class: Values
  Zero
  One
  Two
  Three
```

**Cast a valid integer to the enum type.**

```console
Enum: Zero
```

**Cast an invalid integer to an enum type.**

```console
Exception caught: The numeric value '5' is not a valid member of scoped enum 'Values'.
```

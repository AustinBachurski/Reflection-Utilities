add_library(ReflUtils INTERFACE)

target_sources(ReflUtils INTERFACE
    FILE_SET HEADERS
    BASE_DIRS
    "${PROJECT_SOURCE_DIR}/include"

    FILES
    "${PROJECT_SOURCE_DIR}/include/ReflUtils/annotations/annotations.hpp"
    "${PROJECT_SOURCE_DIR}/include/ReflUtils/checked_enum_cast/checked_enum_cast.hpp"
    "${PROJECT_SOURCE_DIR}/include/ReflUtils/debug_formatter/debug_formatter.hpp"
    "${PROJECT_SOURCE_DIR}/include/ReflUtils/string_of_enum/string_of_enum.hpp"
)

add_executable(example)

target_sources(example PRIVATE
    main.cpp
)

target_link_libraries(example PRIVATE ReflUtils)

enable_warnings_for_target(example)

target_compile_options(example PRIVATE
    $<$<CONFIG:Debug>:-freflection -fsanitize=address,undefined>
    $<$<CONFIG:Release>:-freflection>
)

target_link_options(example PRIVATE
    $<$<CONFIG:Debug>:-fsanitize=address,undefined>
)

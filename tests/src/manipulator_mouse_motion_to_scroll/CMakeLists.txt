cmake_minimum_required (VERSION 3.9)

include (../../tests.cmake)

project (karabiner_test)

add_executable(
  karabiner_test
  src/counter_test.cpp
  src/errors_test.cpp
  src/options_test.cpp
  src/test.cpp
)

target_link_libraries(
  karabiner_test
  test_runner
)

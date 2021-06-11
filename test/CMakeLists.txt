cmake_minimum_required(VERSION 3.0)

set(This ExampleTests)

set(SOURCES
  ExampleTests.cpp
)

include_directories(../src/)
add_executable(${This} ${SOURCES})

target_link_libraries(${This} PUBLIC
  gtest_main
  Example
)

add_test(
  NAME ${This}
  COMMAND ${This}
)


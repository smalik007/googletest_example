cmake_minimum_required(VERSION 3.0)

SET(CMAKE_CXX_COMPILER "g++")

PROJECT(Example)

# set c++17 standard
if (CMAKE_VERSION VERSION_LESS "3.1")
  if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++17")
  endif ()
else ()
  set (CMAKE_CXX_STANDARD 17)
endif ()

# tells CMake to enable test
enable_testing()

set(GoogleTestLocation /home/suhail/Documents/Codes/googletest)

add_subdirectory(${GoogleTestLocation} build)

# add CFLAGS
add_definitions("-O3 -Wall -g -lstdc++ -Wl,-rpath -fpermissive -Wno-unused-variable -Wno-unused-function -Wno-unused-but-set-variable -std=c++17")

file(GLOB SOURCES "src/*.hpp" "src/*.cpp")

# link the codes of this project as static library
add_library(Example STATIC ${SOURCES})

add_subdirectory(test)

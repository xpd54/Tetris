cmake_minimum_required(VERSION 3.26)
project(Tetris)
set(CMAKE_CXX_STANDARD 17)
file(GLOB tetris_src
  "src/assets/Window/*.cpp"
  "src/assets/Tetromino/*.cpp"
  "src/assets/Attribute/*.cpp"
  "src/Game/*.cpp"
  "src/env/*.cpp"
  "src/util/*.cpp"
)

file(GLOB tetris_main
  "src/main.cpp"
)

add_executable(
  ${PROJECT_NAME}
  ${tetris_main}
)

include_directories(
  external/**/
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_BUILD_TYPE Release)
add_subdirectory(external/raylib)
set(BENCHMARK_ENABLE_GTEST_TESTS OFF)
add_subdirectory(benchmark/google_benchmark)
# Split main and other source into 2 and link again.
# where tetrislib should get used in testing.
add_library(tetris_src STATIC ${tetris_src})
target_link_libraries(tetris_src raylib benchmark::benchmark)

target_link_libraries(${PROJECT_NAME} 
  PRIVATE
  tetris_src
)

enable_testing()
add_subdirectory(tests)
cmake_minimum_required(VERSION 3.26)
project(Tetris)
set(CMAKE_CXX_STANDARD 17)
file(GLOB tetris_src
  "src/main.cpp"
  "src/assets/Window/*.cpp"
  "src/assets/Tetromino/*.cpp"
  "src/assets/Attribute/*.cpp"
  "src/Game/*.cpp"
  "src/env/*.cpp"
  "src/util/*.cpp"
)

add_executable(
  ${PROJECT_NAME}
  ${tetris_src}
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_BUILD_TYPE Release)
add_subdirectory(external/raylib)

target_link_libraries(${PROJECT_NAME} 
  PRIVATE
  raylib
)
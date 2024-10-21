cmake_minimum_required(VERSION 3.26)
project(Tetris)
set(CMAKE_CXX_STANDARD 17)
file(GLOB tetris_src
  "src/main.cpp"
  "src/assets/Window/*.cpp"
  # "src/assets/Tetromino/*.cpp"
  "src/assets/Attribute/*.cpp"
  "src/env/*.cpp"
)

add_executable(
  ${PROJECT_NAME}
  ${tetris_src}
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
    /usr/local/include/
)

target_link_directories(${PROJECT_NAME} 
  PUBLIC
  /usr/local/lib
)

target_link_libraries(${PROJECT_NAME} 
  PRIVATE
  raylib
)
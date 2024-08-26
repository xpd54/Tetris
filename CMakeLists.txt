cmake_minimum_required(VERSION 3.26)
project(Tetris)
set(CMAKE_CXX_STANDARD 17)
file(GLOB tetris_src
  "src/main.cpp"
  "src/accests/*.cpp"
  "src/env/*.cpp"
)

add_executable(
  ${PROJECT_NAME}
  ${tetris_src}
)
target_link_libraries(${PROJECT_NAME} 
  PRIVATE
  curses
)
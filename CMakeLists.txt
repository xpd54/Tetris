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

find_library( IOKIT_LIBRARY IOKit )
find_library( CORE_VIDEO_LIBRARY CoreVideo )
find_library( Cocoa_LIBRARY Cocoa )
find_library( GLUT_LIBRARY GLUT )
find_library( OpenGL_LIBRARY OpenGL )
target_include_directories(${PROJECT_NAME}
    PUBLIC
    include/
)

target_link_directories(${PROJECT_NAME} 
  PUBLIC
  lib/
)

target_link_libraries(${PROJECT_NAME} 
  PRIVATE
  ${IOKIT_LIBRARY}
  ${CORE_VIDEO_LIBRARY}
  ${Cocoa_LIBRARY}
  ${GLUT_LIBRARY}
  ${OpenGL_LIBRARY}
  raylib
)
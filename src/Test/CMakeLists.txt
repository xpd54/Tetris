cmake_minimum_required(VERSION 3.26)
project(TestRayLib)
set(CMAKE_CXX_STANDARD 17)
file(GLOB raylib_setup_src
  "ball/*.cpp"
  "*.cpp"
)

add_executable(
  ${PROJECT_NAME}
  ${raylib_setup_src}
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
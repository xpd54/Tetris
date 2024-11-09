project(Tetris_Test)

#Unit Test code
file(GLOB test_src
  "src/*.cpp"
)

include_directories(
  ../src/assets/Attribute/
  ../src/assets/Tetromino/
  ../src/assets/Window/
  ../src/Game/
  ../external/**/
)


add_executable(
  ${PROJECT_NAME}
  ${test_src}
)

add_subdirectory(googletest)

target_link_libraries(
  ${PROJECT_NAME}
  GTest::gtest_main
  tetris_src
)
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})



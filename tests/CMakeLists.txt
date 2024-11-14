
option(BUILD_TESTS OFF "Build tests")
option(BUILD_BENCHMARK OFF "Build benchmark")
#--------------benchmark start----------------
if(BUILD_BENCHMARK)
  file(GLOB benchmark_src
    "benchmark/performance/*cpp"
  )
  add_executable(Tetris_benchmark ${benchmark_src})

  set(BENCHMARK_ENABLE_GTEST_TESTS OFF)
  set(BENCHMARK_ENABLE_TESTING OFF)
  add_subdirectory(benchmark/google_benchmark)
  target_link_libraries(
    Tetris_benchmark
    tetris_src
    benchmark::benchmark
    benchmark::benchmark_main
  )
endif()
#---------------benchmark end-----------------

#Unit Test code
#--------------google test--------------------
if(BUILD_TESTS)
  project(Tetris_Test)
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
endif()


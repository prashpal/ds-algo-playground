cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  array_test
  src/array_test.cpp
)
target_include_directories(array_test PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(
  array_test
  GTest::gtest_main
)

# Add tree_test
add_executable(
  tree_test
  src/tree_test.cpp
)
target_include_directories(tree_test PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(
  tree_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(array_test)
gtest_discover_tests(tree_test)
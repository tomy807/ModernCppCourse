project(homework_6)
cmake_minimum_required(VERSION 3.7)
find_package(GTest REQUIRED)

include_directories(results/lib/)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/)
set(TEST_BINARY ${PROJECT_NAME}_test)

add_library(image ../io_tools/image.cpp)
add_executable(${TEST_BINARY}
               test_init.cpp
               test_histogram.cpp
               test_from_file.cpp
               test_resize.cpp)

target_link_libraries(${TEST_BINARY} image GTest::Main)
gtest_discover_tests(${TEST_BINARY} WORKING_DIRECTORY
                     ${CMAKE_CURRENT_SOURCE_DIR})

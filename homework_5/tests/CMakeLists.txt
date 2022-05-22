project(homework_5)
cmake_minimum_required(VERSION 3.7)

find_package(OpenCV 4 REQUIRED)
find_package(Catch2 REQUIRED)

include_directories(${OpenCV_INCLUDE_DIR})
include(CTest)
include(Catch)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/)
set(TEST_BINARY ${PROJECT_NAME}_test)

add_library(sifts_internal SHARED sifts_internal.cpp)
add_library(convert_dataset SHARED ../src/convert_dataset.cpp)
add_library(mat_serialization SHARED ../src/serialize.cpp)

target_link_libraries(sifts_internal ${OpenCV_LIBS})
target_link_libraries(mat_serialization ${OpenCV_LIBS})
target_link_libraries(convert_dataset ${OpenCV_LIBS})

add_executable(${TEST_BINARY}
               test_serialize.cpp
               test_convert_dataset.cpp
               test_main.cpp)

target_link_libraries(${TEST_BINARY}
                      convert_dataset
                      mat_serialization
                      sifts_internal
                      Catch2::Catch2 
                      stdc++fs)

catch_discover_tests(${TEST_BINARY} WORKING_DIRECTORY
                     ${CMAKE_CURRENT_SOURCE_DIR})

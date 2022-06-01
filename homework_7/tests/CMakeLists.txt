project(homework_7)
cmake_minimum_required(VERSION 3.7)

find_package(OpenCV 4 REQUIRED)
find_package(GTest REQUIRED)

include_directories(${OpenCV_INCLUDE_DIR})
include_directories(../include/)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/)

add_executable(test_kmeans test_kmeans.cpp test_data.cpp)
target_link_libraries(test_kmeans kmeans GTest::Main stdc++fs)
gtest_discover_tests(test_kmeans WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_library(kmeans SHARED ../src/kmeans.cpp)
add_library(serialization SHARED ../src/serialize.cpp)
add_library(bow_dictionary SHARED ../src/bowdictionary.cpp)
add_library(convert_dataset SHARED ../src/convert_dataset.cpp)


target_link_libraries(kmeans ${OpenCV_LIBS})
target_link_libraries(serialization ${OpenCV_LIBS})
target_link_libraries(bow_dictionary ${OpenCV_LIBS} kmeans)
target_link_libraries(convert_dataset ${OpenCV_LIBS} serialization)




add_executable(test_bow_dictionary test_bow_dictionary.cpp)
target_link_libraries(test_bow_dictionary
                      bow_dictionary
                      serialization
                      convert_dataset
                      GTest::Main
                      stdc++fs)
gtest_discover_tests(test_bow_dictionary WORKING_DIRECTORY
                     ${CMAKE_CURRENT_SOURCE_DIR})

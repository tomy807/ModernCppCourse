find_package(OpenCV 4 REQUIRED)
add_library(bow_dictionary STATIC bowdictionary.cpp kmeans.cpp)
target_include_directories(bow_dictionary PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(bow_dictionary ${OpenCV_LIBS})
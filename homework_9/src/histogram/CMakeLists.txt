find_package(OpenCV 4 REQUIRED)
add_library(histogram STATIC histogram.cpp)
target_include_directories(histogram PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(histogram ${OpenCV_LIBS})
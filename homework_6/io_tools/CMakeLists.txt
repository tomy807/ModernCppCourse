add_library(image STATIC image.cpp)
target_include_directories(image PUBLIC ${CMAKE_SOURCE_DIR}/include)


target_compile_features(image PRIVATE cxx_std_17)
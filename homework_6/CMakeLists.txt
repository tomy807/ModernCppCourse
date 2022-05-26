project(homework_6)
cmake_minimum_required(VERSION 3.7)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/results/lib)

add_library(image ../io_tools/image.cpp)


##cmake --version
##cmake version 3.16.3
cmake_minimum_required(VERSION 3.16)
project(homework_3)

set(CMAKE_CXX_STANDAD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS "-Wall")

include_directories(include/)

link_directories()

#실행파일 위치 설정
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_library(html_writer src/html_writer.cpp)
add_library(image_browser src/image_browser.cpp)
add_executable(main src/main.cpp)

target_link_libraries(main image_browser html_writer)

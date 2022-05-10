##cmake --version
##cmake version 3.16.3
cmake_minimum_required(VERSION 3.16)
project(homework_1)



# 설치 메크로(make install)시 설치 디렉토리
set(CMAKE_INSTALL_PREFIX install/)

#-std=c++17 
set(CMAKE_CXX_STANDAD 17)

# compile_commands.json 생성
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 컴파일 옵션
# -Wall: 모호한 코딩에 대한 경고
# -W: 합법적이지만 모호한 코딩에 대해서 경고를 보내는 옵션
# -E: 전처리 과정의 결과를 화면에 보이는 옵션 
set(CMAKE_CXX_FLAGS "-Wall")

#include 디렉토리 설정
include_directories(include/)
include_directories(include/ipb_arithmetic/)

link_directories()


# 라이브러리 위치 설정
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/results/lib)

#실행파일 위치 설정
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/results/bin)

# ar rcs build/libipb_arithmetic.a build/sum.o build/subtract.o
add_library(ipb_arithmetic src/subtract.cpp src/sum.cpp)
add_executable(example_output src/main.cpp)
target_link_libraries(example_output ipb_arithmetic)

install(TARGETS ipb_arithmetic DESTINATION ${PROJECT_SOURCE_DIR}/install/lib)
install(DIRECTORY include/ DESTINATION ${PROJECT_SOURCE_DIR}/install/include/)
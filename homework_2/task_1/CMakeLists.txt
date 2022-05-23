##cmake --version
##cmake version 3.16.3
cmake_minimum_required(VERSION 3.16)
project(homework_2)

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

link_directories()

#실행파일 위치 설정
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


# 실행파일 생성
add_executable(task_1 src/main.cpp)



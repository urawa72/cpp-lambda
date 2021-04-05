cmake_minimum_required(VERSION 3.8)
project(sns-sample)
set (CMAKE_CXX_STANDARD 17)

option(BUILD_SHARED_LIBS "Build shared libraries" ON)

find_package(AWSSDK REQUIRED COMPONENTS sns)

add_executable(sns_publish main.cpp)

target_link_libraries(sns_publish ${AWSSDK_LINK_LIBRARIES})

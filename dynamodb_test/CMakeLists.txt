cmake_minimum_required(VERSION 3.8)
project(dynamodb-examples)
set (CMAKE_CXX_STANDARD 17)

option(BUILD_SHARED_LIBS "Build shared libraries" ON)

find_package(AWSSDK REQUIRED COMPONENTS dynamodb)

add_executable(create_table create_table.cpp)

target_link_libraries(create_table ${AWSSDK_LINK_LIBRARIES})

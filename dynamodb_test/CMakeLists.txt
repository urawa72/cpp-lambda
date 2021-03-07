cmake_minimum_required(VERSION 3.2)
project(dynamodb-examples)
set (CMAKE_CXX_STANDARD 17)

find_package(AWSSDK REQUIRED COMPONENTS dynamodb)

set(EXAMPLES "")
list(APPEND EXAMPLES "create_table")

foreach(EXAMPLE IN LISTS EXAMPLES)
    add_executable(${EXAMPLE} ${EXAMPLE}.cpp)
    target_link_libraries(${EXAMPLE} ${AWSSDK_LINK_LIBRARIES})
endforeach()

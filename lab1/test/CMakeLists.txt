cmake_minimum_required(VERSION 3.22.1)

set(CMAKE_CXX_STANDART 20)

add_executable(test test.cpp)
target_link_libraries(test gtest gmock pthread)
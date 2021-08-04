cmake_minimum_required(VERSION 3.1)
project(RandomizedBenchmarking)
add_executable(${PROJECT_NAME} RandomizedBenchmarking.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})

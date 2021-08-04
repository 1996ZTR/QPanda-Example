cmake_minimum_required(VERSION 3.1)
project(CrossEntropyBenchmarking)
add_executable(${PROJECT_NAME} CrossEntropyBenchmarking.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})

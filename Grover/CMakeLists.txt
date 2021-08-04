cmake_minimum_required(VERSION 3.1)
project(Grover)
add_executable(${PROJECT_NAME} Grover.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})

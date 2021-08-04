cmake_minimum_required(VERSION 3.1)
project(QITE)
add_executable(${PROJECT_NAME} QITE.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})

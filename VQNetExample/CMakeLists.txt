cmake_minimum_required(VERSION 3.1)
project(VQNetExample)
add_executable(${PROJECT_NAME} VQNetExample.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})

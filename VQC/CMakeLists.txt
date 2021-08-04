cmake_minimum_required(VERSION 3.1)
project(VQC)
add_executable(${PROJECT_NAME} VQC.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})

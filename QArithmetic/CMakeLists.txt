cmake_minimum_required(VERSION 3.1)
project(QArithmetic)
add_executable(${PROJECT_NAME} QArithmetic.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})

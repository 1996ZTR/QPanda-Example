cmake_minimum_required(VERSION 3.1)
project(DrawQProg)
add_executable(${PROJECT_NAME} DrawQProg.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})

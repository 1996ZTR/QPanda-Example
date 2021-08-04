cmake_minimum_required(VERSION 3.1)
project(QPE)
add_executable(${PROJECT_NAME} QPE.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})

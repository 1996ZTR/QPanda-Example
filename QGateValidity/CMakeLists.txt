cmake_minimum_required(VERSION 3.1)
project(QGateValidity)
add_executable(${PROJECT_NAME} QGateValidity.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})

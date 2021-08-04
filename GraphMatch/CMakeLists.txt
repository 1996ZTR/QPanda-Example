cmake_minimum_required(VERSION 3.1)
project(GraphMatch)
add_executable(${PROJECT_NAME} GraphMatch.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})

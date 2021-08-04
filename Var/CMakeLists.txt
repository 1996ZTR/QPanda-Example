cmake_minimum_required(VERSION 3.1)
project(Var)
add_executable(${PROJECT_NAME} Var.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})

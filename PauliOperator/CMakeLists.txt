cmake_minimum_required(VERSION 3.1)
project(PauliOperator)
add_executable(${PROJECT_NAME} PauliOperator.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})

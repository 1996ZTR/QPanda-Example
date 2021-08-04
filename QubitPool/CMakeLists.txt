cmake_minimum_required(VERSION 3.1)
project(QubitPool)
add_executable(${PROJECT_NAME} QubitPool.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})

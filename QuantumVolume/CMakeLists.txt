cmake_minimum_required(VERSION 3.1)
project(QuantumVolume)
add_executable(${PROJECT_NAME} QuantumVolume.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})

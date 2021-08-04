cmake_minimum_required(VERSION 3.1)
project(QCircuitInfo)
add_executable(${PROJECT_NAME} QCircuitInfo.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})

cmake_minimum_required(VERSION 3.1)
project(QFT)
add_executable(${PROJECT_NAME} QFT.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})

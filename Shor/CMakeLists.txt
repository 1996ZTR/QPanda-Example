cmake_minimum_required(VERSION 3.1)
project(Shor)
add_executable(${PROJECT_NAME} Shor.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})

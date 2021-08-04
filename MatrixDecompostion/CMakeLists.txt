cmake_minimum_required(VERSION 3.1)
project(MatrixDecompostion)
add_executable(${PROJECT_NAME} MatrixDecompostion.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})

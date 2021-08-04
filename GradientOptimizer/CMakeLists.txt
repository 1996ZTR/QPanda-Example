cmake_minimum_required(VERSION 3.1)
project(GradientOptimizer)
add_executable(${PROJECT_NAME} GradientOptimizer.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})

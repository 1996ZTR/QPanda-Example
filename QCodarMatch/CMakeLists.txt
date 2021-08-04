cmake_minimum_required(VERSION 3.1)
project(QCodarMatch)
add_executable(${PROJECT_NAME} QCodarMatch.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})

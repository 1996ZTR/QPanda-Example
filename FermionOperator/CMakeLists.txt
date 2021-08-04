cmake_minimum_required(VERSION 3.1)
project(FermionOperator)
add_executable(${PROJECT_NAME} FermionOperator.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})

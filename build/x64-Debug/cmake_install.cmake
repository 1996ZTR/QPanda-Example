# Install script for directory: E:/QPanda2-example

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/QPanda2")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("E:/QPanda2-example/build/x64-Debug/GateTypeValidator/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/GetMatrix/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/Measure/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/OriginIRToQProg/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/PMeasure/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/QASMToQProg/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/QCircuit/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/QGate/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/QGateCompare/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/QGateCounter/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/QIf/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/QProg/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/QProgClockCycle/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/QProgDataParse/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/QProgStored/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/QProgToOriginIR/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/QProgToQASM/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/QProgToQuil/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/QWhile/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/QubitPool/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/QGateValidity/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/QCircuitInfo/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/DrawQProg/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/QuantumVolume/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/RandomizedBenchmarking/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/CrossEntropyBenchmarking/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/QCodarMatch/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/GraphMatch/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/FillQProgByI/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/MatrixDecompostion/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/PauliOperator/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/FermionOperator/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/Var/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/VQG/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/VQC/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/GradientOptimizer/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/VQNetExample/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/QFT/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/QPE/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/QArithmetic/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/Grover/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/Shor/cmake_install.cmake")
  include("E:/QPanda2-example/build/x64-Debug/QITE/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "E:/QPanda2-example/build/x64-Debug/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")

cmake_minimum_required(VERSION 2.6)
project(Neuron)
set(CMAKE_CXX_FLAGS "-g -Wall -Wextra -pedantic -std=c++11")
enable_testing()
add_subdirectory(gtest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

#add_executable(run main_Neuron.cpp Neuron.cpp)
#add_executable(runTest1 main_Test1.cpp Neuron.cpp)
add_executable(neuron_unittest gtests.cpp Neuron.cpp Network.cpp)
#add_executable(runTest2 main_Test2.cpp Neuron.cpp)
add_executable(NetworkTest Network_Test.cpp Network.cpp Neuron.cpp)
#add_executable(runTest vec.cpp vec_unittest.cpp)

target_link_libraries(neuron_unittest gtest gtest_main) 
add_test(neuron_unittest neuron_unittest)

#DOXYGEN
#add a target to generate API doc with Doxygen
#find_package(Doxygen)
#if(DOXYGEN_FOUND) 
#configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
#add_custom_target(doc $ {DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
#WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
#COMMENT "Generating API documentation with Doxygen" VERBATIM 
#) 
#endif(DOXYGEN_FOUND) 

###### Doxygen generation ######

# We first check if Doxygen is present.
find_package(Doxygen)
if(DOXYGEN_FOUND)

    # We then check if the Doxygen.in configuration file exists
    IF(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
        message(FATAL_ERROR "Doxygen configuration file is needed to build the documentation:
         - ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in not found.
         - Generate one in the project folder with doxygen -g Doxyfile.in")
    ENDIF(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)

    # We configure the doxyfile for make.
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
    add_custom_target(doc
        ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
ELSE(DOXYGEN_FOUND)
    message(FATAL_ERROR "Doxygen is needed to build the documentation.")
ENDIF(DOXYGEN_FOUND)

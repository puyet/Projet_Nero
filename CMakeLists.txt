cmake_minimum_required(VERSION 2.6)
project(Neuron)
set(CMAKE_CXX_FLAGS "-g -Wall -Wextra -pedantic -std=c++11")
enable_testing()
add_subdirectory(gtest)
include_directories($gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(run main_Neuron.cpp Neuron.cpp)
add_executable(runTest1 main_Test1.cpp Neuron.cpp)
add_executable(neuron_unittest gtests.cpp Neuron.cpp)
add_executable(runTest2 main_Test2.cpp Neuron.cpp)
add_executable(NetworkTest Network_Test.cpp Network.cpp Neuron.cpp)
#add_executable(runTest vec.cpp vec_unittest.cpp)

target_link_libraries(neuron_unittest gtest gtest_main) 
add_test(neuron_unittest neuron_unittest)



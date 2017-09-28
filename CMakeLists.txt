cmake_minimum_required(VERSION 3.0)

project(Mison)

set(CMAKE_CXX_COMPILE clang++)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-msse -ftest-coverage -fprofile-arcs")

include_directories(${CMAKE_SOURCE_DIR}/src/ ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/third/googletest/include/)
add_subdirectory(${CMAKE_SOURCE_DIR}/third/googletest/)

set(SOURCE_DIR src/type.h src/Bit.h src/Bit.cc)
add_library(Mison ${SOURCE_DIR})

#gtest
#enable_testing()
set(GTEST_FILES tests/test_Bit.cc tests/main-test.cc)
add_executable(main-test ${GTEST_FILES})
target_link_libraries(main-test gtest)# gtest_main)
target_link_libraries(main-test Mison)
#add_test(maintest main-test)
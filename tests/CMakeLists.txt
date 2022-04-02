cmake_minimum_required(VERSION 3.10)
project(testlib)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-fprofile-arcs -ftest-coverage -O0")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov" )

file(GLOB SOURCES *.cpp)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

message("TESTS HW2_INCLUDE_DIRS = ${HW2_INCLUDE_DIRS}")
message("HW2_LIBRARIES = ${HW2_LIBRARIES}")

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${HW2_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${HW2_LIBRARIES} GTest::Main)
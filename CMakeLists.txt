cmake_minimum_required(VERSION 3.10)
project(HW2)

set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-Wall -Wpedantic -Wextra -Werror")
set(CMAKE_C_CPPCHECK "cppcheck")
set(CMAKE_C_CLANG_TIDY "clang-tidy;-checks=*")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov" )

add_subdirectory(multiprocess)
add_subdirectory(singleprocess)

set(HW2_INCLUDE_DIRS ${MPR_LIB_INCLUDE_DIRS} ${SPR_LIB_INCLUDE_DIRS})
set(HW2_LIBRARIES ${MPR_LIB_LIBRARIES} ${SPR_LIB_LIBRARIES})

message("HW2_INCLUDE_DIRS = ${HW2_INCLUDE_DIRS}")
message("HW2_LIBRARIES = ${HW2_LIBRARIES}")

add_executable(${PROJECT_NAME} main.c)

target_include_directories(${PROJECT_NAME} PUBLIC ${MPR_LIB_INCLUDE_DIRS} ${SPR_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE multproc_lib sglproc_lib)

add_subdirectory(tests)

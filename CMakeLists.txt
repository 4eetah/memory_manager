project(Allocator)
cmake_minimum_required(VERSION 2.8)

set(HDR_DIR "./hdr")
include_directories(${HDR_DIR})
set(HDR_LIST
${HDR_DIR}/block.h
${HDR_DIR}/heap.h
${HDR_DIR}/mem_exception.h
${HDR_DIR}/memlib.h
${HDR_DIR}/mm.h
${HDR_DIR}/my_alloc.h
${HDR_DIR}/thread_safe_mm.h
)

set(SRC_DIR "./src")
include_directories(${SRC_DIR})
set(SRC_LIST
${SRC_DIR}/heap.cpp
${SRC_DIR}/mm.cpp
${SRC_DIR}/thread_safe_mm.cpp
${SRC_DIR}/main.cpp
)

set(TEST_DIR "./tests")
include_directories(${TEST_DIR})
set(TESTS
${TEST_DIR}/macro.h
${TEST_DIR}/test1.h
${TEST_DIR}/test2.h)

add_executable(${PROJECT_NAME} ${SRC_LIST} ${HDR_LIST} ${TESTS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -pthread -Wall -pg ")

set(TEST_DEPENDENCY
${SRC_DIR}/heap.cpp
${SRC_DIR}/mm.cpp
${SRC_DIR}/thread_safe_mm.cpp
)

find_package(CxxTest)
if(CXXTEST_FOUND)
    include_directories(${CXXTEST_INCLUDE_DIR})
    enable_testing()
    set(UNIT_TESTS_DIR ./tests)
    cxxtest_add_test(test1 test1.cpp ${TEST_DEPENDENCY} ${UNIT_TESTS_DIR}/test1.h)
    cxxtest_add_test(test2 test2.cpp ${TEST_DEPENDENCY} ${UNIT_TESTS_DIR}/test2.h)
endif()

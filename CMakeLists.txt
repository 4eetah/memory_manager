project(Allocator)
cmake_minimum_required(VERSION 2.8)

include_directories("./hdr/")
set(HDR_LIST
./hdr/block.h
./hdr/heap.h
./hdr/mem_exception.h
./hdr/memlib.h
./hdr/mm.h
./hdr/my_alloc.h
./hdr/thread_safe_mm.h
)
set(SRC_LIST
./src/heap.cpp
./src/mm.cpp
./src/thread_safe_mm.cpp
./src/test.cpp
)
add_executable(${PROJECT_NAME} ${SRC_LIST} ${HDR_LIST})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -pthread -Wall -pg ")

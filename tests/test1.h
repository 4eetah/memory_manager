#pragma once

#include <cxxtest/TestSuite.h>
#include <iostream>
#include "heap.h"

class TestHeap : public CxxTest::TestSuite
{
    static Heap h;
public:
    void test_mem_heapsize() {
        size_t heapSize = 10 *(1 << 20);
        Heap h(heapSize);
        TS_ASSERT_EQUALS(h.mem_heapsize(), heapSize);
    }

//    void test_mem_init() {  // request 2 ^ 64 bytes = 2 terabytes
//        TS_ASSERT_THROWS(h.mem_init((1 << 31)),
//                         std::bad_alloc);
//    }

    void test_searchFreeBlock() {

    }

};
Heap TestHeap::h;

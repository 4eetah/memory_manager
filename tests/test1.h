#pragma once

#include <cxxtest/TestSuite.h>
#include <iostream>
#include <limits>
#include "mem_exception.h"
#include "heap.h"

class TestHeap : public CxxTest::TestSuite
{
    Heap * ph;
public:

    void setUp() {
        ph = new Heap();
    }
    void tearDown() {
        delete ph;
    }

    void testConstruction() {
        Heap * ptr;
        TS_ASSERT_THROWS_NOTHING(ptr = new Heap());
        TS_ASSERT_DIFFERS(nullptr, ptr);
        // request for the big data
        size_t bigData = std::numeric_limits<size_t>::max();
        TS_ASSERT_THROWS(new Heap(bigData), std::bad_alloc);
        delete ptr;
    }

    void testCopyConstruction() {
        Heap * ptr = new Heap(*ph);
        TS_ASSERT_EQUALS(ptr->mem_heapsize(), ph->mem_heapsize());
        delete ptr;
    }

    void testMoveConstruction() {
        size_t oldSize = ph->mem_heapsize();
        void * lo = ph->mem_heap_lo();
        void * hi = ph->mem_heap_hi();
        Heap * ptr = new Heap(std::move(*ph));
        TS_ASSERT_EQUALS(ptr->mem_heapsize(), oldSize);
        TS_ASSERT(ptr->mem_heap_lo() == lo);
        TS_ASSERT(ptr->mem_heap_hi() == hi);
        TS_ASSERT_EQUALS(ph->mem_heapsize(), 0);
        TS_ASSERT(ph->mem_heap_lo() == nullptr);
        delete ptr;
    }

    void testMemSbrk() {
        TS_ASSERT_DIFFERS(nullptr, ph);
        size_t bigData = std::numeric_limits<size_t>::max();
        TS_ASSERT_THROWS(ph->mem_sbrk(bigData), mem_exception);
        TS_ASSERT_THROWS(ph->mem_sbrk(-1), mem_exception);
    }

    void test_mem_heapsize() {
        size_t heapSize = 10 *(1 << 20);
        Heap * ptr = new Heap(heapSize);
        TS_ASSERT_EQUALS(ptr->mem_heapsize(), heapSize);
        size_t diff = (char*)ptr->mem_heap_hi() - (char*)ptr->mem_heap_lo() + 1;
        TS_ASSERT_EQUALS(ptr->mem_heapsize(), diff);
        delete ptr;
    }

    void test_searchFreeBlock() {

    }

};

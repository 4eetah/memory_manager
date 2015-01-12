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

    void test_construction() {
        Heap * ptr;
        TS_ASSERT_THROWS_NOTHING(ptr = new Heap());
        TS_ASSERT_DIFFERS(nullptr, ptr);
        // request for the big data
        size_t bigData = std::numeric_limits<size_t>::max();
        TS_ASSERT_THROWS(new Heap(bigData), std::bad_alloc);
        delete ptr;
    }

    void test_copy_construction() {
        Heap heap(*ph);
        TS_ASSERT_EQUALS(heap.mem_heapsize(), heap.mem_heapsize());
    }

    void test_move_construction() {
        size_t oldSize = ph->mem_heapsize();
        void * lo = ph->mem_heap_lo();
        void * hi = ph->mem_heap_hi();
        Heap heap(std::move(*ph));
        TS_ASSERT_EQUALS(heap.mem_heapsize(), oldSize);
        TS_ASSERT(heap.mem_heap_lo() == lo);
        TS_ASSERT(heap.mem_heap_hi() == hi);
        TS_ASSERT_EQUALS(ph->mem_heapsize(), 0);
        TS_ASSERT(ph->mem_heap_lo() == nullptr);
    }

    void test_mem_sbrk() {
        size_t bigData = std::numeric_limits<size_t>::max();
        TS_ASSERT_THROWS(ph->mem_sbrk(bigData), mem_exception);
        TS_ASSERT_THROWS(ph->mem_sbrk(-1), mem_exception);
    }

    void test_mem_heapsize() {
        size_t heapSize = 10 *(1 << 20);
        Heap heap(heapSize);
        TS_ASSERT_EQUALS(heap.mem_heapsize(), heapSize);
        size_t diff = (char*)heap.mem_heap_hi() - (char*)heap.mem_heap_lo() + 1;
        TS_ASSERT_EQUALS(heap.mem_heapsize(), diff);
    }

    void test_searchFreeBlock() {

    }

};

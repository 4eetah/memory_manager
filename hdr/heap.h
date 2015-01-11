#pragma once

#include "block.h"

#define UNITTEST

/**
 * Heap data structure that uses explicit free list policy
 * to maintain list of free blocks available for allocation
 */
class Heap {
private:

//#ifdef UNITTEST
//    friend class TestHeap;
//#endif

	static const size_t MAX_HEAP = (20 * (1 << 20));  /* 20 MB */
    size_t heapSize;

	char *mem_start_brk;  /* start of the heap */
	char *mem_brk;        /* current heap area that is in use : [mem_start_brk, mem_brk ] */
	char *mem_max_addr;   /* max legal heap address */

	void mem_init(size_t);
    void mem_deinit();

public:
	Heap(size_t size = MAX_HEAP);	
    ~Heap();
	explicit Heap(const Heap &);
	Heap & operator = (const Heap &) = delete;
	Heap(Heap &&);
	Heap && operator = (Heap &&) = delete;

	// auxilliary functions for working with row heap memory
	void mem_reset_brk();
    void* mem_sbrk(size_t incr);
	size_t mem_heapsize() const;
	size_t mem_pagesize() const;
	void * mem_heap_lo() const;
	void * mem_heap_hi() const;
    BlockInfo* & head();

	// main functions for working with heap data structure
    void * searchFreeBlock(size_t reqSize);
    void insertFreeBlock(BlockInfo * freeBlock);
    void removeFreeBlock(BlockInfo * freeBlock);
    void coalesceFreeBlock(BlockInfo * oldBlock);
    void requestMoreSpace(size_t reqSize);
    void examineHeap();
	template<typename Function>
	void for_each(Function f);
};

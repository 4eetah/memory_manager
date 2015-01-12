#pragma once

#include "heap.h"
#include "mem_exception.h"

/**
 * @brief The MemoryManager is an abstraction to
 * manage the heap memory by means of allocation
 * a big chunk of memory and cut it into blocks.
 */
class MemoryManager
{
private:
    Heap h;

public:
    MemoryManager();
    virtual ~MemoryManager();
    MemoryManager(const MemoryManager&);
    MemoryManager& operator=(const MemoryManager&) = delete;
    MemoryManager(MemoryManager &&);
    MemoryManager& operator=(MemoryManager &&) = delete;

    //main functions
    void * allocate (size_t size);
    void deallocate (void *ptr);
    int checkHeap();
    void initialize ();     // initialize heap
    void reset();           // reset heap without memory deallocation
    size_t heapsize() const;
    size_t pagesize() const;
};

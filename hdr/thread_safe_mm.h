#pragma once

#include "mm.h"
#include <mutex>

/**
 * @brief The ThreadSafeMM class
 * is thread safe class but slow down the speed and
 * reduce benefits of memory management.
 * With used policy here we can only afford one
 * thread per time to have access to the heap
 * for writing but still several threads can read data
 * from heap simultaniously.
 */
class ThreadSafeMM : public MemoryManager {
private:
    std::mutex m;
public:
    ThreadSafeMM();
    ~ThreadSafeMM();
//    ThreadSafeMM(const ThreadSafeMM&) = delete;
    ThreadSafeMM& operator=(const ThreadSafeMM&) = delete;
//    ThreadSafeMM(ThreadSafeMM&&) = delete;
    ThreadSafeMM& operator=(ThreadSafeMM&&) = delete;

// main function
    void * allocate (size_t size);
    void deallocate (void *ptr);
    int checkHeap();
    size_t heapsize() const;
    size_t pagesize() const;
};

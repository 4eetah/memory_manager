#include "thread_safe_mm.h"
#include <iostream>
using namespace std;
ThreadSafeMM::ThreadSafeMM() {}

ThreadSafeMM::~ThreadSafeMM() {}

void * ThreadSafeMM::allocate (size_t size) {
    std::lock_guard<std::mutex> lock(m);
    return MemoryManager::allocate(size);
}

void ThreadSafeMM::deallocate (void *ptr) {
    std::lock_guard<std::mutex> lock(m);
    MemoryManager::deallocate(ptr);
}

int ThreadSafeMM::checkHeap() {
    return MemoryManager::checkHeap();
}

size_t ThreadSafeMM::heapsize() const {
    return MemoryManager::heapsize();
}

size_t ThreadSafeMM::pagesize() const {
    return MemoryManager::pagesize();
}

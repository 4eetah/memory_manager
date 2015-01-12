#pragma once

#include <iostream>
#include "mm.h"

/**
 * STL Allocator specification
 * with using custom allocator
 */
template<typename T>
class MyAlloc
{
public:
    static MemoryManager mm;
public:
    typedef T value_type;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;
public:
    template<typename U>
    struct rebind {
        typedef MyAlloc<U> other;
    };
public:
    MyAlloc() {}
    ~MyAlloc() {}
    MyAlloc(MyAlloc const &) {}
    template<typename U>
    MyAlloc(MyAlloc<U> const &) {}

    pointer address(reference r) { return &r; }
    const_pointer address(const_reference r) { return &r; }

    pointer allocate(size_type n, void* = 0) {
        return reinterpret_cast<pointer>(mm.allocate(n * sizeof(T)));
    }

    void deallocate(pointer p, size_type) {
        mm.deallocate(p);
    }

    size_type max_size() const {
        return mm.heapsize() / 2;
    }

    void construct(pointer p, const_reference t) {
        new(p)T(t);
    }

    void destroy(pointer p) {
        p->~T();
    }

    bool operator==(MyAlloc const &) { return true; }
    bool operator!=(MyAlloc const & a) { return !operator==(a); }
};

template<typename T> MemoryManager MyAlloc<T>::mm = MemoryManager();

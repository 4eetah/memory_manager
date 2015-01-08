#include "my_alloc.h"
#include "mm.h"
#include <iostream>



//template<typename T> MyAlloc<T>::MyAlloc() {};

//template<typename T> MyAlloc<T>::~MyAlloc() {};

//template<typename T> MyAlloc<T>::MyAlloc(MyAlloc const &) {};

//template<typename U> template<typename T>::ContainerAlloc(ContainerAlloc<U> const &) {};

/*
template<typename T> 
T* MyAlloc<T>::allocate(size_type n, void* = 0) { 
		cout << "allocate\n";
		return reinterpret_cast<T*>(::operator new(n * sizeof(T))); 
}

template<typename T>
void MyAlloc<T>::deallocate(T* p, size_type) {
		cout << "deallocate\n";
		::operator delete(p);
}
*/

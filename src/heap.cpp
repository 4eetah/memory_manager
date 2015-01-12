#include <iostream>
#include <string.h>
#include <unistd.h>
#include "mem_exception.h"
#include "heap.h"
#include "memlib.h"

Heap::Heap(size_t size) : heapSize(size) {
    try {
        mem_init(size);
    } catch (std::bad_alloc &) {
        mem_deinit();
        throw;
    }
}

Heap::~Heap() {
    mem_deinit();
}

Heap::Heap(const Heap & other) {
	heapSize = other.mem_heapsize();
	/* allocate the storage that will be used to model memory pool */
	try {
		mem_start_brk = new char[heapSize];
	}
    catch (std::bad_alloc &) {
		std::cerr << "mem_copy_constructor: alloc error\n";
        throw;
	}
	mem_max_addr = mem_start_brk + heapSize;
	mem_brk = mem_start_brk + (other.mem_brk - other.mem_start_brk);                  
	memcpy(mem_start_brk, other.mem_start_brk, heapSize);
}

Heap::Heap(Heap && other) {
	heapSize = other.mem_heapsize();
	other.heapSize = 0;
	mem_start_brk = other.mem_start_brk;
	other.mem_start_brk = nullptr;
	mem_brk = other.mem_brk;
	other.mem_brk = nullptr;
	mem_max_addr = other.mem_max_addr;
	other.mem_max_addr = nullptr;
}

/***********************************************************************
				Auxiliary functions
************************************************************************/

/*
* mem_init - initialize the memory system model
*/
void Heap::mem_init(size_t heapSize) {
	/* allocate the storage that will be used to model memory pool */
	try {
		mem_start_brk = new char[heapSize];
	}
    catch (std::bad_alloc &) {
		std::cerr << "mem_init_vm: alloc error\n";
        throw;
	}
	mem_max_addr = mem_start_brk + heapSize;
	mem_brk = mem_start_brk;                  /* heap is empty initially */
}

/*
* mem_deinit - free the storage used by the memory system model
*/
void Heap::mem_deinit() {
	delete[] mem_start_brk;
}

/*
* mem_reset_brk - reset the simulated brk pointer to make an empty heap
*/
void Heap::mem_reset_brk() {
	mem_brk = mem_start_brk;
}

/*
* mem_sbrk - simple model of the sbrk function. Extends the heap
*    by incr bytes and returns the start address of the new area. In
*    this model, the heap cannot be shrunk.
*/
void* Heap::mem_sbrk(size_t incr) {
	char *old_brk = mem_brk;
    size_t freeSpace = mem_max_addr - mem_brk;
    if ((incr < 0) || (incr > freeSpace)) {
		throw mem_exception("ERROR: mem_sbrk failed. Ran out of memory...\n");
	}
	mem_brk += incr;
	return old_brk;
}

/*
* mem_heapsize() - returns the heap size in bytes
*/
size_t Heap::mem_heapsize() const {
	return mem_max_addr - mem_start_brk;
}

/*
* mem_pagesize() - returns the page size of the system
*/
size_t Heap::mem_pagesize() const {
    return getpagesize();
}

/*
* mem_heap_lo() - returns first byte in the heap
*/
void * Heap::mem_heap_lo() const {
	return mem_start_brk;
}

/*
* mem_heap_hi() - returns last byte in the heap
*/
void * Heap::mem_heap_hi() const {
	return mem_max_addr - 1;
}

/* Pointer to the first BlockInfo in the free list, the list's head.
A pointer to the head of the free list in this implementation is
always stored in the first word in the heap.*/
BlockInfo* & Heap::head() {
    return *(reinterpret_cast<BlockInfo**>(mem_start_brk));
}

/***********************************************************************
			Main functions
************************************************************************/

/* Find a free block of the requested size in the free list.  Returns
nullptr if no free block is large enough. */
void * Heap::searchFreeBlock(size_t reqSize) {
    BlockInfo* freeBlock = head();
	while (freeBlock != nullptr){
		if (sizeOfBlock(freeBlock->sizeAndTags) >= reqSize) {
			return freeBlock;
		}
		else {
			freeBlock = freeBlock->next;
		}
	}
	return nullptr;
}

/* Insert freeBlock at the head of the list.  (LIFO) */
void Heap::insertFreeBlock(BlockInfo* freeBlock) {
    BlockInfo* oldHead = head();
	freeBlock->next = oldHead;
	if (oldHead != nullptr) {
		oldHead->prev = freeBlock;
	}
	freeBlock->prev = nullptr;
    head() = freeBlock;
}

/* Remove a free block from the free list. */
void Heap::removeFreeBlock(BlockInfo* freeBlock) {
	BlockInfo *nextFree, *prevFree;
	nextFree = freeBlock->next;
	prevFree = freeBlock->prev;
	if (nextFree != nullptr) {
		nextFree->prev = prevFree;
	}
    if (freeBlock == head()) {
        head() = nextFree;
	}
	else {
		prevFree->next = nextFree;
	}
}

/* Coalesce 'oldBlock' with any preceeding or following free blocks in memory.
This technic is used here to avoid fragmentation. */
void Heap::coalesceFreeBlock(BlockInfo* oldBlock) {
	BlockInfo *blockCursor;
	BlockInfo *newBlock;
	BlockInfo *freeBlock;
	// size of old block
	size_t oldSize = sizeOfBlock(oldBlock->sizeAndTags);
	// sum to be size of final coalesced block
	size_t newSize = oldSize;

	// Coalesce with any preceding free block
	blockCursor = oldBlock;
	while ((blockCursor->sizeAndTags & TAG_PRECEDING_USED) == 0) {
		// While the block preceding this one in memory (not the
		// prev. block in the free list) is free:

		// Get the size of the previous block from its boundary tag.
		size_t size = sizeOfBlock(*(reinterpret_cast<size_t*>(pointer_sub(blockCursor, WORD_SIZE))));
		// Use this size to find the block info for that block.
		freeBlock = reinterpret_cast<BlockInfo*>(pointer_sub(blockCursor, size));
		// Remove that block from free list.
		removeFreeBlock(freeBlock);

		// Count that block's size and update the current block pointer.
		newSize += size;
		blockCursor = freeBlock;
	}
	newBlock = blockCursor;

	// Coalesce with any following free block.
	// Start with the block following this one in memory
	blockCursor = reinterpret_cast<BlockInfo*>(pointer_add(oldBlock, oldSize));
	while ((blockCursor->sizeAndTags & TAG_USED) == 0) {
		// While the block is free:

		size_t size = sizeOfBlock(blockCursor->sizeAndTags);
		// Remove it from the free list.
		removeFreeBlock(blockCursor);
		// Count its size and step to the following block.
		newSize += size;
		blockCursor = reinterpret_cast<BlockInfo*>(pointer_add(blockCursor, size));
	}

	// If the block actually grew, remove the old entry from the free
	// list and add the new entry.
	if (newSize != oldSize) {
		// Remove the original block from the free list
		removeFreeBlock(oldBlock);

		// Save the new size in the block info and in the boundary tag
		// and tag it as used
		newBlock->sizeAndTags = newSize | TAG_PRECEDING_USED;
		// The boundary tag of the preceding block is the word immediately
		// preceding block in memory where we left off advancing blockCursor.
		*reinterpret_cast<size_t*>(pointer_sub(blockCursor, WORD_SIZE)) = newSize | TAG_PRECEDING_USED;

		// Put the new block in the free list.
		insertFreeBlock(newBlock);
	}
}

/* Get more heap space of size at least reqSize. */
void Heap::requestMoreSpace(size_t reqSize) {
	size_t pagesize = mem_pagesize();
	size_t numPages = (reqSize + pagesize - 1) / pagesize;
	BlockInfo *newBlock;
	size_t totalSize = numPages * pagesize;
	size_t prevLastWordMask;

	void* mem_sbrk_result = nullptr;
	try {
		mem_sbrk_result = mem_sbrk(totalSize);
	}
	catch (mem_exception & e) {
		throw;
	}

	newBlock = reinterpret_cast<BlockInfo*>(pointer_sub(mem_sbrk_result, WORD_SIZE));

	/* initialize header, inherit TAG_PRECEDING_USED status from the
	previously useless last word however, reset the fake TAG_USED
	bit */
	prevLastWordMask = newBlock->sizeAndTags & TAG_PRECEDING_USED;
	newBlock->sizeAndTags = totalSize | prevLastWordMask;
	// Initialize boundary tag.
	(reinterpret_cast<BlockInfo*>(pointer_add(newBlock, totalSize - WORD_SIZE)))->sizeAndTags =
		totalSize | prevLastWordMask;

	/* initialize "new" useless last word
	the previous block is free at this moment
	but this word is useless, so its use bit is set
	This trick let do the "normal" check even at the end of
	the heap and avoid a special check to see if the following
	block is the end of the heap... */
	*(reinterpret_cast<size_t*>(pointer_add(newBlock, totalSize))) = TAG_USED;

	// Add the new block to the free list and immediately coalesce newly
	// allocated memory space
	insertFreeBlock(newBlock);
	coalesceFreeBlock(newBlock);
}

void showBlock(BlockInfo * block) {
	/* print out common block attributes */
	std::cout << (void*)block << ": " <<
		sizeOfBlock(block->sizeAndTags) << " " <<
		(block->sizeAndTags & TAG_PRECEDING_USED) << " " <<
		(block->sizeAndTags & TAG_USED) << "\t";

	/* and allocated/free specific data */
	if (block->sizeAndTags & TAG_USED) {
		std::cout << "ALLOCATED\n";
	}
	else {
		std::cout << "FREE\t" << "next: " << (void*)block->next <<
			" prev: " << (void*)block->prev << std::endl;
	}
}

/* Print the heap by iterating through it as an implicit free list. */
void Heap::examineHeap() {
    std::cout << "\nFREE_LIST_HEAD: " << (void*)head() << std::endl;
	for_each(showBlock);
	std::cout << "END OF HEAP\n\n";
}

template<typename Function>
void Heap::for_each(Function f) {
	BlockInfo *block;
	for (block = reinterpret_cast<BlockInfo*>(pointer_add(mem_heap_lo(), WORD_SIZE)); /* first block on heap */
		sizeOfBlock(block->sizeAndTags) != 0 && block < mem_heap_hi();
		block = reinterpret_cast<BlockInfo*>(pointer_add(block, sizeOfBlock(block->sizeAndTags))))
	{
		f(block);
	}
}

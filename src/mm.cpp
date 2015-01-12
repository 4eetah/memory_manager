#include <iostream>
#include "memlib.h"
#include "mm.h"
#include "block.h"

using namespace std;

MemoryManager::MemoryManager() {
    initialize();
}

MemoryManager::MemoryManager(const MemoryManager & other)
: h(other.h)
{}

MemoryManager::MemoryManager(MemoryManager && other) 
: h(move(other.h))
{}

MemoryManager::~MemoryManager() {}

/* Initialize the allocator. */
void MemoryManager::initialize() {
    // Head of the free list.
    BlockInfo *firstFreeBlock;

    // Initial heap size: WORD_SIZE byte heap-header (stores pointer to head
    // of free list), MIN_BLOCK_SIZE bytes of space, WORD_SIZE byte heap-footer.
    size_t initSize = WORD_SIZE + MIN_BLOCK_SIZE + WORD_SIZE;
    size_t totalSize;

    try {
        h.mem_sbrk(initSize);
    } catch (mem_exception & e) {
        std::cerr << e.what();
        std::cerr << "ERROR: mem_sbrk failed in initialize()\n";
        exit(EXIT_FAILURE);
    }

    firstFreeBlock = reinterpret_cast<BlockInfo*>(pointer_add(h.mem_heap_lo(), WORD_SIZE));

    // Total usable size is full size minus heap-header and heap-footer words
    // NOTE: These are different than the "header" and "footer" of a block!
    // The heap-header is a pointer to the first free block in the free list.
    // The heap-footer is used to keep the data structures consistent (see
    // requestMoreSpace() for more info).
    totalSize = initSize - WORD_SIZE - WORD_SIZE;

    // The heap starts with one free block, which initialize now.
    firstFreeBlock->sizeAndTags = totalSize | TAG_PRECEDING_USED;
    firstFreeBlock->next = nullptr;
    firstFreeBlock->prev = nullptr;
    // boundary tag
    *(reinterpret_cast<size_t*>(pointer_add(firstFreeBlock, totalSize - WORD_SIZE))) =
            totalSize | TAG_PRECEDING_USED;

    // Tag "useless" word at end of heap as used.
    // This is the heap-footer.
    *(reinterpret_cast<size_t*>(pointer_sub(h.mem_heap_hi(), WORD_SIZE - 1))) = TAG_USED;

    // set the head of the free list to this new free block.
    h.head() = firstFreeBlock;
}

void MemoryManager::reset() {
    h.mem_reset_brk();
}

/**************************************************************************
Main user fuctions
***************************************************************************/

/* Allocate a block of size size and return a pointer to it. */
void* MemoryManager::allocate (size_t size) {
    size_t reqSize;
    BlockInfo * ptrFreeBlock = nullptr;
    size_t blockSize;
    size_t precedingBlockUseTag;

    // Zero-size requests get NULL.
    if (size == 0) {
        return nullptr;
    }    /* Pointer to the first BlockInfo in the free list, the list's head.
    A pointer to the head of the free list in this implementation is
    always stored in the first word in the heap.*/

    // Add one word for the initial size header.
    // Note that we don't need boundary tag when the block is used!
    size += WORD_SIZE;
    if (size <= MIN_BLOCK_SIZE) {
        // Make sure we allocate enough space for a blockInfo in case we
        // free this block (when we free this block, we'll need to use the
        // next pointer, the prev pointer, and the boundary tag).
        reqSize = MIN_BLOCK_SIZE;
    } else {
        // Round up for correct alignment
        reqSize = ALIGNMENT * ((size + ALIGNMENT - 1) / ALIGNMENT);
    }

    ptrFreeBlock = reinterpret_cast<BlockInfo*>(h.searchFreeBlock(reqSize));
    if (ptrFreeBlock == nullptr) {
        try {
            h.requestMoreSpace(reqSize);
        } catch (mem_exception & e) {
            throw;
        }
        ptrFreeBlock = reinterpret_cast<BlockInfo*>(h.searchFreeBlock(reqSize));
    }

    // remove this free block from free list
    h.removeFreeBlock(ptrFreeBlock);

    blockSize = sizeOfBlock(ptrFreeBlock->sizeAndTags);
    /* Pointer to the first BlockInfo in the free list, the list's head.
    A pointer to the head of the free list in this implementation is
    always stored in the first word in the heap.*/
    if((blockSize - reqSize) >= MIN_BLOCK_SIZE) {
        // extracting precedingBlockUseTag
        precedingBlockUseTag = ptrFreeBlock->sizeAndTags & TAG_PRECEDING_USED;
        ptrFreeBlock->sizeAndTags = reqSize | TAG_USED | precedingBlockUseTag;

        // set remainder header
        BlockInfo * remainder = reinterpret_cast<BlockInfo*>(pointer_add(ptrFreeBlock, reqSize));
        size_t remainderSize = blockSize - reqSize;
        remainder->sizeAndTags = remainderSize | TAG_PRECEDING_USED;
        // set remainder footer
        *(reinterpret_cast<size_t*>(pointer_add(remainder, remainderSize - WORD_SIZE))) =
                remainder->sizeAndTags;

        h.insertFreeBlock(remainder);
        h.coalesceFreeBlock(remainder);
    } else {
        ptrFreeBlock->sizeAndTags |= TAG_USED;
        // set TAG_PRECEDING_USED to header of following block
        BlockInfo * followingBlock =
                reinterpret_cast<BlockInfo*>(pointer_add(ptrFreeBlock, sizeOfBlock(ptrFreeBlock->sizeAndTags)));
        followingBlock->sizeAndTags |= TAG_PRECEDING_USED;
        // set footer of following block
        *(reinterpret_cast<size_t*>(pointer_add(followingBlock, sizeOfBlock(followingBlock->sizeAndTags) - WORD_SIZE))) =
                followingBlock->sizeAndTags;
    }
    // return useful payload of the block
    return pointer_add(ptrFreeBlock, WORD_SIZE);
}

/* Free the block referenced by ptr. */
void MemoryManager::deallocate(void *ptr) {
    if (ptr == nullptr)
        return;
    // size_t payloadSize;
    BlockInfo * blockInfo;
    BlockInfo * followingBlock;

    // extracting some staff
    blockInfo = reinterpret_cast<BlockInfo*>(pointer_sub(ptr, WORD_SIZE));
    // if block already have been deallocated then just return
    if ((blockInfo->sizeAndTags & TAG_USED) == 0) {
        return;
    }

    followingBlock = reinterpret_cast<BlockInfo*>(pointer_add(blockInfo, sizeOfBlock(blockInfo->sizeAndTags)));
    // mark TAG_PRECEDING_USED of the header of the following block as unused
    followingBlock->sizeAndTags &= ~TAG_PRECEDING_USED;
    // there is no needed to mark the boundary tag of the following block because it is used

    // mark just freed block as unused
    blockInfo->sizeAndTags &= ~TAG_USED;
    *(reinterpret_cast<size_t*>(pointer_sub(followingBlock, WORD_SIZE))) = blockInfo->sizeAndTags;

    h.insertFreeBlock(blockInfo);
    h.coalesceFreeBlock(blockInfo);
}

// Implement a heap checker.
int MemoryManager::checkHeap() {
    h.examineHeap();
    return 0;
}

size_t MemoryManager::heapsize() const {
    return h.mem_heapsize();
}

size_t MemoryManager::pagesize() const {
    return h.mem_pagesize();
}

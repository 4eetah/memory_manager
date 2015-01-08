#pragma once

#include <iostream>

/* A BlockInfo contains information about a block, including the size
and usage tags, as well as pointers to the next and previous blocks
in the free list.

The next and prev pointers and the boundary tag are only
needed when the block is free. To achieve better utilization, allocate
should use the space for next and prev as part of the space it returns.

+--------------+
| sizeAndTags  |  <-  BlockInfo pointers in free list point here
|  (header)    |
+--------------+
|     next     |  <-  Pointers returned by allocate point here
+--------------+
|     prev     |
+--------------+
|  space and   |
|   padding    |
|     ...      |
|     ...      |
+--------------+
| boundary tag |
|  (footer)    |
+--------------+
*/
struct BlockInfo {
	// Size of the block (in the high bits) and tags for whether the
	// block and its predecessor in memory are in use.
	size_t sizeAndTags;
	// Pointer to the next block in the free list.
	BlockInfo* next;
	// Pointer to the previous block in the free list.
	BlockInfo* prev;
};

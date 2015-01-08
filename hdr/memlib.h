#pragma once

#include "block.h"

/* Size of a word on this architecture. */
const size_t WORD_SIZE = sizeof(void*);

/* Minimum block size (to account for size header, next ptr, prev ptr,
   and boundary tag) */
const size_t MIN_BLOCK_SIZE = sizeof(BlockInfo) + WORD_SIZE;

/* Alignment of blocks returned by allocate. */
const size_t ALIGNMENT = 8;

/* TAG_USED is the bit mask used in sizeAndTags to mark a block as used. */
const size_t TAG_USED = 1;

/* TAG_PRECEDING_USED is the bit mask used in sizeAndTags to indicate
   that the block preceding it in memory is used. (used in turn for
   coalescing).  If the previous block is not used, we can get the size
   of the previous block from its boundary tag */
const size_t TAG_PRECEDING_USED = 2;

/* sizeOfBlock(blockInfo->sizeAndTags) extracts the size of a 'sizeAndTags' field.
   Also, calling size(size) selects just the higher bits of 'size'.

      sizeAndTags:
      +-------------------------------------------+
      | 63 | 62 | 61 | 60 |  . . . .  | 2 | 1 | 0 |
      +-------------------------------------------+
        ^                                       ^
      high bit                               low bit

   Since ALIGNMENT == 8, the low 3 bits of sizeAndTags are used for tag
   bits, and bits 3-63 to store the size.

   Bit 0 (2^0 == 1): TAG_USED
   Bit 1 (2^1 == 2): TAG_PRECEDING_USED
*/
inline size_t sizeOfBlock(size_t x) {
    return x & ~(ALIGNMENT - 1);
}

/* Pointer arithmetic to keep other code cleaner.  Casting
   to a char* has the effect that pointer arithmetic happens at the
   byte granularity (i.e. pointer_add(0x1, 1) would be 0x2).  (By
   default, incrementing a pointer in C++ has the effect of incrementing
   it by the size of the type to which it points (e.g. BlockInfo).) */
template<typename T>
inline void* pointer_add(T p, int x) {
    return reinterpret_cast<char*>(p) + x;
}
template<typename T>
inline void* pointer_sub(T p, int x) {
    return reinterpret_cast<char*>(p) - x;
}

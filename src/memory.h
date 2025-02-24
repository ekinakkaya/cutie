#ifndef cutie_memory_h
#define cutie_memory_h

#include "common.h"

/* grow the array by a factor of two, if necessary */
#define GROW_CAPACITY(capacity) \
    ((capacity) < 8 ? 8 : (capacity) * 2)

#define GROW_ARRAY(type, pointer, oldCount, newCount)      \
    (type *)reallocate(pointer, sizeof(type) * (oldCount), \
                       sizeof(type) * (newCount))

#define FREE_ARRAY(type, pointer, oldCount) \
    reallocate(pointer, sizeof(type) * (oldCount), 0)

/* this function can perform all allocation operations
   - Allocate new block.
   - Free allocation.
   - Shrink existing allocation.
   - Grow existing allocation.
*/
void *reallocate(void *pointer, size_t oldSize, size_t newSize);

#endif
//
// Created by sapo on 23/08/2023.
//

#include <stdio.h>
#include "stdlib.h"

#include "memory.h"

/*
 * Reallocates a pointer in memory based on the old and new sizes.
 *
 * Cases:
 *  newSize = 0 -> free memory
 *  oldSize = 0 & newSize != 0 -> allocate new block
 *  oldSize != 0 & newSize < oldSize -> Shrink existing allocation
 *  oldSize != 0 & newSize > oldSize -> Grow existing allocation
 */
void* reallocate(void* pointer, size_t oldSize, size_t newSize) {
    if (newSize == 0) {
        free(pointer);
        return NULL;
    }

    void* result = realloc(pointer, newSize);
    if (result == NULL) exit(1);

    return result;
}
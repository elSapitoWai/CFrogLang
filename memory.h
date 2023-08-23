//
// Created by sapo on 23/08/2023.
//

#ifndef CFROGLANG_MEMORY_H
#define CFROGLANG_MEMORY_H

#include "common.h"

/*
 * Calculates a new capacity based on a given current capacity
 */
#define GROW_CAPACITY(capacity) \
    ((capacity) < 8 ? 8 : (capacity * 2))

/*
 * Frees the memory on an array
 */
#define FREE_ARRAY(type, pointer, oldCount) \
    reallocate(pointer, sizeof(type) * (oldCount), 0)

/*
 * Reallocates the array into a new bigger size array
 */
#define GROW_ARRAY(type, pointer, oldCount, newCount) \
    (type*)reallocate(pointer, sizeof(type) * (oldCount), \
        sizeof(type) * (newCount))

void* reallocate(void* pointer, size_t oldSize, size_t newSize);


#endif //CFROGLANG_MEMORY_H

//
// Created by sapo on 24/08/2023.
//

#include "stdio.h"

#include "memory.h"
#include "value.h"

/*
 * Initializes a value array
 */
void initValueArray(ValueArray* array) {
    array->values = NULL;
    array->capacity = 0;
    array->count = 0;
}

/*
 * Writes a value into a value array
 */
void writeValueArray(ValueArray* array, Value value) {
    if (array->capacity < array->count + 1) {
        int oldCapacity = array->capacity;
        array->capacity = GROW_CAPACITY(oldCapacity);
        array->values = GROW_ARRAY(Value, array->values, oldCapacity, array->capacity);
    }

    array->values[array->count] = value;
    array->count++;
}

/*
 * Frees the memory allocated in a value array
 */
void freeValueArray(ValueArray* array) {
    FREE_ARRAY(Value, array, array->capacity);
    initValueArray(array);
}
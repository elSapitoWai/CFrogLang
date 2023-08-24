//
// Created by sapo on 24/08/2023.
//

#ifndef CFROGLANG_VALUE_H
#define CFROGLANG_VALUE_H

#include "common.h"

typedef double Value;

typedef struct {
    int capacity;
    int count;
    Value* values;
} ValueArray;

void initValueArray(ValueArray* array);
void writeValueArray(ValueArray* array, Value value);
void freeValueArray(ValueArray* array);
void printValue(Value value);

#endif //CFROGLANG_VALUE_H

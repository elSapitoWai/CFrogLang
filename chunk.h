//
// Created by pa2ga on 22/08/2023.
//

#ifndef CFROGLANG_CHUNK_H
#define CFROGLANG_CHUNK_H

#include "common.h"

typedef enum {
    OP_RETURN,
} OpCode;

typedef struct {
    int count;
    int capacity;
    uint8_t* code;
} Chunk;

#endif //CFROGLANG_CHUNK_H

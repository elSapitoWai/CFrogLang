//
// Created by sapo on 22/08/2023.
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

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte);

#endif //CFROGLANG_CHUNK_H

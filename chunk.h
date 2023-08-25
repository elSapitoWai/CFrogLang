//
// Created by sapo on 22/08/2023.
//

#ifndef CFROGLANG_CHUNK_H
#define CFROGLANG_CHUNK_H

#include "common.h"
#include "value.h"
#include "lines.h"

typedef enum {
    OP_CONSTANT,
    OP_RETURN,
} OpCode;

typedef struct {
    int count;
    int capacity;
    uint8_t* code;
    Lines lines;
    ValueArray constants;
} Chunk;

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte, int line);
int addConstant(Chunk* chunk, Value value);
int getLine(Chunk* chunk, int instructionIndex);

#endif //CFROGLANG_CHUNK_H

//
// Created by sapo on 23/08/2023.
//

#include "stdio.h"

#include "chunk.h"
#include "memory.h"

/*
 * Initializes a chunk.
 */
void initChunk(Chunk* chunk) {
    chunk->count = 0;
    chunk->capacity = 0;
    chunk->code = NULL;
    initLinesArray(&chunk->lines);
    initValueArray(&chunk->constants);
}

/*
 * Frees a chunk of code
 */
void freeChunk(Chunk* chunk) {
    FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
    freeLinesArray(&chunk->lines);
    freeValueArray(&chunk->constants);
    initChunk(chunk);
}

/*
 * Adds a byte to the chunk
 *
 * chunk: chunk to add the byte to
 * byte: byte to add to the chunk
 */
void writeChunk(Chunk* chunk, uint8_t byte, int line) {
    if (chunk->capacity < chunk->count + 1) {
        int oldCapacity = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(oldCapacity);
        chunk->code = GROW_ARRAY(uint8_t, chunk->code, oldCapacity, chunk->capacity);
    }

    chunk->code[chunk->count] = byte;
    chunk->count++;

    writeLines(&chunk->lines, line);
}

/*
 * Adds a constant to the chunk and returns the index where the constant was placed.
 */
int addConstant(Chunk* chunk, Value value) {
    writeValueArray(&chunk->constants, value);
    return chunk->constants.count - 1;
}

int getLine(Chunk* chunk, int instructionIndex) {
    printf("Get line called");
    int* encoded = chunk->lines.lines;
    int decoded[chunk->count];
    int count = 0;

    // Creates a decoded array
    for (int i = 0; i < chunk->lines.count; ++i) {
        // If 0 or even -> times
        if (i == 0 || i%2 == 0) {
            for (int j = 1; j < i; ++j) {
                decoded[count] = encoded[i+1];
                count++;
            }
        }
    }

    if (instructionIndex > count - 1) {
        printf("Instruction index is not valid");

        return 0;
    }

    return decoded[instructionIndex];
}
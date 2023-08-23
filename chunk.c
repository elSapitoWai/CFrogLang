//
// Created by sapo on 23/08/2023.
//

#include "stdlib.h"

#include "chunk.h"
#include "memory.h"

/*
 * Initializes a chunk.
 */
void initChunk(Chunk* chunk) {
    chunk->count = 0;
    chunk->capacity = 0;
    chunk->code = NULL;
}

/*
 * Frees a chunk of code
 */
void freeChunk(Chunk* chunk) {
    FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
    initChunk(chunk);
}

/*
 * Adds a byte to the chunk
 *
 * chunk: chunk to add the byte to
 * byte: byte to add to the chunk
 */
void writeChunk(Chunk* chunk, uint8_t byte) {
    if (chunk->capacity < chunk->count + 1) {
        int oldCapacity = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(oldCapacity);
        chunk->code = GROW_ARRAY(uint8_t, chunk->code, oldCapacity, chunk->capacity);
    }

    chunk->code[chunk->count] = byte;
    chunk->count++;
}
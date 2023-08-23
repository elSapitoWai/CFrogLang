//
// Created by sapo on 23/08/2023.
//

#ifndef CFROGLANG_DEBUG_H
#define CFROGLANG_DEBUG_H

#include "chunk.h"

void disassembleChunk(Chunk* chunk, const char* name);
int disassembleInstruction(Chunk* chunk, int offset);

#endif //CFROGLANG_DEBUG_H

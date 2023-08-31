//
// Created by sapo on 26/08/2023.
//

#ifndef CFROGLANG_VM_H
#define CFROGLANG_VM_H

#include "chunk.h"
#include "value.h"

#define STACK_MAX 256

typedef struct {
    Chunk* chunk;
    uint8_t* ip;
    Value stack[STACK_MAX];
    Value* stackTop;
} VM;

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
} InterpretResult;

void initVM();
void freeVM();

InterpretResult interpret(const char* source);

void push(Value value);
Value pop();

#endif //CFROGLANG_VM_H

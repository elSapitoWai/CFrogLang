//
// Created by sapo 03/12/23
//

#include "compiler.h"
#include "chunk.h"
#include "common.h"
#include "scanner.h"

#include <stdio.h>

bool compile(const char *source, Chunk* chunk) {
  initScanner(source);
  advance();
  expresion();
  consume(TOKEN_EOF, "Expect end of expression");
}

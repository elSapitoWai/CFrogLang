//
// Created by sapo on 25/08/2023.
//

#ifndef CFROGLANG_LINES_H
#define CFROGLANG_LINES_H

#include "common.h"

typedef struct {
    int count;
    int capacity;
    int* lines;
} Lines;

void initLinesArray(Lines* lines);
void freeLinesArray(Lines* lines);
void writeLines(Lines* lines, int line);

#endif //CFROGLANG_LINES_H

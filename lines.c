//
// Created by sapo on 25/08/2023.
//

#include "lines.h"
#include "memory.h"

/*
 * Initializes a lines array
 */
void initLinesArray(Lines* lines) {
    lines->count = 0;
    lines->capacity = 0;
    lines->lines = NULL;
}

/*
 * Frees the memory used by a lines array
 */
void freeLinesArray(Lines* lines) {
    FREE_ARRAY(int, lines, lines->capacity);
    initLinesArray(lines);
}

/*
 * Writes a new line into the array.
 */
void writeLines(Lines* lines, int line) {
    if (lines->capacity < lines->count + 1) {
        int oldCapacity = lines->capacity;
        lines->capacity = GROW_CAPACITY(oldCapacity);
        lines->lines = GROW_ARRAY(int, lines, oldCapacity, lines->capacity);
    }

    if (lines->lines == NULL) {
        lines->lines[lines->count] = 1;
        lines->lines[lines->count + 1] = line;
        lines->count += 2;
        return;
    }

    int oldLine = lines->lines[lines->count - 1];

    if (oldLine == line) {
        lines->lines[lines->count-2] += 1;
        return;
    }

    lines->lines[lines->count] = 1;
    lines->lines[lines->count + 1] = line;
}
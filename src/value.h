#ifndef cutie_value_h
#define cutie_value_h

#include "common.h"

/* double precision floating point numbers */
typedef double Value;

/* dynamic array for keeping constants (constant pool) */
typedef struct
{
    int capacity;
    int count;
    Value *values;
} ValueArray;

void initValueArray(ValueArray *array);
void writeValueArray(ValueArray *array, Value value);
void freeValueArray(ValueArray *array);

void printValue(Value value);

#endif
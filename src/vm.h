#ifndef cutie_vm_h
#define cutie_vm_h

#include "chunk.h"

typedef struct
{
    Chunk *chunk;

    /* ip points to the instruction that is about to be executed */
    uint8_t *ip;
} VM;

typedef enum
{
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
} InterpretResult;

void initVM();
void freeVM();
InterpretResult interpret(Chunk *chunk);

#endif
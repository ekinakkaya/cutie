#ifndef cutie_chunk_h
#define cutie_chunk_h

#include "common.h"
#include "value.h"

/* bytecode - one byte operation codes (opcode) */
typedef enum
{
    OP_CONSTANT,
    OP_RETURN,
} OpCode;

/* our dynamic Chunk array. */
typedef struct
{
    int count;
    int capacity;
    uint8_t *code;
    ValueArray constants;
} Chunk;

void initChunk(Chunk *chunk);
void writeChunk(Chunk *chunk, uint8_t byte);
void freeChunk(Chunk *chunk);

int addConstant(Chunk *chunk, Value value);

#endif
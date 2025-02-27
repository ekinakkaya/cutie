#ifndef cutie_chunk_h
#define cutie_chunk_h

#include "common.h"
#include "value.h"

/* bytecode - one byte operation codes (opcode) */
typedef enum
{
    OP_CONSTANT,
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,
    OP_NEGATE,
    OP_RETURN,
} OpCode;

/* our dynamic Chunk array. */
typedef struct
{
    int count;
    int capacity;
    uint8_t *code;
    ValueArray constants;

    int *lines;
} Chunk;

void initChunk(Chunk *chunk);
void writeChunk(Chunk *chunk, uint8_t byte, int line);
void freeChunk(Chunk *chunk);

int addConstant(Chunk *chunk, Value value);

#endif
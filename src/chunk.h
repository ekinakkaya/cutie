#ifndef cutie_chunk_h
#define cutie_chunk_h

#include "common.h"

/* bytecode - one byte operation codes (opcode) */
typedef enum
{
  OP_RETURN,
} OpCode;

/* our dynamic Chunk array. */
typedef struct
{
  int count;
  int capacity;
  uint8_t *code;
} Chunk;

void initChunk(Chunk *chunk);
void writeChunk(Chunk *chunk, uint8_t byte);
void freeChunk(Chunk *chunk);

#endif
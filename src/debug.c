#include <stdio.h>

#include "debug.h"
#include "value.h"

void disassembleChunk(Chunk *chunk, const char *name)
{
    printf("== %s ==\n", name);

    for (int offset = 0; offset < chunk->count;)
    {
        /* instructions can have different sizes, so we do it like this. */
        offset = disassembleInstruction(chunk, offset);
    }
}

static int constantInstruction(const char *name, Chunk *chunk,
                               int offset)
{
    /* offset is our opcode. offset + 1 is the index of the constant */
    uint8_t constant = chunk->code[offset + 1];
    printf("%-16s %4d '", name, constant);
    printValue(chunk->constants.values[constant]);
    printf("'\n");
    return offset + 2;
}

static int simpleInstruction(const char *name, int offset)
{
    printf("%s\n", name);
    return offset + 1; /* simple instructions are 1 byte */
}

int disassembleInstruction(Chunk *chunk, int offset)
{
    printf("%04d ", offset);

    /* our opcode */
    uint8_t instruction = chunk->code[offset];

    switch (instruction)
    {
    case OP_CONSTANT:
        return constantInstruction("OP_CONSTANT", chunk, offset);
    case OP_RETURN:
        return simpleInstruction("OP_RETURN", offset);
    default:
        printf("Unknown opcode %d\n", instruction);
        return offset + 1;
    }
}
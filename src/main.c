#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main(int argc, const char *argv[])
{
    initVM();

    Chunk chunk;
    initChunk(&chunk);

    int constant = addConstant(&chunk, 6.9); /* nice */

    writeChunk(&chunk, OP_CONSTANT, 1);
    writeChunk(&chunk, constant, 1);
    writeChunk(&chunk, OP_NEGATE, 2);
    writeChunk(&chunk, OP_RETURN, 3);

    // disassembleChunk(&chunk, "test chunk");

    interpret(&chunk);

    freeChunk(&chunk);

    freeVM();
    return 0;
}
#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main(int argc, const char *argv[])
{
    initVM();

    Chunk chunk;
    initChunk(&chunk);

    /* define a constant 6.9*/
    int constant = addConstant(&chunk, 6.9); /* nice */
    writeChunk(&chunk, OP_CONSTANT, 1);
    writeChunk(&chunk, constant, 1);

    /* define another constant 3.4 */
    constant = addConstant(&chunk, 3.4);
    writeChunk(&chunk, OP_CONSTANT, 2);
    writeChunk(&chunk, constant, 2);

    /* add those 2 numbers and push onto the stack */
    writeChunk(&chunk, OP_ADD, 2);

    /* define another constant 5.6 */
    constant = addConstant(&chunk, 5.6);
    writeChunk(&chunk, OP_CONSTANT, 3);
    writeChunk(&chunk, constant, 3);

    /* divide the first value on the stack to the second one (6.9 + 3.4) / 5.6 */
    writeChunk(&chunk, OP_DIVIDE, 4);

    /* make the number negative */
    writeChunk(&chunk, OP_NEGATE, 5);
    writeChunk(&chunk, OP_RETURN, 5);

    // disassembleChunk(&chunk, "test chunk");

    interpret(&chunk);

    freeChunk(&chunk);

    freeVM();
    return 0;
}
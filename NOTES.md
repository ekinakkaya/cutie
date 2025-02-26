# interpreter

Basic structure:
```
compiler -> bytecode -> virtual machine
```

- Chunk: sequences of bytecode.

- if there is not enough space for reallocation, realloc() copies the bytes to a new block, frees the old block, and returns the new block.

- Disassembler: ours will take the macchine code and spit out some textual list.

- JVM associates a _constant pool_ with each compiled class.

- Where to store constants in a chunk? Many instruction sets store the value directly in the code stream right after the opcode. These are called immediate instructions. The bits for the value are immediately after the opcode.

- Immediate instructions do not work well for large or variable sized constants like strings. They are usually stored in a seperate _constant data_ region of the binary executable. And the instruction has a pointer to that region.

- Line information is only used when a runtime error occurs. So we do not want it between the instructions.

- We essentially have 3 main things going on here.
  - Bytes of code
  - Constant values
  - Line information for debugging.
# interpreter

Basic structure:
```
compiler -> bytecode -> virtual machine
```

- Chunk: sequences of bytecode.

- if there is not enough space for reallocation, realloc() copies the bytes to a new block, frees the old block, and returns the new block.
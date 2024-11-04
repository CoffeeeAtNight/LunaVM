#include "memory.h"
#include <stdint.h>
#include <string.h>

uint8_t v_memory[256]; // 256 bytes memory

void initialize_memory() 
{
  memset(&v_memory, 0, sizeof(v_memory));
}

uint8_t fetch_next_opcode()
{
  // TODO WHY NO PC IN HERE?
  return 0;
}

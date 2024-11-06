#include "../include/memory.h"
#include <stdint.h>
#include <string.h>

uint8_t v_memory[256];

void initialize_memory() 
{
  memset(v_memory, 0, sizeof(v_memory));
}


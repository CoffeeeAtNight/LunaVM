#include <stdint.h>
#include <string.h>
#include "../include/cpu.h"
#include "../include/memory.h"

uint8_t registers[4];
uint8_t program_counter = 0;

void execute_instruction(uint8_t opcode) 
{
  switch (opcode) 
  {
    case 0x01: // MOV
      break;
    case 0x02: // ADD 
      break;
    case 0x03: // JMP 
      break;
    case 0x04: // DRAW 
      break;
    case 0xFF: // HLT
      break;
    default:
      break;
  }

}

void initialize_cpu()
{
  memset(&registers, 0, sizeof(registers)); 
  program_counter = 0;
}

uint8_t fetch_next_opcode()
{
  // TODO DO I NEED THIS HERE?
  return 0;
}

void run() {
  while (1) {
    uint8_t opcode = fetch_next_opcode();
    execute_instruction(opcode);
    if (opcode == 0xFF) break; // Halt the CPU
  }
}

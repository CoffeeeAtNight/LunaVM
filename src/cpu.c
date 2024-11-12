#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/cpu.h"
#include "../include/memory.h"

#define STACK_CAPACITY 1024

uint8_t registers[4];
uint8_t program_counter = 0;

void execute_instruction(uint8_t opcode) 
{
  switch (opcode) 
  {
    case 0x01: // MOV
      printf("GOT MOV INSTRUCTION\n");

      break;
    case 0x02: // ADD 
      break;
    case 0x03: // JMP 
      break;
    case 0x04: // DRAW 
      break;
    case 0xFF: // HLT
      printf("GOT HLT INSTRUCTION, STOPPING CPU EXECUTION\n");
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
  return v_memory[program_counter++];
}

void load_program(FILE* program) {
  size_t ret = fread(v_memory, 1, sizeof(v_memory), program);
  printf("Size of ret is: %zu\n", ret);
  if (ret == 0) {
    fprintf(stderr, "Failed to load program into virtual memory\n");
    exit(EXIT_FAILURE);
  }
}

void run(FILE* program) {
  initialize_memory();
  struct Stack* stack = initialize_stack(STACK_CAPACITY);
  load_program(program);
  while (1) {
    uint8_t opcode = fetch_next_opcode();
    execute_instruction(opcode);
    if (opcode == 0xFF) {
      free_stack(stack);
      break;
    }
  }
}

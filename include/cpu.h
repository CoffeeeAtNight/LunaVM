#ifndef CPU_H 
#define CPU_H

#include <stdio.h>
#include <stdint.h>

extern uint8_t registers[4];
extern uint8_t program_counter;

void execute_instruction(uint8_t opcode);
void initialize_cpu();
void run(FILE* program);
uint8_t fetch_next_opcode();
#endif

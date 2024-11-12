#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

extern uint8_t v_memory[256]; 
struct Stack;

void initialize_memory();

struct Stack* initialize_stack(unsigned capacity);
int isFull(struct Stack* stack);
int isEmpty(struct Stack* stack);
void push(struct Stack* stack, int value);
int pop(struct Stack* stack);
void free_stack(struct Stack* stack);

#endif


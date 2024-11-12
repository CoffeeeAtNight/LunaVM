#include "../include/memory.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define STACK_CAPACITY 1024

// 256 uint8_t (1 byte)
// Can go from 0x00 to 0xFF (255)
// RAM is 2048 BIT
uint8_t v_memory[256];

struct Stack {
  unsigned sp;
  unsigned capacity;
  int* array;
};

void initialize_memory() 
{
  memset(v_memory, 0, sizeof(v_memory));
  printf("[i] Virtual Memory initialized\n");
}

struct Stack* initialize_stack(unsigned capacity)
{
  struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
  stack->capacity = capacity;
  stack->sp = capacity - 1;
  stack->array = (int*)malloc(stack->capacity * sizeof(int));
  printf("[i] Stack initialized\n");
  return stack;
}

void free_stack(struct Stack* stack)
{
  free(stack->array);
  free(stack);
}

int isFull(struct Stack* stack) 
{
  return stack->sp; 
}

int isEmpty(struct Stack* stack)
{
  return stack->capacity == stack->sp;
}

void push(struct Stack* stack, int value)
{
  if (stack->sp <= 0) return;
  stack->array[--stack->sp] = value;
}

int pop(struct Stack* stack)
{
  if (stack->sp >= stack->capacity) return -1;
  int value = stack->array[stack->sp];
  stack->sp++;
  return value;
}

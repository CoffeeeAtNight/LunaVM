#include "../include/cpu.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE* program;
  
  if (argv[1] == NULL)
  {
    printf("Usage: ./lunavm [PATH_TO_PROGRAM_FILE]\n");
    return 1;  
  }

  printf("[i] Starting LunaVM with binary: %s\n", argv[1]);

  if((program = fopen(argv[1], "r")) == NULL)
    return 1;
  
  run(program);
  return EXIT_SUCCESS;
}


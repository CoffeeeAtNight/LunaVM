#include "../include/cpu.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE* program;
  
  if (argv[1] == NULL)
  {
    // Ran in program-mode
    printf("[i] Starting LunaVM with binary: %s\n", argv[1]);

    if((program = fopen(argv[1], "r")) == NULL)
      return 1;
    run(program);
  }


  // Ran in general purpose-mode
  run(program);
  return EXIT_SUCCESS;
}


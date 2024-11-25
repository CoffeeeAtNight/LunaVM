#ifndef OS_H
#define OS_H

#include "file_manager.h"

typedef enum { 
  STATE_DESKTOP,
  STATE_FILE_MANAGER,
  STATE_DOOM,
} AppState;

// Run General Purpose Mode
void gpm_main(); 

// Start file manager 
void init_file_manager();

#endif // OS_H

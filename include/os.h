#ifndef OS_H
#define OS_H

#include "file_manager.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { 
  STATE_DESKTOP,
  STATE_FILE_MANAGER,
  STATE_BLOOD_MOON_3D,
} AppState;

// Run General Purpose Mode
void gpm_main(); 

#ifdef __cplusplus
}
#endif

#endif // OS_H

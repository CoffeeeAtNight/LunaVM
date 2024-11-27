#include "../include/program_manager.h"
#include "../include/program_manager_wrapper.h"

static ProgramManager manager;

extern "C" void initProgramManager() {
  manager.initAll();
}

extern "C" void cleanupProgramManager() {
  manager.cleanupAll();
}

extern "C" void setActiveProgram(const char* programName) {
  manager.setActiveProgram(programName);
}

extern "C" const char* getActiveProgramName() {
  return manager.getActiveProgramName();
}


#ifndef PROGRAM_MANAGER_H
#define PROGRAM_MANAGER_H

#include <algorithm>
#include <vector>
#include <memory>
#include <string.h>
#include "lvm_program.h"

class ProgramManager {
private:
  std::vector<std::unique_ptr<LvmProgram>> programs; 
  LvmProgram* activeProgram = nullptr;
public:
  // Register a program
  void registerProgram(std::unique_ptr<LvmProgram> program) {
    programs.push_back(std::move(program));
  }

  // Initialize all programs
  void initAll() {
    for (auto& program : programs) {
      program->init();
    }
  }

  // Update the active program
  void updateActive() {
    if (activeProgram) {
      activeProgram->update();
    }
  }

  // Render the active program
  void renderActive() {
    if (activeProgram) {
      activeProgram->render();
    }
  }

  // Cleanup all programs
  void cleanupAll() {
    for (auto& program : programs) {
      program->cleanup();
    }
  }

  // Set the active program by name
  void setActiveProgram(const char* programName) {
    for (auto& program : programs) {
      if (strcmp(program->getProgramName(), programName) == 0) {
        activeProgram = program.get();
        return;
      }
    }
    activeProgram = nullptr;
  }

  // Get the name of the currently active program
  const char* getActiveProgramName() const {
    if (activeProgram) {
      return activeProgram->getProgramName();
    }
    return "None";
  }
};

#endif 


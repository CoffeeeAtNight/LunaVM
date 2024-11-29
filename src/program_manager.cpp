#include "../include/program_manager.h"
#include <iostream>
#include <cstring> 

void ProgramManager::registerProgram(std::unique_ptr<LvmProgram> program) {
  programs.push_back(std::move(program));
}

void ProgramManager::initAll() {
  for (auto& program : programs) {
    program->init();
  }
}

void ProgramManager::updateActive() {
  if (activeProgram) {
    activeProgram->update();
  }
}

void ProgramManager::renderActive() {
  if (activeProgram) {
    activeProgram->render();
  }
}

void ProgramManager::cleanupAll() {
  for (auto& program : programs) {
    program->cleanup();
  }
}

void ProgramManager::setActiveProgram(const char* programName) {
  std::cout << "Still works?" << "\n";
  for (auto& program : programs) {
    if (program == nullptr) {
      std::cout << "Error: program is null!" << std::endl;
      continue; // Skip null programs
    }

    const char* name = program->getProgramName();
    if (name == nullptr) {
      std::cout << "Error: program name is null!" << std::endl;
      continue; // Skip programs with invalid names
    }

    if (strcmp(name, programName) == 0) {
      std::cout << "Program name was correct!!" << "\n";
      activeProgram = program.get();
      return;
    }
  }
  std::cout << "Damn wrong program name ..." << "\n";
  activeProgram = nullptr;
}

const char* ProgramManager::getActiveProgramName() const {
  if (activeProgram) {
    return activeProgram->getProgramName();
  }
  return "None";
}


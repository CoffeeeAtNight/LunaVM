#include "../include/program_manager.h"
#include <iostream>
#include <cstring> 
#include <ostream>
#include <string>

void ProgramManager::registerProgram(std::unique_ptr<LvmProgram> program) {
  if (program) {
    programs.push_back(std::move(program));
  } else {
    std::cerr << "Error: Attempted to register a null program!" << std::endl;
  }
}


void ProgramManager::updateActive() {
  if (activeProgram) {
    activeProgram->update();
  }
}

void ProgramManager::renderActive() {
  if (activeProgram != nullptr) {
    activeProgram->render();
  } else {
    std::cout << "Null ptr in active render" << "\n";
  }
}

void ProgramManager::cleanupAll() {
  for (auto& program : programs) {
    program->cleanup();
  }
}

void ProgramManager::setActiveProgram(const std::string* programName) {
  for (auto& program : programs) {
    if (program == nullptr) {
      std::cout << "Error: program is null!" << std::endl;
      continue; // Skip null programs
    }

    const std::string name = program->getProgramName();
    if (name == "") {
      std::cout << "Error: program name is null!" << std::endl;
      continue; // Skip programs with invalid names
    }

    if (name == *programName) {
      std::cout << "Program name was correct!!" << "\n";
      activeProgram = program.get();
      return;
    }
  }
  activeProgram = nullptr;
}

const std::string ProgramManager::getActiveProgramName() const {
  if (activeProgram) {
    return activeProgram->getProgramName();
  }
  return "";
}


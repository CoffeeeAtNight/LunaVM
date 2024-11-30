#ifndef PROGRAM_MANAGER_H
#define PROGRAM_MANAGER_H

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <memory>
#include <cstring> 
#include "lvm_program.h"

class ProgramManager {
private:
    std::vector<std::unique_ptr<LvmProgram>> programs; 
    LvmProgram* activeProgram = nullptr;

public:
    // Register a program
    void registerProgram(std::unique_ptr<LvmProgram> program);

    // Initialize all programs
    void initAll();

    // Update the active program
    void updateActive();

    // Render the active program
    void renderActive();

    // Cleanup all programs
    void cleanupAll();

    // Set the active program by name
    void setActiveProgram(const std::string* programName);

    // Get the name of the currently active program
    const std::string getActiveProgramName() const;

};

#endif


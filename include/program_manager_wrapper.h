#ifndef PROGRAM_MANAGER_WRAPPER_H
#define PROGRAM_MANAGER_WRAPPER_H

#ifdef __cplusplus
extern "C" {
#endif

void initProgramManager();
void cleanupProgramManager();
void setActiveProgram(const char* programName);
const char* getActiveProgramName();

#ifdef __cplusplus
}
#endif

#endif // PROGRAM_MANAGER_WRAPPER_H


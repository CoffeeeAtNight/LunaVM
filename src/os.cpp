#include "../include/os.h"
#include "../include/graphic.h"
#include <memory>
#include <stdio.h>
#include "../include/program_manager.h"

AppState CURRENT_STATE = STATE_DESKTOP;

void register_programs(ProgramManager* pManager)
{
  //BloodMoon3d bloodMoon3d = BloodMoon3d()
  //pManager->registerProgram(std::unique_ptr<LvmProgram>()); 
};

void gpm_main()
{

  printf("[i] Starting LunaVM in general-purpose mode\n");
  
  ProgramManager pManager;
  
  initialize_render_ctx();
  register_programs(&pManager);

  // Main application loop
  while (!WindowShouldClose()) {
    process_input(&CURRENT_STATE);
    render(&CURRENT_STATE);
  }

  CloseWindow();
}

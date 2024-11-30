#include "../include/os.h"
#include "../include/graphic.h"
#include <memory>
#include <stdio.h>
#include <string>
#include <vector>
#include "../include/program_manager.h"
#include "../include/blood_moon_3d.h"

AppState CURRENT_STATE = STATE_DESKTOP;
const std::vector<std::string> listOfPrograms = {
  "BloodMoon3d",
};

void register_programs(ProgramManager* pManager)
{
  pManager->registerProgram(std::make_unique<BloodMoon3d>());
};

void update(ProgramManager* pManager) 
{
}

void render_main(ProgramManager* pManager)
{

  render(&CURRENT_STATE);

  if (CURRENT_STATE == STATE_BLOOD_MOON_3D)
  {
    std::string programName = std::string("BloodMoon3D"); 
   
    pManager->setActiveProgram(&programName);
    pManager->initAll(); 
    pManager->renderActive();
    pManager->updateActive();
  }

}

void gpm_main()
{

  printf("[i] Starting LunaVM in general-purpose mode\n");
  
  ProgramManager pManager;
  
  initialize_render_ctx();
  register_programs(&pManager);

  // Main application loop
  while (!WindowShouldClose()) {
    process_input(&CURRENT_STATE);
    update(&pManager);
    render_main(&pManager);
  }

  CloseWindow();
}

#include "../include/os.h"
#include "../include/desktop.h"
#include <memory>
#include <stdio.h>
#include <string>
#include <vector>
#include "../include/program_manager.h"
#include "../include/blood_moon_3d.h"

AppState CURRENT_STATE = STATE_DESKTOP;
bool isInitialized = false;
const std::vector<std::string> listOfPrograms = {
  "BloodMoon3D",
};

void register_programs(ProgramManager* pManager)
{
  //TODO HANDLE UNREGISTER TO DESTRUCT MEMBER STUFF?
  pManager->registerProgram(std::make_unique<BloodMoon3d>());
};

void update(ProgramManager* _pManager) 
{
}

void render_main(ProgramManager* pManager) {
  // Handle program state changes
  switch (CURRENT_STATE) {
    case STATE_BLOOD_MOON_3D: {
      if (!isInitialized) {
        std::cout << "Blood Moon 3D initializing..." << "\n"; 
        pManager->setActiveProgram(&listOfPrograms.at(0));
        isInitialized = true; 
      }
      pManager->updateActive();
      pManager->renderActive();
      break;
    }
    case STATE_DESKTOP: {
      render_ui_init(&CURRENT_STATE); 
      break;
    }
    case STATE_FILE_MANAGER: {
      break;
    }
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

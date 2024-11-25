#include "../include/os.h"
#include "../include/graphic.h"
#include <stdio.h>

AppState CURRENT_STATE = STATE_DESKTOP;


void gpm_main()
{
  printf("[i] Starting LunaVM in general-purpose mode\n");
  initialize_render_ctx();

  // Main application loop
  while (!WindowShouldClose()) {
    process_input(&CURRENT_STATE);
    render(&CURRENT_STATE);
  }

  CloseWindow();
}

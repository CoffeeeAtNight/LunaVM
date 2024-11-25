#ifndef GRAPHIC_H
#define GRAPHIC_H

#include "../include/resource_dir.h"
#include "../build/external/raylib-master/src/raylib.h"
#include "os.h"

typedef enum {
  SM = 45,
  LG = 60
} BtnSize;

typedef struct {
  int posX;
  int posY;
  int width;
  int height;
} AppWindowCtx;

int initialize_render_ctx();
void draw_taskbar_button(const char* text, int posX, int posY, BtnSize size);
void setup_desktop();
AppWindowCtx setup_app_window(const char* windowTitle);
void render_ui();
void process_input(AppState* currentState);
void render(AppState* currentState);

void render_dektop();
void render_file_manager();
void render_doom();

#endif // GRAPHIC_H

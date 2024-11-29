#include "../include/graphic.h"
#include "../include/resource_dir.h"
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

#define W_WIDTH  1280
#define W_HEIGHT 800
#define PLAYER_SIZE 11.0
#define GET_HALF(X) (X / 2)
#define CHECK_ERROR(condition, message)      \
    do {                                     \
        if (condition) {                     \
            fprintf(stderr, "Error: %s\n", message); \
            exit(EXIT_FAILURE);              \
        }                                    \
    } while (0)

bool START_MENU_OPEN = false;
bool START_MENU_ONE_OPEN = false;
bool TRANSITION_STATE = false;

Camera CAMERA = { 0 };
int CAMERA_MODE;

void draw_taskbar_button(const char* text, int posX, int posY, BtnSize size)
{
  int buttonHeight = 26;
  int buttonTextSize = 13.0;
  int buttonTextPaddingStartX = size == SM ? size / 9 : size / 6; 

  DrawRectangle(posX, posY - (buttonHeight / 2), size, 25, BROWN);
  DrawText(text, posX + buttonTextPaddingStartX, posY - (buttonTextSize / 2), buttonTextSize, WHITE);
}

void setup_desktop()
{
  int tbX = 0;
  int tbH = 50;
  int tbY = W_HEIGHT - tbH; 
  int tbW = W_WIDTH;

  // Draw Taskbar
  DrawRectangle(tbX, tbY, tbW, tbH, BEIGE);

  draw_taskbar_button("Start", 25, tbY + (tbH / 2), SM);
}

AppWindowCtx setup_app_window(const char* windowTitle)
{
  int appWindowW = 950;
  int appWindowH = 640;
  int appWindowX = W_WIDTH / 2 - appWindowW / 2;
  int appWindowY = W_HEIGHT / 2 - appWindowH / 2;
  int appWindowRenderAreaX = appWindowX;
  int appWindowRenderAreaY = appWindowY + 30;
  int appWindowRenderAreaW = appWindowW;
  int appWindowRenderAreaH = appWindowH - 30;

  AppWindowCtx newAppWindow;

  DrawRectangle(appWindowX, appWindowY, appWindowW, appWindowH, BROWN);                                           // Window
  DrawRectangle(appWindowX, appWindowY, appWindowW, 30, BEIGE);                                                   // Window Bar
  DrawText(windowTitle, appWindowX + 15, appWindowY + 8, 15.0, WHITE);                                            // Window Bar Title
  DrawText("Close [ x ]", (appWindowX + appWindowW) - 80, appWindowY + 8, 15.0, RED);                             // Window Close Button
  DrawRectangle(appWindowRenderAreaX, appWindowRenderAreaY, appWindowRenderAreaW, appWindowRenderAreaH, BLACK);   // Window Render Area

  newAppWindow.posX = appWindowRenderAreaX;
  newAppWindow.posY = appWindowRenderAreaY;
  newAppWindow.width = appWindowRenderAreaW;
  newAppWindow.height = appWindowRenderAreaH;

  return newAppWindow; 
}

void process_input(AppState *currentState)
{}

void render_desktop(AppState* currentState)
{
  double startTime = GetTime();
  setup_desktop();
  double desktopTime = GetTime() - startTime;

  BeginDrawing();

  DrawFPS(30, 30);
  DrawText(TextFormat("Desktop Render Time: %.3f ms", desktopTime * 1000.0), 30, 50, 20, WHITE);

  // Toggle Menus
  if(IsKeyPressed(KEY_SPACE)) START_MENU_OPEN = !START_MENU_OPEN;
  if(IsKeyPressed(KEY_ONE)) START_MENU_ONE_OPEN = !START_MENU_ONE_OPEN;
  if(IsKeyPressed(KEY_A)) TRANSITION_STATE = !TRANSITION_STATE;

  if(START_MENU_OPEN)
  {
    int startMenuX = 0;
    int startMenuY = 350;
    int startMenuW = 250;
    int startMenuH = 400;
    int paddingX = 25;
    int paddingY = 30;
    float fontSize = 16.0;

    DrawRectangle(startMenuX, startMenuY, startMenuW, startMenuH, BROWN);
    DrawText("Programs [ 1 ]", startMenuX + paddingX, startMenuY + paddingY, fontSize, WHITE);
    DrawText("File Manager [ 2 ]", startMenuX + paddingX, startMenuY + paddingY * 2, fontSize, WHITE);
    DrawText("Settings [ 3 ]", startMenuX + paddingX, startMenuY + paddingY * 3, fontSize, WHITE);
  
    if(START_MENU_ONE_OPEN)
    {
      DrawRectangle(startMenuW, startMenuY + paddingY, startMenuW, startMenuH / 2, BROWN);
      DrawText("Blood Moon 3D [ a ]", startMenuW + paddingX, startMenuY + paddingX * 2, fontSize, WHITE);
      
      if(TRANSITION_STATE)
      {
        // START Blood Moon 3D
        printf("[i] Starting Blood Moon 3D\n");
        START_MENU_OPEN = false;
        START_MENU_ONE_OPEN = false;
        TRANSITION_STATE = false;
        *currentState = STATE_BLOOD_MOON_3D; 
      }
    }
  }

  EndDrawing();
}

void render_file_manager()
{
  double startTime = GetTime();
  // STEP FUNCTION FOR FILE MANAGER
  double desktopTime = GetTime() - startTime;

  DrawFPS(30, 30);
  DrawText(TextFormat("File Manager Render Time: %.3f ms", desktopTime * 1000.0), 30, 50, 20, WHITE);
}

void render_doom()
{
  UpdateCamera(&CAMERA, CAMERA_MODE);
  Vector3 movement = { 0.f, 0.f, 0.f };
  Vector3 rotation = { 0.f, 0.f, 0.f };
  float zoom = 0.f;
  
  if(IsKeyDown(KEY_LEFT)) rotation.x = -1.5;
  if(IsKeyDown(KEY_RIGHT)) rotation.x = 1.5;
  if(IsKeyDown(KEY_UP)) rotation.y = -1.5;
  if(IsKeyDown(KEY_DOWN)) rotation.y = 1.5;

  UpdateCameraPro(&CAMERA, movement, rotation, zoom);
  BeginDrawing();

  double startTime = GetTime();
  setup_desktop();
  AppWindowCtx appWindowCtx = setup_app_window("Blood Moon 3D");
  double desktopTime = GetTime() - startTime;

  DrawFPS(30, 30);
  DrawText(TextFormat("Blood Moon 3D Render Time: %.3f ms", desktopTime * 1000.0), 30, 50, 20, WHITE);

  DisableCursor();
  BeginScissorMode(appWindowCtx.posX, appWindowCtx.posY, appWindowCtx.width, appWindowCtx.height);
  BeginMode3D(CAMERA);

  DrawPlane((Vector3){ 0.0f, 0.0f, 0.0f }, (Vector2){ 32.0f, 32.0f }, LIGHTGRAY);
  DrawCube((Vector3){ -16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, BLUE);
  DrawCube((Vector3){ 16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, LIME); 
  DrawCube((Vector3){ 0.0f, 2.5f, 16.0f }, 32.0f, 5.0f, 1.0f, GOLD);
  Vector3 cubePosition = { 
      (float)(appWindowCtx.posX - (float)W_WIDTH / 2) / W_WIDTH * 10.0f,
      5.0f,     
      (float)(appWindowCtx.posY - (float)W_HEIGHT / 2) / W_HEIGHT * 10.0f 
  };
  DrawCube(cubePosition, 1.0f, 1.0f, 1.0f, BLUE);
  DrawCubeWires(cubePosition, 1.0f, 1.0f, 1.0f, MAROON);

  EndMode3D();
  EndScissorMode();
  EndDrawing();
}

void render(AppState* currentState)
{
  // Setup the back buffer for drawing (clear color and depth buffers)
  ClearBackground(DARKGRAY);
  
  render_desktop(currentState);
}

int initialize_render_ctx()
{
 	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(1280, 800, "LunaVM | Virtualized Desktop");

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

  // Cap to 60 FPS
  SetTargetFPS(60);

  CAMERA.position = (Vector3){ 0.0f, 2.0f, 4.0f };    // Camera position
  CAMERA.target = (Vector3){ 0.0f, 2.0f, 0.0f };      // Camera looking at point
  CAMERA.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
  CAMERA.fovy = 60.0f;                                // Camera field-of-view Y
  CAMERA.projection = CAMERA_PERSPECTIVE;             // Camera projection type

  CAMERA_MODE = CAMERA_FIRST_PERSON;

  return EXIT_SUCCESS;
}

#include "../../include/blood_moon_3d.h"
#include <iostream>

// Constructor
BloodMoon3d::BloodMoon3d(int appWinX, int appWinY, int appWinW, int appWinH) : LvmProgram(0,0,0,0,true) {
  std::cout << "BloodMoon3d initialized as a 3D application." << std::endl;
  _appWinX = appWinX;
  _appWinY = appWinY;
  _appWinW = appWinW;
  _appWinH = appWinH;
}

// Destructor
BloodMoon3d::~BloodMoon3d() {
  std::cout << "BloodMoon3d resources cleaned up." << std::endl;
}

// Return program name
const char* BloodMoon3d::getProgramName() const { return "BloodMoon3d"; }

// Initialize the program
void BloodMoon3d::init() {
  std::cout << "Initializing BloodMoon3d..." << std::endl;
  camera.position = (Vector3){ 0.0f, 2.0f, 4.0f };    // Camera position
  camera.target = (Vector3){ 0.0f, 2.0f, 0.0f };      // Camera looking at point
  camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
  camera.fovy = 60.0f;                                // Camera field-of-view Y
  camera.projection = CAMERA_PERSPECTIVE;
  cameraMode = CAMERA_FIRST_PERSON;
}

// Update logic
void BloodMoon3d::update() {
  std::cout << "Updating BloodMoon3d..." << std::endl;

  float deltaTime = GetFrameTime();
  if (IsKeyDown(KEY_LEFT)) rotation.x -= 1.5f * deltaTime;
  if (IsKeyDown(KEY_RIGHT)) rotation.x += 1.5f * deltaTime;
  if (IsKeyDown(KEY_UP)) rotation.y -= 1.5f * deltaTime;
  if (IsKeyDown(KEY_DOWN)) rotation.y += 1.5f * deltaTime;
}

// Render the scene
void BloodMoon3d::render() {
  std::cout << "Rendering BloodMoon3d..." << std::endl;

  UpdateCameraPro(&camera, movement, rotation, zoom);
  BeginDrawing();

  DrawFPS(30, 30);

  DisableCursor();
  BeginScissorMode(_appWinX, _appWinY, _appWinW, _appWinH);
  BeginMode3D(camera);

  DrawPlane((Vector3){ 0.0f, 0.0f, 0.0f }, (Vector2){ 32.0f, 32.0f }, LIGHTGRAY);
  DrawCube((Vector3){ -16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, BLUE);
  DrawCube((Vector3){ 16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, LIME); 
  DrawCube((Vector3){ 0.0f, 2.5f, 16.0f }, 32.0f, 5.0f, 1.0f, GOLD);
  Vector3 cubePosition = { 
      (float)(_appWinX - (float)mWindowWidth / 2) / mWindowWidth * 10.0f,
      5.0f,     
      (float)(_appWinY - (float)mWindowHeight / 2) / mWindowHeight * 10.0f 
  };
  DrawCube(cubePosition, 1.0f, 1.0f, 1.0f, BLUE);
  DrawCubeWires(cubePosition, 1.0f, 1.0f, 1.0f, MAROON);

  EndMode3D();
  EndScissorMode();
  EndDrawing();
}

// Handle focus event
void BloodMoon3d::onFocus() {
  std::cout << "BloodMoon3d gained focus." << std::endl;
}

// Handle blur event
void BloodMoon3d::onBlur() {
  std::cout << "BloodMoon3d lost focus." << std::endl;
}

// Cleanup resources
void BloodMoon3d::cleanup() {
  std::cout << "Cleaning up BloodMoon3d resources..." << std::endl;
}


#include "../include/blood_moon_3d.h"
#include <iostream>

// Constructor
BloodMoon3d::BloodMoon3d() : LvmProgram(true) {
  std::cout << "BloodMoon3d initialized as a 3D application." << std::endl;
  init();
}

// Destructor
BloodMoon3d::~BloodMoon3d() {
  std::cout << "BloodMoon3d resources cleaned up." << std::endl;
}


// Initialize the program
void BloodMoon3d::init() {
 
}

// Update logic
void BloodMoon3d::update() {
  std::cout << "Updating BloodMoon3d..." << std::endl;

  float deltaTime = GetFrameTime(); 

  // Handle camera movement with W, A, S, D keys
  if (IsKeyDown(KEY_W)) {
    camera.position.z -= movementSpeed * deltaTime;
    camera.target.z -= movementSpeed * deltaTime;
  }
  if (IsKeyDown(KEY_S)) {
    camera.position.z += movementSpeed * deltaTime;
    camera.target.z += movementSpeed* deltaTime;
  }
  if (IsKeyDown(KEY_A)) {
    camera.position.x -= movementSpeed* deltaTime;
    camera.target.x -= movementSpeed* deltaTime;
  }
  if (IsKeyDown(KEY_D)) {
    camera.position.x += movementSpeed* deltaTime;
    camera.target.x += movementSpeed* deltaTime;
  }

  // Handle rotation with Arrow Keys
  if (IsKeyDown(KEY_LEFT)) {
    camera.target.x -= rotationSpeed* deltaTime;
  }
  if (IsKeyDown(KEY_RIGHT)) {
    camera.target.x += rotationSpeed* deltaTime;
  }
  if (IsKeyDown(KEY_UP)) {
    camera.target.y += rotationSpeed* deltaTime;
  }
  if (IsKeyDown(KEY_DOWN)) {
    camera.target.y -= rotationSpeed* deltaTime;
  }

}



// Render the scene
void BloodMoon3d::render() {
  std::cout << "Rendering BloodMoon3d..." << std::endl;
  std::cout << "Movement: " << movement.x << ", " << movement.y << ", " << movement.z << std::endl;
  std::cout << "Rotation: " << rotation.x << ", " << rotation.y << ", " << rotation.z << std::endl;
  std::cout << "Zoom: " << zoom << std::endl;

  BeginDrawing();

  setupLvmAppWindow();

  DisableCursor();
  BeginScissorMode(_appWinRenderAreaX, _appWinRenderAreaY, _appWinRenderAreaW, _appWinRenderAreaH);
  std::cout << "Entering 3D Mode" << std::endl;
  BeginMode3D(camera);

  ClearBackground(BLACK);
  std::cout << "Camera position: " << camera.position.x << ", " << camera.position.y << ", " << camera.position.z << std::endl;
  std::cout << "Camera target: " << camera.target.x << ", " << camera.target.y << ", " << camera.target.z << std::endl;

  DrawPlane((Vector3){ 0.0f, 0.0f, 0.0f }, (Vector2){ 32.0f, 32.0f }, LIGHTGRAY);
  DrawCube((Vector3){ -16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, BLUE);
  DrawCube((Vector3){ 16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, LIME); 
  DrawCube((Vector3){ 0.0f, 2.5f, 16.0f }, 32.0f, 5.0f, 1.0f, GOLD);
  Vector3 cubePosition = { 
      (float)(_appWinRenderAreaX - (float)W_WIDTH / 2) / W_WIDTH * 10.0f,
      5.0f,     
      (float)(_appWinRenderAreaY - (float)W_HEIGHT / 2) / W_HEIGHT * 10.0f 
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


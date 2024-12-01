#ifndef LVM_PROGRAM_H
#define LVM_PROGRAM_H 

#include "../raylib/src/raylib.h"
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <ostream>
#include <string>

constexpr int W_WIDTH = 1280;
constexpr int W_HEIGHT = 800;


class LvmProgram {
public:
  explicit LvmProgram(bool is3DApp) : Is3DApp(is3DApp) {
    std::cout << "LvmProgram constructor called with is3DApp = " << is3DApp << "\n";

    if (Is3DApp) {
      camera.position = (Vector3){ 0.0f, 2.0f, 4.0f };    // Camera position
      camera.target = (Vector3){ 0.0f, 2.0f, 0.0f };      // Camera looking at point
      camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
      camera.fovy = 60.0f;                                // Camera field-of-view Y
      camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type

      cameraMode = CAMERA_FIRST_PERSON;
    }


    _appWinW = 950;
    _appWinH = 640;
    _appWinX = W_WIDTH / 2 - _appWinW / 2;
    _appWinY = W_HEIGHT / 2 - _appWinH / 2;
   

    _appWinRenderAreaX = _appWinX;
    _appWinRenderAreaY = _appWinY + 30;
    _appWinRenderAreaW = _appWinW;
    _appWinRenderAreaH = _appWinH - 30;
  }

  virtual ~LvmProgram() = default;

  virtual const std::string& getProgramName() const = 0;
  virtual void init() = 0;
  virtual void update() = 0;
  virtual void render() = 0;
  virtual void onFocus() = 0;
  virtual void onBlur() = 0;
  virtual void cleanup() = 0;

protected:
  bool Is3DApp;
  int _appWinX, _appWinY, _appWinW, _appWinH, _appWinRenderAreaX, _appWinRenderAreaY, _appWinRenderAreaW, _appWinRenderAreaH;


  Camera camera = {};
  Vector3 movement = { 0.f, 0.f, 0.f };
  Vector3 rotation = { 0.f, 0.f, 0.f };
  float zoom = 0.f;
  int cameraMode;
  bool lvmInitDone = false;

  void setupLvmAppWindow() {
    if(!lvmInitDone) {

      const char* windowTitle = getProgramName().c_str();

      DrawRectangle(_appWinX, _appWinY, _appWinW, _appWinH, BROWN);                                           // Window
      DrawRectangle(_appWinX, _appWinY, _appWinW, 30, BEIGE);                                                   // Window Bar
      DrawText(windowTitle, _appWinX + 15, _appWinY + 8, 15.0, WHITE);                                            // Window Bar Title
      DrawText("Close [ x ]", (_appWinX + _appWinW) - 80, _appWinY + 8, 15.0, RED);                             // Window Close Button
      DrawRectangle(_appWinRenderAreaX, _appWinRenderAreaY, _appWinRenderAreaW, _appWinRenderAreaH, BLACK);   // Window Render Area
      lvmInitDone = true;
    }
  }
};

#endif // LVM_PROGRAM_H 

#ifndef LVM_PROGRAM_H
#define LVM_PROGRAM_H 

#include "../build/external/raylib-master/src/raylib.h"

class LvmProgram {
public:
  explicit LvmProgram(bool is3DApp) : Is3DApp(is3DApp) {
    if (Is3DApp) {
      // Initialize 3D-specific members
      camera = { 0 };
      camera.position = { 0.0f, 2.0f, 4.0f };
      camera.target = { 0.0f, 0.0f, 0.0f };
      camera.up = { 0.0f, 1.0f, 0.0f };
      camera.fovy = 60.0f;
      camera.projection = CAMERA_PERSPECTIVE;
    }
  }

  virtual ~LvmProgram() = default;

  virtual const char* getProgramName() const = 0;
  virtual void init() = 0;
  virtual void update() = 0;
  virtual void render() = 0;
  virtual void onFocus() = 0;
  virtual void onBlur() = 0;
  virtual void cleanup() = 0;

protected:
  bool Is3DApp;

  Camera camera = { 0 };
  Vector3 movement = { 0.f, 0.f, 0.f };
  Vector3 rotation = { 0.f, 0.f, 0.f };
  float zoom = 0.f;
};

#endif // LVM_PROGRAM_H 

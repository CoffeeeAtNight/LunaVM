#ifndef BLOOD_MOON_3D_H
#define BLOOD_MOON_3D_H

#include <string>
#include "lvm_program.h"

class BloodMoon3d : public LvmProgram {
private:
  std::string progamName = "BloodMoon3D";
  bool initialized = false;

  void init() override;
public:
    BloodMoon3d();
    ~BloodMoon3d() override;

    const std::string& getProgramName() const override {
      return progamName;
    };

    void update() override;
    void render() override;
    void onFocus() override;
    void onBlur() override;
    void cleanup() override;
};

#endif // BLOOD_MOON_3D_H


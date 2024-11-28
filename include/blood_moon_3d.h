#ifndef BLOOD_MOON_3D_H
#define BLOOD_MOON_3D_H

#include "lvm_program.h"

class BloodMoon3d : public LvmProgram {
public:
    BloodMoon3d(int appWinX, int appWinY, int appWinW, int appWinH);
    ~BloodMoon3d() override;

    const char* getProgramName() const override;
    void init() override;
    void update() override;
    void render() override;
    void onFocus() override;
    void onBlur() override;
    void cleanup() override;
};

#endif // BLOOD_MOON_3D_H


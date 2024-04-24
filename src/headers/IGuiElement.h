#pragma once
#include <raylib.h>

class IGuiElement {
protected:
    Rectangle body;
public:
    virtual void update(double deltaTime) = 0;
    virtual void draw() = 0;
};
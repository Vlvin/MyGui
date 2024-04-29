#pragma once
#include "types.h"
#include <raylib.h>
#include <string>
#include <memory>

class IGuiElement {
protected:
    std::string id_;
    Rectangle realbody_;
    RayRect body_;
    IGuiElement* parent_;
public:
    IGuiElement(const char* id, RayRect body, IGuiElement* parent = nullptr);
    RayRect body();
    Rectangle realbody();
    std::string id();
    IGuiElement* parent();
    virtual void update_size();
    virtual void update(double deltaTime) = 0;
    virtual void draw() = 0;

    void setPosition(RayUnit x, RayUnit y);
    void setSize(RayUnit width, RayUnit height);
    void setParent_(IGuiElement* parent);
};
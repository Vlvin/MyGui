#pragma once
#include "types.h"
#include <raylib.h>
#include <string>
#include <memory>

class IGuiElement {
protected:
    std::string id_;
    Rectangle realbody_;
    Rectangle body_;
    IGuiElement* parent_;
public:
    IGuiElement(const char* id, Rectangle body, IGuiElement* parent = nullptr);
    Rectangle body();
    std::string id();
    IGuiElement* parent();
    void setParent_(IGuiElement* parent);
    virtual void update_size();
    virtual void update(double deltaTime) = 0;
    virtual void draw() = 0;
};
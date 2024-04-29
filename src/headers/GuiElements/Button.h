#pragma once
#include "IGuiElement.h"

class Button : public IGuiElement {
protected:
    bool is_pressed_;
    Color color_;
    Color permacolor_;
    // std::string id
    // Rectangle body
    // RayRect realbody
public: 
    Button(const char* id, RayRect body, IGuiElement* parent, Color color = WHITE);
    ~Button();
    void setColor(Color color);
    virtual bool is_pressed();
    virtual void draw() override;
    virtual void update(double deltaTime) override;
};
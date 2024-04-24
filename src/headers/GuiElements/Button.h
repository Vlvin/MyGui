#pragma once
#include "IGuiElement.h"

class Button : public IGuiElement {
protected:
    bool is_pressed_;
    Color color_;
    // std::string id
    // Rectangle body
public: 
    Button(const char* id, Rectangle body, IGuiElement* parent);
    ~Button();
    virtual bool is_pressed();
    virtual void draw() override;
    virtual void update(double deltaTime) override;
};
#pragma once
#include <string>
#include "IGuiElement.h"

class TextEdit : public IGuiElement {
protected:
    std::string text_;
    bool is_in_focus_;
public:
    TextEdit(const char* id, RayRect body, IGuiElement* parent);

    std::string text();
    bool is_in_focus();

    virtual void update(double deltaTime) override;
    virtual void draw() override;
};
#pragma once
#include <string>
#include <vector>
#include "IGuiElement.h"

class TextEdit : public IGuiElement {
protected:
    std::vector<std::string> text_;
    size_t line_, cursor_, start_line_, start_index_;
    bool is_in_focus_;
public:
    TextEdit(const char* id, RayRect body, IGuiElement* parent);

    std::vector<std::string> text();
    std::string line(size_t line);
    bool is_in_focus();

    virtual void update(double deltaTime) override;
    virtual void draw() override;
};
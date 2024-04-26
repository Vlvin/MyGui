#include "GuiElements/Button.h"

Button::Button(const char* id, RayRect body, IGuiElement* parent)
: IGuiElement(id, body, parent) {
    this->is_pressed_ = false;
    this->color_ = WHITE;
}

Button::~Button() {}

bool Button::is_pressed() {
    return is_pressed_;
}

void Button::update(double deltaTime) {
    this->update_size();
    this->is_pressed_ = false;
    this->color_ = WHITE;
    Vector2 mouse = GetMousePosition();
    if ((realbody_.x < mouse.x) && (mouse.x < (realbody_.x + realbody_.width)) &&
        (realbody_.y < mouse.y) && (mouse.y < (realbody_.y + realbody_.height))
    ) 
    {
        this->color_ = GRAY;
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            this->color_ = DARKGRAY;
            this->is_pressed_ = true;
        }
    }
}

void Button::draw() {
    DrawRectangleRec(this->realbody_, this->color_);
}
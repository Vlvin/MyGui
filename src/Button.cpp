#include "GuiElements/Button.h"

Button::Button(const char* id, Rectangle body, IGuiElement* parent)
: IGuiElement(id, body, parent) {
    this->is_pressed_ = false;
    this->color_ = WHITE;
}

Button::~Button() {}

bool Button::is_pressed() {
    return is_pressed_;
}

void Button::update(double deltaTime) {
    this->is_pressed_ = false;
    this->color_ = WHITE;
    Vector2 mouse = GetMousePosition();
    if ((body_.x < mouse.x) && (mouse.x < (body_.x + body_.width)) &&
        (body_.y < mouse.y) && (mouse.y < (body_.y + body_.height))
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
    DrawRectangleRec(this->body_, this->color_);
}
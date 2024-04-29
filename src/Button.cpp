#include "GuiElements/Button.h"

Button::Button(const char* id, RayRect body, IGuiElement* parent, Color color)
: IGuiElement(id, body, parent) {
    this->is_pressed_ = false;
    this->color_ = color;
    this->permacolor_ = color;
}

Button::~Button() {}

bool Button::is_pressed() {
    return is_pressed_;
}

void Button::update(double deltaTime) {
    this->update_size();
    this->is_pressed_ = false;
    this->color_ = permacolor_;
    Vector2 mouse = GetMousePosition();
    if ((realbody_.x < mouse.x) && (mouse.x < (realbody_.x + realbody_.width)) &&
        (realbody_.y < mouse.y) && (mouse.y < (realbody_.y + realbody_.height))
    ) 
    {
        this->color_ = (Color){
                (u_char)(permacolor_.r > 50 ? permacolor_.r - 50 : 0), 
                (u_char)(permacolor_.g > 50 ? permacolor_.g - 50 : 0), 
                (u_char)(permacolor_.b > 50 ? permacolor_.b - 50 : 0), 
                permacolor_.a
            };
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            this->color_ = (Color){
                    (u_char)(permacolor_.r > 100 ? permacolor_.r - 100 : 0), 
                    (u_char)(permacolor_.g > 100 ? permacolor_.g - 100 : 0), 
                    (u_char)(permacolor_.b > 100 ? permacolor_.b - 100 : 0), 
                    permacolor_.a
                };
            this->is_pressed_ = true;
        }
    }
}

void Button::setColor(Color color) {
    this->permacolor_ = color;
}

void Button::draw() {
    DrawRectangleRec(this->realbody_, this->color_);
}
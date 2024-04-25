#include "IGuiElement.h"
#include "Window.h"
#include <iostream>

IGuiElement::IGuiElement(const char* id, Rectangle body, IGuiElement* parent) 
: id_(id), body_(body), parent_(parent) {
    if ((!parent) || dynamic_cast<Window*>(parent)) {
        this->realbody_ = body;
        return;
    }
    this->realbody_ = Rectangle{
        parent->body().x + parent->body().width * 0.01f * body.x,
        parent->body().y + parent->body().height * 0.01f * body.y,
        parent->body().width * 0.01f * body.x,
        parent->body().height * 0.01f * body.x
    };

}


Rectangle IGuiElement::body() {
    return this->body_;
}

std::string IGuiElement::id() {
    return this->id_;
}

IGuiElement* IGuiElement::parent() {
    return this->parent_;
}

void IGuiElement::setParent_(IGuiElement* parent) {
    this->parent_ = parent;
}

void IGuiElement::update_size() {
    if (!parent_) {
        this->realbody_ = body_;
        return;
    }
    if (dynamic_cast<Window*>(parent_)) {
        body_.x = 0;
        body_.y = 0;
        body_.width = parent_->body().width;
        body_.height = parent_->body().height;
        this->realbody_ = body_;
        return;
    }
    realbody_.x = parent_->body().x + parent_->body().width * 0.01f * body_.x;
    realbody_.y = parent_->body().y + parent_->body().height * 0.01f * body_.y;
    realbody_.width = parent_->body().width * 0.01f * body_.width;
    realbody_.height = parent_->body().height * 0.01f * body_.height;
}
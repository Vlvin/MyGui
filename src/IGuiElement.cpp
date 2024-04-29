#include "IGuiElement.h"
#include "Window.h"
#include <iostream>
#include <vector>

IGuiElement::IGuiElement(const char* id, RayRect body, IGuiElement* parent) 
: id_(id), body_(body), parent_(parent) {
    if ((!parent) || dynamic_cast<Window*>(parent)) {
        this->realbody_.x = body["x"];
        this->realbody_.y = body["y"];
        this->realbody_.width = body["width"];
        this->realbody_.height = body["height"];
        return;
    }
    this->realbody_ = Rectangle{0., 0., 0., 0.};
    // real_x
    if (body.x.type() == UnitType::PERCENT) {
        this->realbody_.x = parent->realbody().x + parent->realbody().width * 0.01f * body["x"];
    } else {
        this->realbody_.x = body["x"];
    }
    // real_y
    if (body.y.type() == UnitType::PERCENT) {
        this->realbody_.y = parent->realbody().y + parent->realbody().height * 0.01f * body["y"];
    } else {
        this->realbody_.y = body["y"];
    }
    // real_width
    if (body.width.type() == UnitType::PERCENT) {
        this->realbody_.width = parent->realbody().width * 0.01f * body["width"];
    } else {
        this->realbody_.width = body["width"];
    }
    // real_width
    if (body.height.type() == UnitType::PERCENT) {
        this->realbody_.height = parent->realbody().height * 0.01f * body["height"];
    } else {
        this->realbody_.height = body["height"];
    }
}


Rectangle IGuiElement::realbody() {
    return this->realbody_;
}

RayRect IGuiElement::body() {
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

void IGuiElement::setPosition(RayUnit x, RayUnit y) {
    this->body_.x = x;
    this->body_.y = y;
}

void IGuiElement::setSize(RayUnit width, RayUnit height) {
    this->body_.width = width;
    this->body_.height = height;
}

void IGuiElement::update_size() {
    if ((!parent_)) {
        this->realbody_.x = body_["x"];
        this->realbody_.y = body_["y"];
        this->realbody_.width = body_["width"];
        this->realbody_.height = body_["height"];
        return;
    }
    if (dynamic_cast<Window*>(parent_)) {
        body_.x = 0.;
        body_.y = 0.;
        body_.width = parent_->realbody().width;
        body_.height = parent_->realbody().height;

        this->realbody_.x = body_["x"];
        this->realbody_.y = body_["y"];
        this->realbody_.width = body_["width"];
        this->realbody_.height = body_["height"];
        return;
    }
    // real_x
    if (body_.x.type() == UnitType::PERCENT) {
        this->realbody_.x = parent_->realbody().x + parent_->realbody().width * 0.01f * body_["x"];
    } else {
        this->realbody_.x = body_["x"];
    }
    // real_y
    if (body_.y.type() == UnitType::PERCENT) {
        this->realbody_.y = parent_->realbody().y + parent_->realbody().height * 0.01f * body_["y"];
    } else {
        this->realbody_.y = body_["y"];
    }
    // real_width
    if (body_.width.type() == UnitType::PERCENT) {
        this->realbody_.width = parent_->realbody().width * 0.01f * body_["width"];
    } else {
        this->realbody_.width = body_["width"];
    }
    // real_width
    if (body_.height.type() == UnitType::PERCENT) {
        this->realbody_.height = parent_->realbody().height * 0.01f * body_["height"];
    } else {
        this->realbody_.height = body_["height"];
    }
}
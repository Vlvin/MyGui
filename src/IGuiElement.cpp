#include "IGuiElement.h"


IGuiElement::IGuiElement(const char* id, Rectangle body, IGuiElement* parent) 
: id_(id), body_(body), parent_(parent) {}


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
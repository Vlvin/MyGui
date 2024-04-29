#include "GuiElements/Screen.h"
#include "Background/Exception.h"

#include "Window.h"

Screen::Screen(const char* id, IGuiElement* parent) : IGuiElement(id, parent->body(), parent) {
    this->elements_ = {};
    this->elementsDictionary_ = {};
}

Screen::~Screen() {
    while (!elements_.empty())
        elements_.pop_back();
}

void Screen::draw() {
    for (size_t i = 0; i < elements_.size(); i++) {
        this->elements_[i]->draw();
    }
}

void Screen::update(double deltaTime) {
    this->update_size();
    for (size_t i = 0; i < elements_.size(); i++) {
        this->elements_[i]->update(deltaTime);
    }
}

void Screen::add(IGuiElement* element) {
    if (!element) return;
    element->setParent_(this);
    this->elementsDictionary_.insert({element->id(), this->elements_.size()});
    this->elements_.push_back(element);
}

void Screen::remove(const char* id) {
    std::string key(id);
    if (!this->elementsDictionary_.count(key))
        throw OutOfRangeException(
            "No such element: ", id
        );
    std::map<std::string, size_t>::iterator dictionarySlice = this->elementsDictionary_.find(key);
    size_t index = dictionarySlice->second;
    // remove from std::vector
    elements_[index] = elements_.back();
    elements_.pop_back();
    // remove from std::map allocating last element to new place
    std::prev(this->elementsDictionary_.end())->second = index;
    elementsDictionary_.erase(key);
}



// IGuiElement* Screen::operator[](const char* id) {
//     return this->get_p(id);
// }
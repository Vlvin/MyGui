#include "GuiElements.h"

Screen::Screen() {
    this->mElements = {};
    this->mElementsDictionary = {};
}

void Screen::draw() {
    for (int i = 0; i < mElements.size(); i++) {
        this->mElements[i]->draw();
    }
}

void Screen::update(double deltaTime) {
    for (int i = 0; i < mElements.size(); i++) {
        this->mElements[i]->update(deltaTime);
    }
}

IGuiElement* Screen::operator[](std::string id) {
    if (!this->mElementsDictionary.count(id)) return nullptr;
    std::map<std::string, size_t>::iterator dictionarySlice = this->mElementsDictionary.find(id);
    size_t index = dictionarySlice->second;
    return this->mElements[index];
}
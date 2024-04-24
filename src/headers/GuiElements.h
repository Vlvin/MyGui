#pragma once
#include <vector>
#include <string>
#include <map>
#include "IGuiElement.h"

class Screen : public IGuiElement {
protected:
    std::vector<IGuiElement*> mElements;
    std::map<std::string, size_t> mElementsDictionary;
public:
    Screen();
    virtual void draw() override;
    virtual void update(double deltaTime) override;
    void add(IGuiElement* element);
    IGuiElement* pGet(std::string key);
    IGuiElement* operator[](std::string key); // same as Screen::pGet but cleaner
};
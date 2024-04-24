#pragma once
#include <vector>
#include <string>
#include <map>
#include "Button.h"

class Screen : public IGuiElement {
protected:
    std::vector<IGuiElement*> elements_;
    std::map<std::string, size_t> elementsDictionary_;
public:
    Screen(const char* id, IGuiElement* parent);
    ~Screen();
    virtual void draw() override;
    virtual void update(double deltaTime) override;
    void add(IGuiElement* element);
    void remove(const char* id);
    IGuiElement* get_p(const char* id);
    IGuiElement* operator[](const char* id); // same as Screen::get_p() but cleaner

    friend class Window;
};
#pragma once
#include <vector>
#include <string>
#include <map>
#include "Button.h"
#include "Background/Exception.h"

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
    template <class El>
    El* get_p(const char* id) {
        std::string key(id);
        if (!this->elementsDictionary_.count(key)) 
            throw OutOfRangeException(
                "No such element: ", id
            );
        std::map<std::string, size_t>::iterator dictionarySlice = this->elementsDictionary_.find(key);
        size_t index = dictionarySlice->second;
        return dynamic_cast<El*>(this->elements_[index]);
    }
    template <class El>
    El* operator[](const char* id) {
        return get_p<El>(id);
    } // same as Screen::get_p() but cleaner

    friend class Window;
};
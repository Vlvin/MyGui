#pragma once
#include <raylib.h>
#include <memory>
#include <string>
#include "IGuiElement.h"

class Screen;

class Window : public IGuiElement {
private:
    static std::shared_ptr<Window> mInstance;
    Screen* mScreen;
    std::string title;
    Window(int positionX, int positionY, int width, int height, std::string title);
public:
    // void attachScreen(Screen* screen);
    static std::shared_ptr<Window> getInstance(int positionX = 0, int positionY = 0, int width = 0, int height = 0, std::string title = ""); // Will create one and only one main window if not exists
    ~Window();
    virtual void draw() override;
    virtual void update(double deltaTime) override;
};
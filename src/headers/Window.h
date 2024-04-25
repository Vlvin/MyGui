#pragma once
#include <raylib.h>
#include <memory>
#include <string>

#include "IGuiElement.h"

class Screen;

/** Window used to be a unique object that can be used from everywhere
 *  provides all stuff to work with window and elements
*/
class Window : public IGuiElement {
protected:
    static std::shared_ptr<Window> instance_p;
    std::shared_ptr<Screen> screen_p;
    Window(int positionX, int positionY, int width, int height, const char* title);
public:
    void attachScreen(std::shared_ptr<Screen> screen);
    static std::shared_ptr<Window> getInstance(int positionX = 0, int positionY = 0, int width = 0, int height = 0, const char* title = ""); // Will create one and only one main window if not exists
    ~Window();
    virtual void draw() override;
    virtual void update(double deltaTime) override;
    virtual void update_size() override;
};
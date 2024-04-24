#include <iostream>

#include "Window.h"
#include "GuiElements/Screen.h"

std::shared_ptr<Window> Window::instance_p = nullptr;

Window::Window(int positionX, int positionY, int width, int height, const char* title) 
: IGuiElement(title, Rectangle{(float)positionX, (float)positionY, (float)width, (float)height}) {
    InitWindow(width, height, title);
    SetWindowPosition(positionX, positionY);
    std::string scrID("Window::");
    scrID += title; scrID += ":Screen";
    this->screen_p = std::shared_ptr<Screen>
                    (
                        new Screen
                        (
                                scrID.c_str(), 
                                this
                        )
                    );
}

Window::~Window() {
    if (!Window::instance_p.use_count()) {
        CloseWindow();
    }
}

void Window::attachScreen(std::shared_ptr<Screen> screen) {
    (this->screen_p) = screen;
    (this->screen_p)->setParent_(this);
}

std::shared_ptr<Window> Window::getInstance(int positionX, int positionY, int width, int height, const char* title) {
    if (!Window::instance_p) {
        Window::instance_p = std::shared_ptr<Window>(new Window(positionX, positionY, width, height, title));
    }
    return Window::instance_p;
}

void Window::update(double deltaTime) {
    if (!this->screen_p) return;
    (this->screen_p)->update(deltaTime);
}

void Window::draw() {
    if (!this->screen_p) return;
    (this->screen_p)->draw();
}
#include <iostream>
#include "Window.h"
#include "GuiElements.h"

std::shared_ptr<Window> Window::mInstance = nullptr;

Window::Window(int positionX, int positionY, int width, int height, std::string title) {
    InitWindow(width, height, title.c_str());
    SetWindowPosition(positionX, positionY);
    this->body = Rectangle{(float)positionX, (float)positionY, (float)width, (float)height};
    this->mScreen = new Screen();
}

Window::~Window() {
    if (!Window::mInstance.use_count()) {
        delete this->mScreen;
        CloseWindow();
    }
}

std::shared_ptr<Window> Window::getInstance(int positionX, int positionY, int width, int height, std::string title) {
    if (!Window::mInstance) {
        Window::mInstance = std::shared_ptr<Window>(new Window(positionX, positionY, width, height, title));
    }
    return Window::mInstance;
}

void Window::update(double deltaTime) {
    this->mScreen->update(deltaTime);
}

void Window::draw() {
    this->mScreen->draw();
}
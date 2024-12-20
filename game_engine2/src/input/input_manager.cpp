#include "input_manager.h"
#include <GLFW/glfw3.h> // Voor toetsenbord- en muisinvoer
#include <iostream>     // Voor foutmeldingen

InputManager& InputManager::getInstance() {
    static InputManager instance;
    return instance;
}

InputManager::InputManager()
    : mousePosition(0.0f, 0.0f), prevMousePosition(0.0f, 0.0f) {}

InputManager::~InputManager() {}

void InputManager::update() {
    updateKeyState();
    updateMouseState();
}

bool InputManager::isKeyPressed(int key) const {
    auto it = keyState.find(key);
    if (it != keyState.end() && it->second) {
        auto prevIt = prevKeyState.find(key);
        return prevIt == prevKeyState.end() || !prevIt->second;
    }
    return false;
}

bool InputManager::isKeyReleased(int key) const {
    auto it = keyState.find(key);
    if (it != keyState.end() && !it->second) {
        auto prevIt = prevKeyState.find(key);
        return prevIt != prevKeyState.end() && prevIt->second;
    }
    return false;
}

bool InputManager::isKeyHeld(int key) const {
    auto it = keyState.find(key);
    return it != keyState.end() && it->second;
}

glm::vec2 InputManager::getMousePosition() const {
    return mousePosition;
}

glm::vec2 InputManager::getMouseDelta() const {
    return mousePosition - prevMousePosition;
}

bool InputManager::isMouseButtonPressed(int button) const {
    return glfwGetMouseButton(glfwGetCurrentContext(), button) == GLFW_PRESS;
}

bool InputManager::isMouseButtonReleased(int button) const {
    return glfwGetMouseButton(glfwGetCurrentContext(), button) == GLFW_RELEASE;
}

void InputManager::updateKeyState() {
    prevKeyState = keyState;

    for (int key = GLFW_KEY_SPACE; key <= GLFW_KEY_LAST; ++key) {
        int state = glfwGetKey(glfwGetCurrentContext(), key);
        keyState[key] = (state == GLFW_PRESS);
    }
}

void InputManager::updateMouseState() {
    prevMousePosition = mousePosition;

    double xpos, ypos;
    glfwGetCursorPos(glfwGetCurrentContext(), &xpos, &ypos);
    mousePosition = glm::vec2(static_cast<float>(xpos), static_cast<float>(ypos));
}

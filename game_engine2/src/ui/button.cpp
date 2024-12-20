#include "button.h"
#include <iostream>

Button::Button(std::string label, float x, float y, float width, float height)
    : label(label), x(x), y(y), width(width), height(height), isPressed(false) {}

Button::~Button() {}

void Button::update() {
    // Controleer of de knop is ingedrukt (dit kan bijvoorbeeld worden gecontroleerd via een muis- of toetsenbordinput)
    if (/* input check condition */) {
        isPressed = true;
    } else {
        isPressed = false;
    }
}

void Button::render() {
    // Teken de knop (bijvoorbeeld met een rechthoek en het label)
    std::cout << "Rendering button: " << label << " at (" << x << ", " << y << ")\n";
}

float Button::getX() const {
    return x;
}

float Button::getY() const {
    return y;
}

float Button::getWidth() const {
    return width;
}

float Button::getHeight() const {
    return height;
}

std::string Button::getLabel() const {
    return label;
}

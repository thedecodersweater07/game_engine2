#include "toolbar.h"
#include <iostream>

Toolbar::Toolbar() {
    // Initialisatie van de toolbar
}

Toolbar::~Toolbar() {
    // Opruimen van knoppen in de toolbar
    for (auto button : buttons) {
        delete button;
    }
}

void Toolbar::addButton(Button* button) {
    buttons.push_back(button);
}

void Toolbar::update() {
    // Werk de knoppen in de toolbar bij
    for (auto button : buttons) {
        button->update();
    }
}

void Toolbar::render() {
    // Teken de knoppen in de toolbar
    for (auto button : buttons) {
        button->render();
    }
}

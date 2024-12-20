#ifndef TOOLBAR_H
#define TOOLBAR_H

#include "button.h"
#include <vector>

class Toolbar {
public:
    Toolbar();
    ~Toolbar();

    // Voeg een knop toe aan de toolbar
    void addButton(Button* button);

    // Verwerk de knoppen in de toolbar
    void update();

    // Teken de toolbar
    void render();

private:
    std::vector<Button*> buttons;  // Lijst van knoppen
};

#endif // TOOLBAR_H

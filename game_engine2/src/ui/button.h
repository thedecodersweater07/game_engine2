#ifndef BUTTON_H
#define BUTTON_H

#include <string>

class Button {
public:
    Button(std::string label, float x, float y, float width, float height);
    ~Button();

    // Update de knopstatus (bijv. of hij geklikt is)
    void update();

    // Render de knop op het scherm
    void render();

    // Toegang tot de positie van de knop
    float getX() const;
    float getY() const;
    float getWidth() const;
    float getHeight() const;

    // Toegang tot het label van de knop
    std::string getLabel() const;

private:
    std::string label;  // Label van de knop
    float x, y;         // Positie van de knop
    float width, height; // Grootte van de knop
    bool isPressed;     // Is de knop ingedrukt?
};

#endif // BUTTON_H

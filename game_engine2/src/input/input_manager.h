#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <unordered_map>
#include <glm/glm.hpp> // Voor muispositie

class InputManager {
public:
    // Singleton patroon
    static InputManager& getInstance();

    // Updates input status, moet elke frame worden aangeroepen
    void update();

    // Toetsenbord invoer
    bool isKeyPressed(int key) const;
    bool isKeyReleased(int key) const;
    bool isKeyHeld(int key) const;

    // Muis invoer
    glm::vec2 getMousePosition() const;
    glm::vec2 getMouseDelta() const;
    bool isMouseButtonPressed(int button) const;
    bool isMouseButtonReleased(int button) const;

private:
    InputManager();
    ~InputManager();

    // Toetsenbord status
    std::unordered_map<int, bool> keyState;         // Huidige staat van toetsen
    std::unordered_map<int, bool> prevKeyState;     // Vorige staat van toetsen

    // Muis status
    glm::vec2 mousePosition;
    glm::vec2 prevMousePosition;

    // Helper functies
    void updateKeyState();
    void updateMouseState();
};

#endif // INPUT_MANAGER_H

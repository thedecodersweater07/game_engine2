#include "skybox.h"
#include <iostream>

Skybox::Skybox() 
    : textureID(0), size(100.0f) { // Default size of the skybox
    std::cout << "Skybox created." << std::endl;
}

Skybox::~Skybox() {
    unload();
    std::cout << "Skybox destroyed." << std::endl;
}

void Skybox::load(const std::string& texturePath) {
    faces.push_back(texturePath);
    std::cout << "Loading skybox texture: " << texturePath << std::endl;

    // In an actual implementation, OpenGL or another graphics API would load the texture
    textureID = 1; // Placeholder for texture loading
}

void Skybox::render() {
    if (textureID == 0) {
        std::cerr << "Error: Skybox texture not loaded!" << std::endl;
        return;
    }

    std::cout << "Rendering skybox of size: " << size << " with texture ID: " << textureID << std::endl;

    // In an actual implementation, rendering code using OpenGL or a similar library would go here
}

void Skybox::unload() {
    if (textureID != 0) {
        std::cout << "Unloading skybox texture with ID: " << textureID << std::endl;
        textureID = 0;
        faces.clear();
    }
}

void Skybox::setSize(float newSize) {
    if (newSize <= 0) {
        std::cerr << "Error: Invalid skybox size!" << std::endl;
        return;
    }
    size = newSize;
    std::cout << "Skybox size set to: " << size << std::endl;
}

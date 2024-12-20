#ifndef SKYBOX_H
#define SKYBOX_H

#include <string>
#include <vector>

class Skybox {
public:
    // Constructor and Destructor
    Skybox();
    ~Skybox();

    // Methods to load and render the skybox
    void load(const std::string& texturePath);
    void render();

    // Method to unload textures
    void unload();

    // Method to set the size of the skybox
    void setSize(float size);

private:
    std::vector<std::string> faces; // Paths to the textures for each face of the skybox
    unsigned int textureID;         // ID for the skybox texture
    float size;                     // Size of the skybox
};

#endif // SKYBOX_H

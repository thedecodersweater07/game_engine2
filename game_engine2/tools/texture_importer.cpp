#include "texture_importer.h"
#include <iostream>
#include <stb_image.h>

bool TextureImporter::loadTexture(const std::string& filePath, Texture& texture) {
    std::cout << "Loading texture from " << filePath << "..." << std::endl;

    // Gebruik stb_image om de textuur te laden
    int width, height, channels;
    unsigned char* image = stbi_load(filePath.c_str(), &width, &height, &channels, 0);
    if (!image) {
        std::cerr << "Failed to load texture: " << filePath << std::endl;
        return false;
    }

    // Zet de geladen textuurdata in de texture object
    texture.setWidth(width);
    texture.setHeight(height);
    texture.setData(image);
    texture.setChannels(channels);

    // Het geheugen voor de afbeelding is nu opgeslagen in het texture object, dus we kunnen het nu vrijgeven
    stbi_image_free(image);

    std::cout << "Texture loaded successfully from " << filePath << std::endl;
    return true;
}

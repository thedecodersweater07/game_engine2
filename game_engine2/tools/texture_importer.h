#ifndef TEXTURE_IMPORTER_H
#define TEXTURE_IMPORTER_H

#include <string>
#include "texture.h"

// De TextureImporter klasse is verantwoordelijk voor het importeren van texturen uit verschillende formaten.
class TextureImporter {
public:
    // Laadt een textuur uit een bestand
    bool loadTexture(const std::string& filePath, Texture& texture);
};

#endif // TEXTURE_IMPORTER_H

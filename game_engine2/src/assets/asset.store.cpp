#include "asset_store.h"
#include <iostream>
#include <fstream>

// Constructor
AssetStore::AssetStore() {
    std::cout << "AssetStore initialized." << std::endl;
}

// Destructor
AssetStore::~AssetStore() {
    std::cout << "AssetStore destroyed." << std::endl;
}

// Laad een model in de store
bool AssetStore::loadModel(const std::string& filePath, const std::string& modelName) {
    // Controleer of het model al is geladen
    if (models.find(modelName) != models.end()) {
        std::cerr << "Model " << modelName << " is already loaded." << std::endl;
        return false;
    }

    // Hier zou je de echte logica voor het laden van een model gebruiken
    std::shared_ptr<Model> model = std::make_shared<Model>();
    // Laad model uit bestand
    if (!model->loadFromFile(filePath)) {
        std::cerr << "Failed to load model from " << filePath << std::endl;
        return false;
    }

    // Voeg het model toe aan de store
    models[modelName] = model;
    std::cout << "Model " << modelName << " loaded successfully." << std::endl;
    return true;
}

// Laad een textuur in de store
bool AssetStore::loadTexture(const std::string& filePath, const std::string& textureName) {
    // Controleer of de textuur al is geladen
    if (textures.find(textureName) != textures.end()) {
        std::cerr << "Texture " << textureName << " is already loaded." << std::endl;
        return false;
    }

    // Hier zou je de echte logica voor het laden van een textuur gebruiken
    std::shared_ptr<Texture> texture = std::make_shared<Texture>();
    // Laad textuur uit bestand
    if (!texture->loadFromFile(filePath)) {
        std::cerr << "Failed to load texture from " << filePath << std::endl;
        return false;
    }

    // Voeg de textuur toe aan de store
    textures[textureName] = texture;
    std::cout << "Texture " << textureName << " loaded successfully." << std::endl;
    return true;
}

// Laad een geluid in de store
bool AssetStore::loadSound(const std::string& filePath, const std::string& soundName) {
    // Controleer of het geluid al is geladen
    if (sounds.find(soundName) != sounds.end()) {
        std::cerr << "Sound " << soundName << " is already loaded." << std::endl;
        return false;
    }

    // Hier zou je de echte logica voor het laden van een geluid gebruiken
    std::shared_ptr<Sound> sound = std::make_shared<Sound>();
    // Laad geluid uit bestand
    if (!sound->loadFromFile(filePath)) {
        std::cerr << "Failed to load sound from " << filePath << std::endl;
        return false;
    }

    // Voeg het geluid toe aan de store
    sounds[soundName] = sound;
    std::cout << "Sound " << soundName << " loaded successfully." << std::endl;
    return true;
}

// Verkrijg een geladen model
std::shared_ptr<Model> AssetStore::getModel(const std::string& modelName) {
    if (models.find(modelName) != models.end()) {
        return models[modelName];
    }
    std::cerr << "Model " << modelName << " not found." << std::endl;
    return nullptr;
}

// Verkrijg een geladen textuur
std::shared_ptr<Texture> AssetStore::getTexture(const std::string& textureName) {
    if (textures.find(textureName) != textures.end()) {
        return textures[textureName];
    }
    std::cerr << "Texture " << textureName << " not found." << std::endl;
    return nullptr;
}

// Verkrijg een geladen geluid
std::shared_ptr<Sound> AssetStore::getSound(const std::string& soundName) {
    if (sounds.find(soundName) != sounds.end()) {
        return sounds[soundName];
    }
    std::cerr << "Sound " << soundName << " not found." << std::endl;
    return nullptr;
}

// Verwijder een asset uit de store
void AssetStore::removeAsset(const std::string& assetName) {
    if (models.find(assetName) != models.end()) {
        models.erase(assetName);
        std::cout << "Model " << assetName << " removed." << std::endl;
    }
    else if (textures.find(assetName) != textures.end()) {
        textures.erase(assetName);
        std::cout << "Texture " << assetName << " removed." << std::endl;
    }
    else if (sounds.find(assetName) != sounds.end()) {
        sounds.erase(assetName);
        std::cout << "Sound " << assetName << " removed." << std::endl;
    }
    else {
        std::cerr << "Asset " << assetName << " not found." << std::endl;
    }
}

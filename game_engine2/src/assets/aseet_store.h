#ifndef ASSET_STORE_H
#define ASSET_STORE_H

#include <string>
#include <unordered_map>
#include <memory>
#include "model.h"
#include "texture.h"
#include "sound.h"

// De AssetStore is verantwoordelijk voor het beheren van alle assets in de game.
class AssetStore {
public:
    // Constructor en Destructor
    AssetStore();
    ~AssetStore();

    // Laad een model uit een bestand en sla het op in de store
    bool loadModel(const std::string& filePath, const std::string& modelName);

    // Laad een textuur uit een bestand en sla het op in de store
    bool loadTexture(const std::string& filePath, const std::string& textureName);

    // Laad een geluid uit een bestand en sla het op in de store
    bool loadSound(const std::string& filePath, const std::string& soundName);

    // Verkrijg een geladen model
    std::shared_ptr<Model> getModel(const std::string& modelName);

    // Verkrijg een geladen textuur
    std::shared_ptr<Texture> getTexture(const std::string& textureName);

    // Verkrijg een geladen geluid
    std::shared_ptr<Sound> getSound(const std::string& soundName);

    // Verwijder een specifiek asset uit de store
    void removeAsset(const std::string& assetName);

private:
    // Maps voor asset opslag
    std::unordered_map<std::string, std::shared_ptr<Model>> models;
    std::unordered_map<std::string, std::shared_ptr<Texture>> textures;
    std::unordered_map<std::string, std::shared_ptr<Sound>> sounds;
};

#endif // ASSET_STORE_H

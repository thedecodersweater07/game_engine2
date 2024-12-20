#ifndef MESH_IMPORTER_H
#define MESH_IMPORTER_H

#include <string>
#include <vector>
#include "model.h"

// De MeshImporter klasse is verantwoordelijk voor het importeren van 3D-modellen van verschillende bestandsformaten.
class MeshImporter {
public:
    // Laadt een model uit een bestand
    bool loadModel(const std::string& filePath, Model& model);

private:
    // Helperfunctie voor het verwerken van specifieke modelgegevens
    bool processMeshData(const std::string& filePath, Model& model);
};

#endif // MESH_IMPORTER_H

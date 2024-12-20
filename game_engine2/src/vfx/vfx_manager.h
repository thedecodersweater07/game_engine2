#ifndef VFX_MANAGER_H
#define VFX_MANAGER_H

#include <vector>
#include "particle_system.h"

class VFXManager {
public:
    VFXManager();
    ~VFXManager();

    void initialize();
    void update(float deltaTime);
    void render();
    void add_particle_system(const ParticleSystem& particleSystem);

private:
    std::vector<ParticleSystem> particleSystems;
};

#endif

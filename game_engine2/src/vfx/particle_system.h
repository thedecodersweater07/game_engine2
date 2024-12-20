#ifndef PARTICLE_SYSTEM_H
#define PARTICLE_SYSTEM_H

#include <vector>
#include <glm/glm.hpp>

struct Particle {
    glm::vec3 position;
    glm::vec3 velocity;
    float lifetime;
};

class ParticleSystem {
public:
    ParticleSystem();
    void initialize(int maxParticles);
    void update(float deltaTime);
    void render();

private:
    std::vector<Particle> particles;
    int maxParticles;
};

#endif

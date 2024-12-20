#include "particle_system.h"
#include <iostream>

ParticleSystem::ParticleSystem() : maxParticles(0) {}

void ParticleSystem::initialize(int maxParticles) {
    this->maxParticles = maxParticles;
    particles.resize(maxParticles);
    std::cout << "Particle system initialized with " << maxParticles << " particles." << std::endl;
}

void ParticleSystem::update(float deltaTime) {
    for (auto& particle : particles) {
        particle.position += particle.velocity * deltaTime;
        particle.lifetime -= deltaTime;
        if (particle.lifetime <= 0) {
            particle.position = {0, 0, 0};
            particle.lifetime = 5.0f; // Reset lifetime
        }
    }
}

void ParticleSystem::render() {
    for (const auto& particle : particles) {
        // Render particle at `particle.position`
    }
}

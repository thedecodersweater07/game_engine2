#include "vfx_manager.h"
#include <iostream>

VFXManager::VFXManager() {
    std::cout << "VFX Manager initialized." << std::endl;
}

VFXManager::~VFXManager() {
    std::cout << "VFX Manager destroyed." << std::endl;
}

void VFXManager::initialize() {
    std::cout << "Initializing VFX systems..." << std::endl;
}

void VFXManager::update(float deltaTime) {
    for (auto& system : particleSystems) {
        system.update(deltaTime);
    }
    std::cout << "VFX systems updated." << std::endl;
}

void VFXManager::render() {
    for (const auto& system : particleSystems) {
        system.render();
    }
    std::cout << "Rendering VFX systems." << std::endl;
}

void VFXManager::add_particle_system(const ParticleSystem& particleSystem) {
    particleSystems.push_back(particleSystem);
    std::cout << "Added new particle system." << std::endl;
}

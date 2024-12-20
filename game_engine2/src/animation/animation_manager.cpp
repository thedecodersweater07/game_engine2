#include "animation_manager.h"
#include <iostream>

AnimationManager::AnimationManager() {
    std::cout << "Animation Manager initialized." << std::endl;
}

AnimationManager::~AnimationManager() {
    std::cout << "Animation Manager destroyed." << std::endl;
}

void AnimationManager::update(float deltaTime) {
    for (auto& animation : animations) {
        animation.update(deltaTime);
    }
    std::cout << "Animations updated." << std::endl;
}

void AnimationManager::add_animation(const Animation& animation) {
    animations.push_back(animation);
    std::cout << "Added new animation." << std::endl;
}

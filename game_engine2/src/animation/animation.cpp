#include "animation.h"
#include <iostream>

Animation::Animation(const std::string& name, float duration)
    : name(name), duration(duration), currentTime(0.0f) {}

void Animation::update(float deltaTime) {
    currentTime += deltaTime;
    if (currentTime > duration) {
        currentTime = 0.0f; // Loop the animation
    }
}

bool Animation::is_finished() const {
    return currentTime >= duration;
}

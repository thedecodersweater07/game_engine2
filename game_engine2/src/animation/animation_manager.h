#ifndef ANIMATION_MANAGER_H
#define ANIMATION_MANAGER_H

#include <vector>
#include "animation.h"

class AnimationManager {
public:
    AnimationManager();
    ~AnimationManager();

    void update(float deltaTime);
    void add_animation(const Animation& animation);

private:
    std::vector<Animation> animations;
};

#endif

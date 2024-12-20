#ifndef ANIMATION_H
#define ANIMATION_H

#include <string>

class Animation {
public:
    Animation(const std::string& name, float duration);
    void update(float deltaTime);
    bool is_finished() const;

private:
    std::string name;
    float duration;
    float currentTime;
};

#endif

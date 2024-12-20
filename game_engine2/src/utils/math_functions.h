#ifndef MATH_FUNCTIONS_H
#define MATH_FUNCTIONS_H

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace MathFunctions {
    // Vector-bewerkingen
    float dotProduct(const glm::vec3& vec1, const glm::vec3& vec2);
    glm::vec3 crossProduct(const glm::vec3& vec1, const glm::vec3& vec2);

    // Matrix-transformaties
    glm::mat4 createTranslationMatrix(const glm::vec3& translation);
    glm::mat4 createRotationMatrix(const glm::quat& rotation);
    glm::mat4 createScaleMatrix(const glm::vec3& scale);

    // Interpolatie
    glm::vec3 lerp(const glm::vec3& start, const glm::vec3& end, float t);
    glm::quat slerp(const glm::quat& start, const glm::quat& end, float t);

    // Hulpfuncties
    float toRadians(float degrees);
    float toDegrees(float radians);
}

#endif // MATH_FUNCTIONS_H

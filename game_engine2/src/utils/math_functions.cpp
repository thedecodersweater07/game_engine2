#include "math_functions.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>

namespace MathFunctions {
    // Vector-bewerkingen
    float dotProduct(const glm::vec3& vec1, const glm::vec3& vec2) {
        return glm::dot(vec1, vec2);
    }

    glm::vec3 crossProduct(const glm::vec3& vec1, const glm::vec3& vec2) {
        return glm::cross(vec1, vec2);
    }

    // Matrix-transformaties
    glm::mat4 createTranslationMatrix(const glm::vec3& translation) {
        return glm::translate(glm::mat4(1.0f), translation);
    }

    glm::mat4 createRotationMatrix(const glm::quat& rotation) {
        return glm::toMat4(rotation);
    }

    glm::mat4 createScaleMatrix(const glm::vec3& scale) {
        return glm::scale(glm::mat4(1.0f), scale);
    }

    // Interpolatie
    glm::vec3 lerp(const glm::vec3& start, const glm::vec3& end, float t) {
        return glm::mix(start, end, t);
    }

    glm::quat slerp(const glm::quat& start, const glm::quat& end, float t) {
        return glm::slerp(start, end, t);
    }

    // Hulpfuncties
    float toRadians(float degrees) {
        return glm::radians(degrees);
    }

    float toDegrees(float radians) {
        return glm::degrees(radians);
    }
}

#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
    Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch);

    // Retourneert de view-matrix van de camera
    glm::mat4 getViewMatrix() const;

    // Beweging van de camera
    void moveForward(float distance);
    void moveBackward(float distance);
    void moveRight(float distance);
    void moveLeft(float distance);

    // Camera rotatie
    void rotate(float yawOffset, float pitchOffset);

    // Instellen van perspectief
    glm::mat4 getProjectionMatrix(float aspectRatio, float fov, float nearPlane, float farPlane) const;

    // Camera-instellingen ophalen
    glm::vec3 getPosition() const;

private:
    void updateCameraVectors();

    // Camera eigenschappen
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    glm::vec3 right;
    glm::vec3 worldUp;

    // Euler-hoeken
    float yaw;
    float pitch;

    // Beperkingen
    const float pitchLimit = 89.0f; // Max pitch om gimbal lock te voorkomen
};

#endif // CAMERA_H

#include "camera.h"

Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
    : position(position), worldUp(up), yaw(yaw), pitch(pitch) {
    updateCameraVectors();
}

glm::mat4 Camera::getViewMatrix() const {
    return glm::lookAt(position, position + front, up);
}

void Camera::moveForward(float distance) {
    position += front * distance;
}

void Camera::moveBackward(float distance) {
    position -= front * distance;
}

void Camera::moveRight(float distance) {
    position += right * distance;
}

void Camera::moveLeft(float distance) {
    position -= right * distance;
}

void Camera::rotate(float yawOffset, float pitchOffset) {
    yaw += yawOffset;
    pitch += pitchOffset;

    // Beperk pitch om gimbal lock te voorkomen
    if (pitch > pitchLimit) pitch = pitchLimit;
    if (pitch < -pitchLimit) pitch = -pitchLimit;

    updateCameraVectors();
}

glm::mat4 Camera::getProjectionMatrix(float aspectRatio, float fov, float nearPlane, float farPlane) const {
    return glm::perspective(glm::radians(fov), aspectRatio, nearPlane, farPlane);
}

glm::vec3 Camera::getPosition() const {
    return position;
}

void Camera::updateCameraVectors() {
    // Bereken de nieuwe front-vector
    glm::vec3 newFront;
    newFront.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    newFront.y = sin(glm::radians(pitch));
    newFront.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    front = glm::normalize(newFront);

    // Bereken right en up vectors
    right = glm::normalize(glm::cross(front, worldUp));
    up = glm::normalize(glm::cross(right, front));
}

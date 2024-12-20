#ifndef GLM_HPP
#define GLM_HPP

// GLM 0.9.9 header file, contains functions and types for vector math operations

#include <cmath>

namespace glm {
    typedef float vec3[3];

    inline void normalize(vec3& v) {
        float length = std::sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
        v[0] /= length;
        v[1] /= length;
        v[2] /= length;
    }

    inline void cross(const vec3& a, const vec3& b, vec3& result) {
        result[0] = a[1] * b[2] - a[2] * b[1];
        result[1] = a[2] * b[0] - a[0] * b[2];
        result[2] = a[0] * b[1] - a[1] * b[0];
    }

    inline void dot(const vec3& a, const vec3& b, float& result) {
        result = a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
    }
}

#endif // GLM_HPP

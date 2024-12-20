#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <unordered_map>
#include <glm/glm.hpp> // For matrix uniforms

class Shader {
public:
    unsigned int ID; // Shader program ID

    // Constructor
    Shader(const std::string& vertexPath, const std::string& fragmentPath);

    // Use the shader program
    void use() const;

    // Utility functions for setting uniforms
    void setBool(const std::string& name, bool value) const;
    void setInt(const std::string& name, int value) const;
    void setFloat(const std::string& name, float value) const;
    void setVec3(const std::string& name, const glm::vec3& value) const;
    void setMat4(const std::string& name, const glm::mat4& mat) const;

    // Destructor
    ~Shader();

private:
    // Private utility functions
    std::string readFile(const std::string& path) const;
    unsigned int compileShader(unsigned int type, const std::string& source);
    void linkProgram(unsigned int vertexShader, unsigned int fragmentShader);

    mutable std::unordered_map<std::string, int> uniformCache; // Cache for uniform locations
    int getUniformLocation(const std::string& name) const;
};

#endif // SHADER_H

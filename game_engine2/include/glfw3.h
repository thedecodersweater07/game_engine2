#ifndef GLFW3_H
#define GLFW3_H

// GLFW 3.3 header file, contains declarations for the window management and input

#ifdef __cplusplus
extern "C" {
#endif

// Some of the GLFW constants and types
typedef void (*GLFWkeyfun)(GLFWwindow* window, int key, int scancode, int action, int mods);
typedef struct GLFWwindow GLFWwindow;

GLFWwindow* glfwCreateWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share);
void glfwDestroyWindow(GLFWwindow* window);
void glfwPollEvents(void);
int glfwGetKey(GLFWwindow* window, int key);

int glfwInit(void);
void glfwTerminate(void);

#ifdef __cplusplus
}
#endif

#endif // GLFW3_H

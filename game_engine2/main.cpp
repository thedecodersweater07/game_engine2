#include <iostream>
#include <GLFW/glfw3.h>
#include <GL/glew.h>
#include "src/camera/camera.h"
#include "src/graphics/renderer.h"
#include "src/ui/ui_manager.h"
#include "src/events/event_manager.h"
#include "src/input/input_manager.h"
#include "src/loading/loading_screen.h"
#include "src/core/engine.h"
#include "src/systems/cpu_gpu_manager.h"  // Toevoegen van de CPU-GPU Manager

// Functie voor het initialiseren van GLFW en GLEW
bool initializeGraphics(GLFWwindow** window) {
    if (!glfwInit()) {
        std::cerr << "Error: GLFW initialization failed!" << std::endl;
        return false;
    }

    *window = glfwCreateWindow(1280, 720, "Game Engine", nullptr, nullptr);
    if (!*window) {
        std::cerr << "Error: GLFW window creation failed!" << std::endl;
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(*window);
    glfwSwapInterval(1);  // Schakel V-Sync in

    if (glewInit() != GLEW_OK) {
        std::cerr << "Error: GLEW initialization failed!" << std::endl;
        return false;
    }

    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
    return true;
}

int main() {
    GLFWwindow* window;

    // Initialiseer de graphics
    if (!initializeGraphics(&window)) {
        return -1;
    }

    // Initialiseer de game engine componenten
    Engine engine;
    InputManager inputManager;
    Camera camera;
    Renderer renderer;
    UIManager uiManager;
    EventManager eventManager;
    LoadingScreen loadingScreen;
    
    // Initialiseer CPU_GPU_Manager voor prestatiebeheer
    CPU_GPU_Manager cpuGpuManager;

    // Hoofdlus van de game
    while (!glfwWindowShouldClose(window)) {
        // Verwerk invoer
        inputManager.processInput(window);

        // Update game logica
        eventManager.handleEvents();

        // Monitor en optimaliseer CPU en GPU-prestaties
        cpuGpuManager.monitorPerformance();
        cpuGpuManager.optimizeCPUUsage();
        cpuGpuManager.optimizeGPUUsage();

        // Render de scene
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        renderer.renderScene(camera);

        // Render UI
        uiManager.renderUI();

        // Render loading scherm
        loadingScreen.render();

        // Wissel de buffers
        glfwSwapBuffers(window);

        // Verwerk de events
        glfwPollEvents();
    }

    // Sluit de window en maak alles schoon
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

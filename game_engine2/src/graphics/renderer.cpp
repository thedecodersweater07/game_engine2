#include "renderer.h"
#include <iostream>

Renderer::Renderer() {
    std::cout << "Renderer initialized." << std::endl;
}

void Renderer::initialize() {
    std::cout << "Setting up rendering pipeline." << std::endl;
}

void Renderer::render_scene() {
    std::cout << "Rendering 3D scene..." << std::endl;
    skybox.render();
}

void Renderer::render_ui() {
    std::cout << "Rendering UI..." << std::endl;
}

#include "engine.h"
#include <iostream>
#include <thread>
#include <chrono>

Engine::Engine() {
    std::cout << "Engine initialized." << std::endl;
    is_running = true;
}

void Engine::initialize() {
    asset_store.load_assets();
    renderer.initialize();
    ui_manager.setup_ui();
    event_manager.register_events();
    std::cout << "Engine fully initialized." << std::endl;
}

void Engine::start() {
    std::cout << "Starting main game loop." << std::endl;
    while (is_running) {
        auto start_time = std::chrono::high_resolution_clock::now();
        update();
        render();
        handle_input();
        auto end_time = std::chrono::high_resolution_clock::now();
        std::this_thread::sleep_for(std::chrono::milliseconds(16) - (end_time - start_time)); // 60 FPS cap
    }
}

void Engine::update() {
    event_manager.process_events();
    animation_manager.update_animations();
    vfx_manager.update_effects();
    std::cout << "Game updated." << std::endl;
}

void Engine::render() {
    renderer.render_scene();
    renderer.render_ui();
}

void Engine::handle_input() {
    input_manager.poll_input();
}

void Engine::stop() {
    is_running = false;
    std::cout << "Engine stopped." << std::endl;
}

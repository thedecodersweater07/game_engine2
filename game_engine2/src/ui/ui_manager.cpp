#include "ui_manager.h"
#include <iostream>

UIManager::UIManager() {
    std::cout << "UI Manager initialized." << std::endl;
}

void UIManager::setup_ui() {
    toolbar.add_button(Button("Start"));
    toolbar.add_button(Button("Exit"));
    std::cout << "UI setup complete." << std::endl;
}

void UIManager::show_ui() {
    toolbar.render();
}

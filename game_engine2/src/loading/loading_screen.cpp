#include "loading_screen.h"
#include <iostream>
#include <thread>
#include <chrono>

void LoadingScreen::show() {
    std::cout << "Loading... [";
    for (int i = 0; i < 10; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        std::cout << "=";
    }
    std::cout << "] Done!" << std::endl;
}

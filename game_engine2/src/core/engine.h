#ifndef ENGINE_H
#define ENGINE_H

#include "asset_store.h"
#include "renderer.h"
#include "ui_manager.h"
#include "event_manager.h"
#include "input_manager.h"
#include "animation_manager.h"
#include "vfx_manager.h"

class Engine {
public:
    Engine();
    void initialize();
    void start();
    void update();
    void render();
    void handle_input();
    void stop();

private:
    bool is_running;
    AssetStore asset_store;
    Renderer renderer;
    UIManager ui_manager;
    EventManager event_manager;
    InputManager input_manager;
    AnimationManager animation_manager;
    VFXManager vfx_manager;
};

#endif

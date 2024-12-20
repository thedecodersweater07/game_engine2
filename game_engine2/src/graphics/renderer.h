#ifndef RENDERER_H
#define RENDERER_H

#include "skybox.h"

class Renderer {
public:
    Renderer();
    void initialize();
    void render_scene();
    void render_ui();

private:
    void load_shaders();
    void setup_skybox();

    Skybox skybox;
};

#endif

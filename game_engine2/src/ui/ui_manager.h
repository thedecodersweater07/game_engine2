#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include "toolbar.h"

class UIManager {
public:
    UIManager();
    void setup_ui();
    void show_ui();

private:
    Toolbar toolbar;
};

#endif

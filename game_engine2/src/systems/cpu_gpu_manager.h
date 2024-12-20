#ifndef CPU_GPU_MANAGER_H
#define CPU_GPU_MANAGER_H

#include <GLFW/glfw3.h>

class CPU_GPU_Manager {
public:
    CPU_GPU_Manager();
    ~CPU_GPU_Manager();

    void optimizeCPUUsage();
    void optimizeGPUUsage();
    void monitorPerformance();

private:
    float cpuUsage;
    float gpuUsage;
};

#endif // CPU_GPU_MANAGER_H

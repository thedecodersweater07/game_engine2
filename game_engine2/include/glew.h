#ifndef GLEW_H
#define GLEW_H

// GLEW 2.2.0 header file, contains declarations for OpenGL extensions

#ifdef __cplusplus
extern "C" {
#endif

// Initialization functions
GLboolean glewInit(void);
GLboolean glewIsSupported(const char* name);

// OpenGL functions
#define glGenBuffers(...) (void)0
#define glBindBuffer(...) (void)0

#ifdef __cplusplus
}
#endif

#endif // GLEW_H

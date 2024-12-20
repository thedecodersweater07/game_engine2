#ifndef STB_IMAGE_H
#define STB_IMAGE_H

// stb_image.h header file, used for loading image files

#define STB_IMAGE_IMPLEMENTATION
#include <stdlib.h>
#include <stdio.h>

extern "C" {
    unsigned char* stbi_load(const char* filename, int* width, int* height, int* channels_in_file, int desired_channels);
    void stbi_image_free(void* retval_from_stbi_load);
}
#endif // STB_IMAGE_H

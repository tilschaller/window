#pragma once

#include <iostream>
#include <vector>

#include "../deps/glad/include/glad/glad.h"
#include <glm/glm.hpp>

#include "../deps/stb_image/stb_image.h"

#include "shader.hpp"

class Terrain
{
  public:
    const unsigned int NUM_PATCH_PTS = 4;
    unsigned int terrainVAO, terrainVBO;
    unsigned int rez;

    Terrain(const char *location, Shader *shader);
    ~Terrain();
};

#pragma once

#include <iostream>
#include <vector>

#include "../deps/glad/include/glad/glad.h"
#include <glm/glm.hpp>

#include "../deps/stb_image/stb_image.h"

class Terrain
{
  public:
    unsigned int terrainVAO, terrainVBO, terrainIBO;
    int numStrips, numTrisPerStrip;

    Terrain(const char *);
    ~Terrain();
};

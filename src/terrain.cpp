#include <vector>

#include "../glad/include/glad/glad.h"
#include <glm/glm.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include "../stb_image.h"

class Terrain
{
  public:
    GLuint load_heightmap(const char *location)
    {
        std::vector<float> vertices;
        std::vector<unsigned int> indices;
        float yScale = 64.0f / 256.0f, yShift = 16.0f;

        int width, height, nChannels;
        unsigned char *data = stbi_load("resources/heightmaps/iceland_heightmap.png", &width, &height, &nChannels, 0);

        for (unsigned int i = 0; i < height; i++)
        {
            for (unsigned int j = 0; j < width; j++)
            {
                // retrieve texel for (i,j) tex coord
                unsigned char *texel = data + (j + width * i) * nChannels;
                // raw height at coordinate
                unsigned char y = texel[0];

                // vertex
                vertices.push_back(-height / 2.0f + i);       // v.x
                vertices.push_back((int)y * yScale - yShift); // v.y
                vertices.push_back(-width / 2.0f + j / 2.0f); // v.z
            }
        }
        stbi_image_free(data);

        for (unsigned int i = 0; i < height - 1; i++) // for each row a.k.a. each strip
        {
            for (unsigned int j = 0; j < width; j++) // for each column
            {
                for (unsigned int k = 0; k < 2; k++) // for each side of the strip
                {
                    indices.push_back(j + width * (i + k));
                }
            }
        }

        // register VAO
        GLuint terrainVAO, terrainVBO, terrainEBO;
        glGenVertexArrays(1, &terrainVAO);
        glBindVertexArray(terrainVAO);

        glGenBuffers(1, &terrainVBO);
        glBindBuffer(GL_ARRAY_BUFFER, terrainVBO);
        glBufferData(GL_ARRAY_BUFFER,
                     vertices.size() * sizeof(float), // size of vertices buffer
                     &vertices[0],                    // pointer to first element
                     GL_STATIC_DRAW);

        // position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);
        glEnableVertexAttribArray(0);

        glGenBuffers(1, &terrainEBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, terrainEBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                     indices.size() * sizeof(unsigned int), // size of indices buffer
                     &indices[0],                           // pointer to first element
                     GL_STATIC_DRAW);
        return terrainVAO;
    }
};


#include <SDL2/SDL.h>

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <iostream>

#include <window.hpp>

#include <vector>

SDL_Window* window;

int main(int argc, char ** argv){
    Window window(800, 600, "world");

    std::vector<float> vertices;
    int width = 1800; int height = 1800;
    for (unsigned int i = 0; i < height; i++){
        for (unsigned int j = 0; j < width; j++){

            vertices.push_back(-height/2.0f + i);
            vertices.push_back(rand() % 20);
            vertices.push_back(-width/2.0f + j);
        }
    }

    //Generate indicies
    std::vector<unsigned int> indicies;
    for (unsigned int i = 0; i < height-1; i++){
        for (unsigned int j = 0; j < width; j++){
            for (unsigned int k = 0; k < 2; k++){
                indicies.push_back(j + width * (i + k));
            }
        }
    }

    const unsigned int NUM_STRIPS = height-1;
    const unsigned int NUM_VERTS_PER_STRIP = width*2;

    unsigned int VAO, VBO, EBO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);

    //Position attrib
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicies.size() * sizeof(unsigned int), &indicies[0], GL_STATIC_DRAW);

    while (window.getState()){
        glClearColor(0.3f, 0.4f, 0.4f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        SDL_GL_SwapWindow(window.getWindow());
        window.update();
    }
    SDL_Quit();
    std::cout << "Quiting Application" << std::endl;
    return 0;
}
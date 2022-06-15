#include <window.hpp>

#include <glad/glad.h>


Window::Window(int windowWidth, int windowHeight, std::string windowTitle){
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
    }
    //CReate window (OPENgl CONTEXT)
    window = SDL_CreateWindow(windowTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

    //Set context current
    SDL_GL_CreateContext(window);

    //init GLAD
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)){
    }



    w_width = windowWidth; w_height = windowHeight;

    LAST = 0; NOW = SDL_GetPerformanceFrequency();
    deltaTime = 0;
    wState = true;

}

void Window::update(){
    //update deltaTime
    LAST = NOW;
    NOW = SDL_GetPerformanceFrequency();
    deltaTime = (NOW - LAST)/SDL_GetPerformanceCounter();

    while (SDL_PollEvent(&event)){

        if (event.type == SDL_QUIT){
            wState = false;
        }

        if (event.type == SDL_KEYDOWN){
            if (event.key.keysym.sym == SDLK_ESCAPE){
                wState = false;
            }
        }

        if (event.type == SDL_WINDOWEVENT){
            if (event.window.type == SDL_WINDOWEVENT_RESIZED){
                SDL_GetWindowSize(window, &w_width, &w_height);
                glViewport(0, 0, w_width, w_height);
            }
        }
    }
}

SDL_Window* Window::getWindow(){
    return window;
}

bool Window::getState(){
    return wState;
}
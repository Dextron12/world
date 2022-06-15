
#pragma once

#include <SDL2\SDL.h>
#include <string>

class Window{
    private:
        SDL_Window* window;
        SDL_Event event;
        int w_width, w_height;
        bool wState = false;


        //Timings
        double NOW, LAST; // Now is initailized when class is constructed.
        float deltaTime = 0;

    public:
        Window(int windowWidth, int windowHeight, std::string windowTitle);

        void update();


        //Getters
        SDL_Window* getWindow();

        bool getState();



};
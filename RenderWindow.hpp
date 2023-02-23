#ifndef RENDER_WINDOW_
#define RENDER_WINDOW_



#pragma once
#include <SDL.h>
#include<SDL_image.h>
#include<iostream>
#include "Entity.hpp"
using namespace std;
class RenderWindow
{
public:
    RenderWindow(const char* p_title,int p_w,int p_h);
    SDL_Texture* loadTexture(const char* file_path);
    void clear();
    void render(SDL_Texture* tex);



    void display();
    void cleanUp();
    SDL_Window* window;
    SDL_Renderer* renderer;
private:

};
#endif // RENDER_WINDOW_


#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "RenderWindow.hpp"
#include "Entity.hpp"
using namespace std;




int main(int argc,char* argv[])
{
    if(SDL_Init(SDL_INIT_EVERYTHING) > 0)
    {
        cout<< "Hey...SDL_INIT has failed!: "<<SDL_GetError() <<endl;
    }
    if( !IMG_Init(IMG_INIT_PNG) )
    {
        cout<< "Hey...IMG_INIT has failed!" << SDL_GetError() <<endl;
    }

    SDL_Event event;

    RenderWindow window("game v1.0",1280,600);

    SDL_Texture* background = window.loadTexture("resources/bkground.png");
    SDL_Texture* image =window.loadTexture("resources/miniita1-PhotoRoom.png");
    Entity plane;
    plane.tex=image;

    plane.posX=100;
    plane.posY=400;
    bool gameRunning=true;
    while(gameRunning)
    {

        SDL_RenderClear(window.renderer);
        window.render(background);
        while( SDL_PollEvent( &event ) != 0 )
        {

        //User requests quit
					if( event.type == SDL_QUIT )
					{
						gameRunning=false;
					}

					//Handle input for the dot
					plane.handleEvent(event);
        }

        plane.move();




        plane.render(plane.tex,window.renderer);

        window.display();
        window.clear();
    }


    window.cleanUp();
    return 0;
}

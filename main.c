#include <stdio.h>
#include <stdlib.h>

#include "SDL2/SDL.h"

int nav(int x_position, int y_position, int x_limit, int y_limit)
{

    for (int i = x_position; i <= x_limit; ++i)
    {
        return(i);
    }
    return x_position;
    
}

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) == 0) 
    {
        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;

        int resolutionL = 640;
        int resolutionH = 480;

        if (SDL_CreateWindowAndRenderer(resolutionL, resolutionH, 0, &window, &renderer) == 0) 
        {
            SDL_bool done = SDL_FALSE;

            int x = 300, y = 200, i = 0, j = 0;

            while (!done) 
            {
                SDL_Event event;

                SDL_SetRenderDrawColor(renderer, 0, 0, 20, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(renderer);

                SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

                SDL_RenderDrawLine(renderer, 10, 10, 10, (resolutionH - 10));
                SDL_RenderDrawLine(renderer, 10, 10, (resolutionL - 10), 10);
                SDL_RenderDrawLine(renderer, (resolutionL - 10), 10, (resolutionL - 10), (resolutionH - 10));
                SDL_RenderDrawLine(renderer, 10, (resolutionH - 10), (resolutionL - 10), (resolutionH - 10));

                SDL_RenderDrawPoint(renderer, x, y);
                SDL_RenderPresent(renderer);


                
                x = nav(x, y, (resolutionL - 20), (resolutionH - 20));
                //y = nav(x, y, (resolutionL - 20), (resolutionH - 20));

                SDL_Delay(20);

                while (SDL_PollEvent(&event)) 
                {
                    if (event.type == SDL_QUIT) 
                    {
                        done = SDL_TRUE;
                    }
                }
            }
        }

        if (renderer) {
            SDL_DestroyRenderer(renderer);
        }
        if (window) {
            SDL_DestroyWindow(window);
        }
    }
    SDL_Quit();
    return 0;
}

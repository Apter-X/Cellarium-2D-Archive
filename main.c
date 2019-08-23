#include <stdio.h>
#include <stdlib.h>

#include "SDL2/SDL.h"
#include "header/main.h"

int nav(int position, int limit, char c)
{
    for (int i = position; i < limit; i++)
    {
        printf("Incrementation %c\n", c);
        printf("i = %d\n", i);
        return(++position);
    }
    return (20);
}

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) == 0) 
    {
        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;

        int resolutionL = 640;
        int resolutionH = 480;

        int x_limit = resolutionL - 20;
        int y_limit = resolutionH - 20;

        int x_matrix[x_limit];
        int y_matrix[y_limit];

        if (SDL_CreateWindowAndRenderer(resolutionL, resolutionH, 0, &window, &renderer) == 0) 
        {
            SDL_bool done = SDL_FALSE;

            int x = 300, y = 200, i = 0, j = 0;
            char a = 'x', b = 'y';

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
                
                x = nav(x, x_limit, a);
                y = nav(y, y_limit, b);

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

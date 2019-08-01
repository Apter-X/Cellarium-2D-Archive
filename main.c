#include "SDL2/SDL.h"

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) == 0) 
    {
        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;

        if (SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer) == 0) 
        {
            SDL_bool done = SDL_FALSE;

            int x = 300;
            int y = 240;
            int x_plimit = 620;
            int y_plimit = 460;
            int x_nlimit = 20;
            int y_nlimit = 20;

            while (!done) 
            {
                SDL_Event event;

                SDL_SetRenderDrawColor(renderer, 0, 0, 20, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(renderer);

                SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
                SDL_RenderDrawPoint(renderer, x, y);
                SDL_RenderPresent(renderer);
                
                SDL_Delay(20);
                if(x != x_plimit && y != y_plimit)
                {
                    printf("right\n");
                    x++;
                }
                else if(x == x_plimit && y != y_plimit)
                {
                    printf("down\n");
                    y++;
                }
                else if (y == y_plimit && x != x_nlimit)
                {
                    printf("left\n");
                    x--;
                }
                else if (x == x_nlimit && y != 0)
                {
                    printf("up\n");
                    y--;
                }
                

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

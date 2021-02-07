#include <SDL.h>

#include <stdio.h>
#include <stdbool.h>


#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480


static bool G_running = false;


int
main (int argc, char *argv[])
{
    if (SDL_Init (SDL_INIT_VIDEO) == 0)
    {
        SDL_Window *window = SDL_CreateWindow ("sdl-app",
                                  SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED,
                                  SCREEN_WIDTH,
                                  SCREEN_HEIGHT,
                                  SDL_WINDOW_SHOWN);
        if (window)
        {
            SDL_Renderer *renderer = SDL_CreateRenderer (window, -1, SDL_RENDERER_ACCELERATED);
            if (renderer)
            {
                SDL_SetRenderDrawColor (renderer, 0x33, 0x33, 0x33, 0xFF);

                G_running = true;
                while (G_running)
                {
                    SDL_Event event;
                    while (SDL_PollEvent(&event) != 0)
                    {
                        switch (event.type)
                        {
                            case SDL_QUIT:
                            {
                                G_running = false;
                                SDL_Log ("quit received");
                            } break;
                            case SDL_KEYDOWN:
                            {
                                SDL_Log ("keydown");
                            } break;
                            case SDL_MOUSEBUTTONDOWN:
                            case SDL_MOUSEBUTTONUP:
                            case SDL_MOUSEMOTION:
                            {

                            } break;
                            case SDL_TEXTINPUT:
                            {
                                SDL_Log("TEXTINPUT event received");
                            } break;
                            case SDL_TEXTEDITING:
                            {
                                SDL_Log("TEXTEDITING event received");
                            } break;
                        }
                    }
                }
                SDL_DestroyRenderer (renderer);
            }
            else
            {
                printf ("failed to create renderer\n");
            }
            SDL_DestroyWindow (window);
        }
        else
        {
            printf ("failed create window\n");
        }
        SDL_Quit ();
    }
    else
    {
        printf ("failed to init SDL\n");
    }

    return 0;
}
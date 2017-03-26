#ifndef _DEMO_H_
#define _DEMO_H_

#include <SDL2/SDL.h>

typedef struct SDL_Instance
{
  SDL_Window *window;
  SDL_Renderer *renderer;
} SDL_Instance;

int init_instance(SDL_Instance *);
#endif

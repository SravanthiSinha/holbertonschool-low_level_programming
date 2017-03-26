#ifndef _HEADER_H_
#define _HEADER_H_

#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define WINDOW_WIDTH 1260
#define WINDOW_HEIGHT 720
#define row 8
#define col 8
#define inclination 0.7
#define ISOX(x,y)  inclination * x - inclination * y
#define ISOY(x,y,z)  (1-inclination) * x + (1-inclination) * y - z

#define WIDTH  60
#define LEFT_OFFSET 630
#define TOP_OFFSET 360

typedef struct SDL_Instance
{
  SDL_Window *window;
  SDL_Renderer *renderer;
} SDL_Instance;

int init_instance(SDL_Instance *);
void draw_grid(SDL_Instance instance,int **altitudes,int __attribute__((unused)) angle);
  
int **getAltitudes(FILE *file);

void print_grid(int **grid, int x, int y);
int **alloc_grid(int x, int y);
void free_grid(int **grid, int h);

#endif

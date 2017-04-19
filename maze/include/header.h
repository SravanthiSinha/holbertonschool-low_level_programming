#ifndef _HEADER_H_
#define _HEADER_H_

#include <SDL2/SDL.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PI M_PI

/* Defining PROJECTION ATTRIBUTES */
#define TILE_SIZE 128
#define WALL_HEIGHT 128
#define PROJECTIONPLANEWIDTH 640
#define PROJECTIONPLANEHEIGHT 400
#define ANGLE60 PROJECTIONPLANEWIDTH
#define ANGLE30 (ANGLE60 / 2)
#define ANGLE15 (ANGLE30 / 2)
#define ANGLE90 (ANGLE30 * 3)
#define ANGLE180 (ANGLE90 * 2)
#define ANGLE270 (ANGLE90 * 3)
#define ANGLE360 (ANGLE60 * 6)
#define ANGLE0 0
#define ANGLE5 (ANGLE30 / 6)
#define ANGLE10 (ANGLE5 * 2)

/**
 * struct SDL_Instance - fetches both the window instance and the renderer
 * @window: The window to be created
 * @renderer: rendering context
 *
 * Defines Window and context to be rendered
 */
typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;

/* main.c */
int init_instance(SDL_Instance *);

char **getMap(FILE *file, int *row, int *col);

/* grid.c */
void print_grid(char **grid, int x, int y);
char **alloc_grid(int x, int y);
void free_grid(char **grid, int h);

#endif

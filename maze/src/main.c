#include "header.h"

int poll_events(void)
 {
  SDL_Event event;
  SDL_KeyboardEvent key;

  while (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
    case SDL_QUIT:
      return (1);
    case SDL_KEYDOWN:
      key = event.key;
      if (key.keysym.scancode == 0x29)
	return (1);
      break;
    }
  }
  return (0);
}

int getCameraAngle(void)
{
  int angle;
  printf("Choose the options from 1 to 10 for angle of the camera:\n");
  printf("1:ANGLE0\n");
  printf("2:ANGLE5\n");
  printf("3:ANGLE10\n");
  printf("4:ANGLE15\n");
  printf("5:ANGLE30\n");
  printf("6:ANGLE60\n");
  printf("7:ANGLE90\n");
  printf("8:ANGLE180\n");
  printf("9:ANGLE270\n");
  printf("10:ANGLE360\n");
  scanf("%d", &angle);
  switch (angle)
  {
  case 1:
    return (ANGLE0);
  case 2:
    return (ANGLE5);
  case 3:
    return (ANGLE10);
  case 4:
    return (ANGLE15);
  case 5:
    return (ANGLE30);
  case 6:
    return (ANGLE60);
  case 7:
    return (ANGLE90);
  case 8:
    return (ANGLE180);
  case 9:
    return (ANGLE270);
  case 10:
    return (ANGLE360);
  }
  return (ANGLE0);
}

int init_instance(SDL_Instance *instance)
{
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
  {
    fprintf(stderr, "Unable to intialize SDL: %s\n", SDL_GetError());
    return (1);
  }

  instance->window = SDL_CreateWindow("AMAZ_ING \\o/", SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED, PROJECTIONPLANEWIDTH, PROJECTIONPLANEHEIGHT, 0);

  if (instance->window == NULL)
  {
    fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
    SDL_Quit();
    return (1);
  }

  instance->renderer = SDL_CreateRenderer(instance->window, -1,
  SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if (instance->renderer == NULL)
   {
    SDL_DestroyWindow(instance->window);
    fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
    SDL_Quit();
    return (1);
  }
  return (0);
}

int start(SDL_Instance instance, char **fMap, int row, int col)
{
  int angle;
  angle = getCameraAngle();

  if (init_instance(&instance) != 0)
    return (1);
  while (1)
   {
    SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
    SDL_RenderClear(instance.renderer);
    if (poll_events() == 1)
      break;
    draw_maze(instance, angle, fMap, row, col);
    SDL_RenderPresent(instance.renderer);
  }
  SDL_DestroyRenderer(instance.renderer);
  SDL_DestroyWindow(instance.window);
  SDL_Quit();
  return (0);
}

int main(int argc, char *argv[])
{
  SDL_Instance instance;
  FILE *file;
  char **fMap;
  int *row, *col;
  int i;

  i = 0;
  row = &i;
  col = &i;
  if (argc > 1)
  {
    file = fopen(argv[1], "r");
    fMap = getMap(file, row, col);
    createTrignometricTables();
    start(instance, fMap, *row, *col);
    free_grid(fMap, *row);
    fclose(file);
  }
  else
    printf("Enter a valid Input File.\n");
  return (1);
}
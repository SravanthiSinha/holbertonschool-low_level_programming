#include "header.h"
#include "tables.h"
#include "maze.h"

int poll_events(Player *player, Tables t)
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
	if (key.keysym.sym == SDLK_LEFT)
	  player->fPlayerArc -= 5;
	if (key.keysym.sym == SDLK_RIGHT)
	  player->fPlayerArc += 5;
	if (key.keysym.sym == SDLK_UP || key.keysym.sym == SDLK_w)
	  move(player, t, 'w');
	if (key.keysym.sym == SDL_KEYDOWN || key.keysym.sym == SDLK_s)
	  move(player, t, 's');
	if (key.keysym.sym == SDLK_a)
	  orient(player, 'a');
	if (key.keysym.sym == SDLK_d)
	  orient(player, 'd');
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

int start(SDL_Instance instance, char **fMap, Map map, Tables tables)
{
  int i;
  int *angle;
  Player player;

  i = 0;
  angle = &i;

  *angle = getCameraAngle();
  if (init_instance(&instance) != 0)
    return (1);
  init_player(&player, tables, *angle);
  while (1)
   {
    SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
    SDL_RenderClear(instance.renderer);
    if (poll_events(&player, tables) == 1)
      break;
    draw(instance, fMap, map, tables, player);
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
  Tables tables;
  Map map;
  FILE *file;
  char **fMap;

  int *row, *col;
  int i, j;

  i = 0, j = 0;
  row = &i;
  col = &j;
  if (argc > 1)
  {
    file = fopen(argv[1], "r");
    fMap = getMap(file, row, col);
    map.MAP_WIDTH = *row;
    map.MAP_HEIGHT = *col;
    createTrignometricTables(&tables);
    start(instance, fMap, map, tables);
    free_grid(fMap, *row);
    fclose(file);
  }
  else
    printf("Enter a valid Input File.\n");
  return (1);
}

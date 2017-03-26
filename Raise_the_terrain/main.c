#include "header.h"
int angle;
int poll_events()
{
  SDL_Event event;
  SDL_KeyboardEvent key;

  while(SDL_PollEvent(&event))
    {
      switch(event.type)
	{
	case SDL_QUIT:
	  return (1);
	case SDL_KEYDOWN:
	  key = event.key;
	  if(key.keysym.scancode == 0x29)
	    return (1);
	  if(key.keysym.sym == SDLK_LEFT)
	    angle += 1;
	  if(key.keysym.sym == SDLK_RIGHT)
	    angle -= 1;
	  break;
	}
    }
  return (0);
}

int init_instance(SDL_Instance *instance)
{
  if(SDL_Init(SDL_INIT_VIDEO) !=0)
    {
      fprintf(stderr,"Unable to intialize SDL: %s\n",SDL_GetError());
      return (1);
    }
  
  instance->window = SDL_CreateWindow("Raise the terrain \\o/",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WINDOW_WIDTH,WINDOW_HEIGHT,0);

  if(instance->window == NULL)
    {
      fprintf(stderr,"SDL_CreateWindow Error: %s\n",SDL_GetError());
      SDL_Quit();      
      return (1);
    }

  instance->renderer = SDL_CreateRenderer(instance->window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if(instance->renderer == NULL)
    {
      SDL_DestroyWindow(instance->window);
      fprintf(stderr,"SDL_CreateRenderer Error: %s\n",SDL_GetError());
      SDL_Quit();      
      return (1);      
    }
  return (0);  
}

int main(int argc,char *argv[])
{
  SDL_Instance instance;
  FILE *file;
  int **altitudes;      

  angle = 0;
  if(init_instance(&instance) != 0)
    return (1);

  if(argc > 1)
    {
      file = fopen(argv[1], "r");
      altitudes = getAltitudes(file);
      //print_grid(altitudes,row,col);
      while(1)
	{
	  SDL_SetRenderDrawColor(instance.renderer,0,0,0,0);
	  SDL_RenderClear(instance.renderer);
	  if(poll_events() == 1)
	    break;
	  draw_grid(instance,altitudes,angle);
	  SDL_RenderPresent(instance.renderer);
	}
      SDL_DestroyRenderer(instance.renderer);
      SDL_DestroyWindow(instance.window);
      SDL_Quit();      
      free_grid(altitudes,row);
      fclose(file);
    }
  else
    printf("Enter a valid Input File.\n");
  
  return (0);
}

#include "header.h"

void draw_grid(SDL_Instance instance, int **altitudes,int  __attribute__((unused)) Angle)
{
  int i,j;
  float wx,wy,wx1,wy1;
  float a;
  float rx,ry,rx1,ry1;

  SDL_SetRenderDrawColor(instance.renderer,0xFF,0xFF,0xFF,0xFF);
  for(i = 0;i < row;i++)
    {
      for(j = 0; j < row -1;j++)
	{
	  wx = ISOX(j*WIDTH, i*WIDTH);
	  wy = ISOY(j*WIDTH, i*WIDTH, altitudes[i][j]);
	  wx1 = ISOX((j+1)*WIDTH, i*WIDTH);
	  wy1 = ISOY((j+1)*WIDTH, i*WIDTH, altitudes[i][j+1]);
	  if (Angle != 0)
	    {
	      a = Angle * M_PI / 180;
	      rx = wx * cos(a) - wy * sin(a);
	      ry = wx * sin(a) + wy * cos(a);
	      rx1 = wx1 * cos(a) - wy1 * sin(a);
	      ry1 = wx1 * sin(a) + wy1 * cos(a);
	      SDL_RenderDrawLine(instance.renderer, rx+LEFT_OFFSET, ry+TOP_OFFSET, rx1+LEFT_OFFSET, ry1+TOP_OFFSET);	      
	    }
	  else
	    {
	      SDL_RenderDrawLine(instance.renderer, wx+LEFT_OFFSET, wy+TOP_OFFSET, wx1+LEFT_OFFSET, wy1+TOP_OFFSET);
	    }
	  wx = ISOX(i*WIDTH, j*WIDTH);
	  wy = ISOY(i*WIDTH, j*WIDTH, altitudes[j][i]);
	  wx1 = ISOX(i*WIDTH, (j+1)*WIDTH);
	  wy1 = ISOY(i*WIDTH, (j+1)*WIDTH, altitudes[j+1][i]);
	  if (Angle != 0)
	    {
	      a = Angle * M_PI / 180;
	      rx = wx * cos(a) - wy * sin(a);
	      ry = wx * sin(a) + wy * cos(a);
	      rx1 = wx1 * cos(a) - wy1 * sin(a);
	      ry1 = wx1 * sin(a) + wy1 * cos(a);
	      SDL_RenderDrawLine(instance.renderer, rx+LEFT_OFFSET, ry+TOP_OFFSET, rx1+LEFT_OFFSET, ry1+TOP_OFFSET);	      
	    }
	  else
	    {
	      SDL_RenderDrawLine(instance.renderer, wx+LEFT_OFFSET, wy+TOP_OFFSET, wx1+LEFT_OFFSET, wy1+TOP_OFFSET);
	    }
	}
    }
}

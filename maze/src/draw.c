#include "header.h"
#include "maze.h"
#include "metrics.h"

void draw_Background(SDL_Instance instance)
{
  int r;
  /*sky */
  SDL_SetRenderDrawColor(instance.renderer, 0, 191, 255, 255);
  for (r = 0; r < PROJECTIONPLANEHEIGHT / 2; r += 1)
  {
    SDL_RenderDrawLine(instance.renderer, 0, r, PROJECTIONPLANEWIDTH, r);
  }
  /* ground */
  SDL_SetRenderDrawColor(instance.renderer, 124, 252, 0, 255);
  for (; r < PROJECTIONPLANEHEIGHT; r += 1)
  {
    SDL_RenderDrawLine(instance.renderer, 0, r, PROJECTIONPLANEWIDTH, r);
  }
}

void draw_maze(SDL_Instance instance, int angle, char **fMap, int row, int col)
 {
  /*Defining point of view*/
  fPlayerX = PROJECTIONPLANEWIDTH / 2;
  /*player’s position*/
  fPlayerY = PROJECTIONPLANEHEIGHT / 2;
  /*player’s position*/
  fPlayerArc = angle;
  /**angle that the player is facing to*/
  fPlayerDistanceToTheProjectionPlane =
      PROJECTIONPLANEWIDTH / (fTanTable[ANGLE30] * 2);
  /*Distance to the Projection Plane*/
  fPlayerHeight = PROJECTIONPLANEHEIGHT / 2;
  /*Player / viewer’s height*/

  fPlayerSpeed = 16;
  fProjectionPlaneYCenter = PROJECTIONPLANEHEIGHT / 2;
  MAP_WIDTH = row;
  MAP_HEIGHT = col;
  draw_Background(instance);
  draw_Walls(instance, fMap);
}

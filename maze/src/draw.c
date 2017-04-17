#include "header.h"
#include "tables.h"
#include "maze.h"

void draw_Background(SDL_Instance instance)
{
  int r;
  /*sky */
  SDL_SetRenderDrawColor(instance.renderer, 72, 168, 255, 255);
  for (r = 0; r < PROJECTIONPLANEHEIGHT / 2 ; r += 1)
  {
    SDL_RenderDrawLine(instance.renderer, 0, r, PROJECTIONPLANEWIDTH, r);
  }
  /* ground */
  SDL_SetRenderDrawColor(instance.renderer, 0, 126, 0, 255);
  for (; r < PROJECTIONPLANEHEIGHT; r += 1)
  {
    SDL_RenderDrawLine(instance.renderer, 0, r, PROJECTIONPLANEWIDTH, r);
  }
}

void draw(SDL_Instance instance, int angle, char **fMap, Map map, Tables t)
 {
  Player player;
  /*Defining point of view*/
  player.fPlayerX = PROJECTIONPLANEWIDTH / 2;
  /*player’s position*/
  player.fPlayerY = PROJECTIONPLANEHEIGHT / 2;
  /*player’s position*/
  player.fPlayerArc = angle;
  /*angle that the player is facing to*/
  player.fPlayerDistanceToTheProjectionPlane =
      PROJECTIONPLANEWIDTH / (t.fTanTable[ANGLE30] * 2);
  /*Distance to the Projection Plane*/
  player.fPlayerHeight = PROJECTIONPLANEHEIGHT / 2;
  /*Player / viewer’s height*/

  player.fPlayerSpeed = 16;
  player.fProjectionPlaneYCenter = PROJECTIONPLANEHEIGHT / 2;
  draw_Background(instance);
  draw_Walls(instance, fMap, map, t, player);
}

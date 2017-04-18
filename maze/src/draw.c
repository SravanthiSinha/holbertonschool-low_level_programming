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

void init_player(Player *player, Tables tables, int angle)
{
   /*Defining point of view*/
   player->fPlayerX = PROJECTIONPLANEWIDTH / 2;
   /*player’s position*/
   player->fPlayerY = PROJECTIONPLANEHEIGHT / 2;
   /*player’s position*/
   player->fPlayerArc = angle;
   /*angle that the player is facing to*/
   player->fPlayerDistanceToTheProjectionPlane =
   PROJECTIONPLANEWIDTH / (tables.fTanTable[ANGLE30] * 2);
   /*Distance to the Projection Plane*/
   player->fPlayerHeight = PROJECTIONPLANEHEIGHT / 2;
   /*Player / viewer’s height*/

   player->fPlayerSpeed = 16;
   player->fProjectionPlaneYCenter = PROJECTIONPLANEHEIGHT / 2;
}

void move(Player *player, Tables t, char key, Map map)
{
  float playerXDir = t.fCosTable[player->fPlayerArc];
  float playerYDir = t.fSinTable[player->fPlayerArc];
  int px, py;
  px = player->fPlayerX ;
  py = player->fPlayerY;
  printf("%d %d\n", px, py);
  if (key == 'w')
  {
    if (px < (map.MAP_WIDTH - 2) * TILE_SIZE && py < (map.MAP_WIDTH - 1) * TILE_SIZE)
    {
      player->fPlayerX += (int)(playerXDir * player->fPlayerSpeed);
      player->fPlayerY += (int)(playerYDir * player->fPlayerSpeed);
    }
  }
  if (key == 's')
  {
    if (px > TILE_SIZE  && py > TILE_SIZE)
    {
      player->fPlayerX -= (int)(playerXDir * player->fPlayerSpeed);
      player->fPlayerY -= (int)(playerYDir * player->fPlayerSpeed);
    }
  }
}

void orient(Player *player, char key)
{
  if (key == 'a')
  {
    player->fPlayerArc -= ANGLE10;
    if (player->fPlayerArc < ANGLE0)
    {
      player->fPlayerArc += ANGLE360;
    }
  }
  if (key == 'd')
  {
    player->fPlayerArc += ANGLE10;
    if (player->fPlayerArc < ANGLE0)
    {
      player->fPlayerArc -= ANGLE360;
    }
  }
}
void draw(SDL_Instance instance, char **fMap, Map map, Tables t, Player player)
 {
  draw_Background(instance);
  draw_Walls(instance, fMap, map, t, player);
}

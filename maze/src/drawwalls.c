#include "header.h"
#include "tables.h"
#include "maze.h"

float DistToHGridBeingHit
(char **fMap, int castArc, int HGrid, float xIntersection, int distToNextHGrid, Tables t, Player player, Map map)
{
  int xGridIndex; /* the current cell that the ray is in */
  int yGridIndex;
  float distToHGridBeingHit;
  float distToNextXIntersection;

  distToNextXIntersection = t.fXStepTable[castArc];
  while (1)
  {
    xGridIndex = (int)(xIntersection / TILE_SIZE);
    yGridIndex = (HGrid / TILE_SIZE);
    if ((xGridIndex >= map.MAP_WIDTH) || (yGridIndex >= map.MAP_HEIGHT) ||
    xGridIndex < 0 || yGridIndex < 0)
    {
      distToHGridBeingHit = FLT_MAX;
      break;
    } else if ((fMap[yGridIndex][xGridIndex]) != 'O')
    {
      distToHGridBeingHit = (xIntersection - player.fPlayerX) * t.fICosTable[castArc];
      break;
    } else
    {
      xIntersection += distToNextXIntersection;
      HGrid += distToNextHGrid;
    }
  }
  return (distToHGridBeingHit);
}

float DistToVGridBeingHit
(char **fMap, int castArc, int VGrid, float yIntersection, int distToNextVGrid, Tables t, Player player, Map map)
{
  int xGridIndex; /* the current cell that the ray is in */
  int yGridIndex;
  float distToVGridBeingHit;
  float distToNextYIntersection;

  distToNextYIntersection = t.fYStepTable[castArc];
  while (1)
  {
    xGridIndex = (VGrid / TILE_SIZE);
    yGridIndex = (int)(yIntersection / TILE_SIZE);
    if ((xGridIndex >= map.MAP_WIDTH) || (yGridIndex >= map.MAP_HEIGHT) ||
    xGridIndex < 0 || yGridIndex < 0)
    {
      distToVGridBeingHit = FLT_MAX;
      break;
    } else if ((fMap[yGridIndex][xGridIndex]) != 'O')
    {
      distToVGridBeingHit = (yIntersection - player.fPlayerY) * t.fISinTable[castArc];
      break;
    } else
    {
      yIntersection += distToNextYIntersection;
      VGrid += distToNextVGrid;
    }
  }
  return (distToVGridBeingHit);
}

float getDistToVGridBeingHit(int castArc, char **fMap, Map map, Tables t, Player player)
{
  int VGrid;
  int distToNextVGrid;
  float yIntersection;
  float distToVGridBeingHit;

  if (castArc < ANGLE90 || castArc > ANGLE270)
  {
    VGrid = TILE_SIZE + (player.fPlayerX / TILE_SIZE) * TILE_SIZE;
    distToNextVGrid = TILE_SIZE;
    float ytemp = t.fTanTable[castArc] * (VGrid - player.fPlayerX);
    yIntersection = ytemp + player.fPlayerY;
  } else
  {
    VGrid = (player.fPlayerX / TILE_SIZE) * TILE_SIZE;
    distToNextVGrid = -TILE_SIZE;
    float ytemp = t.fTanTable[castArc] * (VGrid - player.fPlayerX);
    yIntersection = ytemp + player.fPlayerY;
    VGrid--;
  }
  if (castArc == ANGLE90 || castArc == ANGLE270)
  {
    distToVGridBeingHit = 9999999;
  } else
  {
    return (DistToVGridBeingHit(fMap, castArc, VGrid, yIntersection,
    distToNextVGrid, t, player, map));
  }
  return (distToVGridBeingHit);
}

float getDistToHGridBeingHit(int castArc, char **fMap, Map map, Tables t, Player player)
{
  int HGrid; /* horizotal or V coordinate of intersection*/
  int distToNextHGrid;
  float xIntersection;
  float distToHGridBeingHit;

  if (castArc > ANGLE0 && castArc < ANGLE180)
  {
    HGrid = (player.fPlayerY / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
    distToNextHGrid = TILE_SIZE;
    float xtemp = t.fITanTable[castArc] * (HGrid - player.fPlayerY);
    xIntersection = xtemp + player.fPlayerX;
  } else
  {
    HGrid = (player.fPlayerY / TILE_SIZE) * TILE_SIZE;
    distToNextHGrid = -TILE_SIZE;
    float xtemp = t.fITanTable[castArc] * (HGrid - player.fPlayerY);
    xIntersection = xtemp + player.fPlayerX;
    HGrid--;
  }
  if (castArc == ANGLE0 || castArc == ANGLE180)
  {
    distToHGridBeingHit = (float)9999999;
  } else
  {
    return (DistToHGridBeingHit(fMap, castArc, HGrid, xIntersection,
    distToNextHGrid, t, player, map));
  }
  return (distToHGridBeingHit);
}

void draw_Walls(SDL_Instance instance, char **fMap, Map map, Tables t, Player player)
{
  int castArc, castColumn;
  float distToVGridBeingHit;
  float distToHGridBeingHit;
  int projectedWallHeight;
  int topOfWall;
  int bottomOfWall;
  float dist;

  castArc = player.fPlayerArc;
  castArc -= ANGLE30;
  if (castArc < 0)
    castArc = ANGLE360 + castArc;
  for (castColumn = 0; castColumn < PROJECTIONPLANEWIDTH; castColumn++)
  {
    distToHGridBeingHit = getDistToHGridBeingHit(castArc, fMap, map, t, player);
    distToVGridBeingHit = getDistToVGridBeingHit(castArc, fMap, map, t, player);
    if (distToHGridBeingHit < distToVGridBeingHit)
    {
      dist = distToHGridBeingHit;
      SDL_SetRenderDrawColor(instance.renderer, 112, 112, 112, 255);
    } else
    {
      dist = distToVGridBeingHit;
      SDL_SetRenderDrawColor(instance.renderer, 149, 149, 149, 255);
    }
    dist /= t.fFishTable[castColumn];
    projectedWallHeight =
    (int)(WALL_HEIGHT * (float) player.fPlayerDistanceToTheProjectionPlane / dist);
    bottomOfWall = player.fProjectionPlaneYCenter + (int)(projectedWallHeight * 0.5F);
    topOfWall = PROJECTIONPLANEHEIGHT - bottomOfWall;
    if (bottomOfWall >= PROJECTIONPLANEHEIGHT)
      bottomOfWall = PROJECTIONPLANEHEIGHT - 1;
    SDL_Rect fillRect = {castColumn, topOfWall, 1, projectedWallHeight};
    SDL_RenderFillRect(instance.renderer, &fillRect);
    castArc += 1;
    if (castArc >= ANGLE360)
      castArc -= ANGLE360;
  }
}

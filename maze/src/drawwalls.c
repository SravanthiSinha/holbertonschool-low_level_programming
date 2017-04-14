#include "header.h"
#include "maze.h"
#include "metrics.h"

float DistToHGridBeingHit
(char **fMap, int castArc, int HGrid, float xIntersection, int distToNextHGrid)
{
  int xGridIndex; /* the current cell that the ray is in */
  int yGridIndex;
  float distToHGridBeingHit;
  float distToNextXIntersection;

  distToNextXIntersection = fXStepTable[castArc];
  while (1)
  {
    xGridIndex = (int)(xIntersection / TILE_SIZE);
    yGridIndex = (HGrid / TILE_SIZE);
    if ((xGridIndex >= MAP_WIDTH) || (yGridIndex >= MAP_HEIGHT) ||
    xGridIndex < 0 || yGridIndex < 0)
    {
      distToHGridBeingHit = FLT_MAX;
      break;
    } else if ((fMap[yGridIndex][xGridIndex]) != 'O')
    {
      distToHGridBeingHit = (xIntersection - fPlayerX) * fICosTable[castArc];
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
(char **fMap, int castArc, int VGrid, float yIntersection, int distToNextVGrid)
{
  int xGridIndex; /* the current cell that the ray is in */
  int yGridIndex;
  float distToVGridBeingHit;
  float distToNextYIntersection;

  distToNextYIntersection = fYStepTable[castArc];
  while (1)
  {
    xGridIndex = (VGrid / TILE_SIZE);
    yGridIndex = (int)(yIntersection / TILE_SIZE);
    if ((xGridIndex >= MAP_WIDTH) || (yGridIndex >= MAP_HEIGHT) ||
    xGridIndex < 0 || yGridIndex < 0)
    {
      distToVGridBeingHit = FLT_MAX;
      break;
    } else if ((fMap[yGridIndex][xGridIndex]) != 'O')
    {
      distToVGridBeingHit = (yIntersection - fPlayerY) * fISinTable[castArc];
      break;
    } else
    {
      yIntersection += distToNextYIntersection;
      VGrid += distToNextVGrid;
    }
  }
  return (distToVGridBeingHit);
}

float getDistToVGridBeingHit(int castArc, char **fMap)
{
  int VGrid;
  int distToNextVGrid;
  float yIntersection;
  float distToVGridBeingHit;

  if (castArc < ANGLE90 || castArc > ANGLE270)
  {
    VGrid = TILE_SIZE + (fPlayerX / TILE_SIZE) * TILE_SIZE;
    distToNextVGrid = TILE_SIZE;
    float ytemp = fTanTable[castArc] * (VGrid - fPlayerX);
    yIntersection = ytemp + fPlayerY;
  } else
  {
    VGrid = (fPlayerX / TILE_SIZE) * TILE_SIZE;
    distToNextVGrid = -TILE_SIZE;
    float ytemp = fTanTable[castArc] * (VGrid - fPlayerX);
    yIntersection = ytemp + fPlayerY;
    VGrid--;
  }
  if (castArc == ANGLE90 || castArc == ANGLE270)
  {
    distToVGridBeingHit = 9999999;
  } else
  {
    return (DistToVGridBeingHit(fMap, castArc, VGrid, yIntersection,
    distToNextVGrid));
  }
  return (distToVGridBeingHit);
}

float getDistToHGridBeingHit(int castArc, char **fMap)
{
  int HGrid; /* horizotal or V coordinate of intersection*/
  int distToNextHGrid;
  float xIntersection;
  float distToHGridBeingHit;

  if (castArc > ANGLE0 && castArc < ANGLE180)
  {
    HGrid = (fPlayerY / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
    distToNextHGrid = TILE_SIZE;
    float xtemp = fITanTable[castArc] * (HGrid - fPlayerY);
    xIntersection = xtemp + fPlayerX;
  } else
  {
    HGrid = (fPlayerY / TILE_SIZE) * TILE_SIZE;
    distToNextHGrid = -TILE_SIZE;
    float xtemp = fITanTable[castArc] * (HGrid - fPlayerY);
    xIntersection = xtemp + fPlayerX;
    HGrid--;
  }
  if (castArc == ANGLE0 || castArc == ANGLE180)
  {
    distToHGridBeingHit = (float)9999999;
  } else
  {
    return (DistToHGridBeingHit(fMap, castArc, HGrid, xIntersection,
    distToNextHGrid));
  }
  return (distToHGridBeingHit);
}

void draw_Walls(SDL_Instance instance, char **fMap)
{
  int castArc, castColumn;
  float distToVGridBeingHit;
  float distToHGridBeingHit;
  int projectedWallHeight;
  int topOfWall;
  int bottomOfWall;
  float dist;

  castArc = fPlayerArc;
  castArc -= ANGLE30;
  if (castArc < 0)
    castArc = ANGLE360 + castArc;
  for (castColumn = 0; castColumn < PROJECTIONPLANEWIDTH; castColumn++)
  {
    distToHGridBeingHit = getDistToHGridBeingHit(castArc, fMap);
    distToVGridBeingHit = getDistToVGridBeingHit(castArc, fMap);
    if (distToHGridBeingHit < distToVGridBeingHit)
    {
      dist = distToHGridBeingHit;
      SDL_SetRenderDrawColor(instance.renderer, 105, 105, 105, 255);
    } else
    {
      dist = distToVGridBeingHit;
      SDL_SetRenderDrawColor(instance.renderer, 169, 169, 169, 255);
    }
    dist /= fFishTable[castColumn];
    projectedWallHeight =
    (int)(WALL_HEIGHT * (float)fPlayerDistanceToTheProjectionPlane / dist);
    bottomOfWall = fProjectionPlaneYCenter + (int)(projectedWallHeight * 0.5F);
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

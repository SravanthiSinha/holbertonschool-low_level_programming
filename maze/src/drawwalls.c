#include "header.h"
#include "tables.h"
#include "maze.h"

/**
 * HHit - Distance To the Horizonatl Grid Being Hit
 * @w: The user defined map.
 * @c: castArc
 * @HG: Distance to Horizontal Grid.
 * @xI: x intersection
 * @N:distance To Next Horizonatal Grid
 * @t: Stores the trignometric table values.
 * @p: Stores Player's details.
 * @m: Stores the map dimensions.
 * Description: Distance To the Horizonatl Grid Being Hit.
 * Return: Distance To the Horizonatl Grid Being Hit
 */
float HHit(char **w, int c, int HG, float xI, int N, Tables t, Player p, Map m)
{
	int xGridIndex; /* the current cell that the ray is in */
	int yGridIndex;
	float distToHGridBeingHit;
	float distToNextXIntersection;

	distToNextXIntersection = t.fXStepTable[c];
	while (1)
	{
		xGridIndex = (int)(xI / TILE_SIZE);
		yGridIndex = (HG / TILE_SIZE);
		if ((xGridIndex >= m.MAP_WIDTH) || (yGridIndex >= m.MAP_HEIGHT)
		    || xGridIndex < 0 || yGridIndex < 0)
		{
			distToHGridBeingHit = FLT_MAX;
			break;
		}
		else if ((w[yGridIndex][xGridIndex]) != 'O')
		{
			distToHGridBeingHit = (xI - p.fPlayerX) * t.fICosTable[c];
			break;
		}
		else
		{
			xI += distToNextXIntersection;
			HG += N;
		}
	}
	return (distToHGridBeingHit);
}

/**
 * VHit - Distance To the Vertical Grid Being Hit
 * @w: The user defined map.
 * @c: castArc
 * @VG: Distance to Vertical Grid.
 * @yI: y intersection
 * @N:distance To Next Vertical Grid
 * @t: Stores the trignometric table values.
 * @p: Stores Player's details.
 * @m: Stores the map dimensions.
 * Description: Distance To the Vertical Grid Being Hit.
 * Return: Distance To the Vertical Grid Being Hit
 */
float VHit(char **w, int c, int VG, float yI, int N, Tables t, Player p, Map m)
{
	int xGridIndex; /* the current cell that the ray is in */
	int yGridIndex;
	float distToVGridBeingHit;
	float distToNextYIntersection;

	distToNextYIntersection = t.fYStepTable[c];
	while (1)
	{
		xGridIndex = (VG / TILE_SIZE);
		yGridIndex = (int)(yI / TILE_SIZE);
		if ((xGridIndex >= m.MAP_WIDTH) || (yGridIndex >= m.MAP_HEIGHT)
		    || xGridIndex < 0 || yGridIndex < 0)
		{
			distToVGridBeingHit = FLT_MAX;
			break;
		}
		else if ((w[yGridIndex][xGridIndex]) != 'O')
		{
			distToVGridBeingHit = (yI - p.fPlayerY) * t.fISinTable[c];
			break;
		}
		else
		{
			yI += distToNextYIntersection;
			VG += N;
		}
	}
	return (distToVGridBeingHit);
}

/**
 * getDistToVGridBeingHit - Distance To the Vertical Grid Being Hit
 * @c: castArc
 * @w: The user defined map.
 * @map: Stores the map dimensions.
 * @t: Stores the trignometric table values.
 * @player: Stores Player's details.
 * Description: Distance To the Vertical Grid Being Hit.
 * Return: Distance To the Vertical Grid Being Hit
 */
float getDistToVGridBeingHit(int c, char **w, Map map, Tables t, Player player)
{
	int VGrid;
	int distToNextVGrid;
	float yI;
	float distToVGridBeingHit;
	float ytemp;

	if (c < ANGLE90 || c > ANGLE270)
	{
		VGrid = TILE_SIZE + (player.fPlayerX / TILE_SIZE) * TILE_SIZE;
		distToNextVGrid = TILE_SIZE;
		ytemp = t.fTanTable[c] * (VGrid - player.fPlayerX);
		yI = ytemp + player.fPlayerY;
	}
	else
	{
		VGrid = (player.fPlayerX / TILE_SIZE) * TILE_SIZE;
		distToNextVGrid = -TILE_SIZE;
		ytemp = t.fTanTable[c] * (VGrid - player.fPlayerX);
		yI = ytemp + player.fPlayerY;
		VGrid--;
	}
	if (c == ANGLE90 || c == ANGLE270)
		distToVGridBeingHit = 9999999;
	else
		return (VHit(w, c, VGrid, yI, distToNextVGrid, t, player, map));
	return (distToVGridBeingHit);
}

/**
 * getDistToHGridBeingHit - Distance To the Horizontal Grid Being Hit
 * @c: castArc
 * @w: The user defined map.
 * @map: Stores the map dimensions.
 * @t: Stores the trignometric table values.
 * @player: Stores Player's details.
 * Description: Distance To the Horizontal Grid Being Hit.
 * Return: Distance To the Horizontal Grid Being Hit
 */
float getDistToHGridBeingHit(int c, char **w, Map map, Tables t, Player player)
{
	int HGrid; /* horizotal or V coordinate of intersection*/
	int distToNextHGrid;
	float xI;
	float distToHGridBeingHit;
	float xtemp;

	if (c > ANGLE0 && c < ANGLE180)
	{
		HGrid = (player.fPlayerY / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
		distToNextHGrid = TILE_SIZE;
		xtemp = t.fITanTable[c] * (HGrid - player.fPlayerY);
		xI = xtemp + player.fPlayerX;
	}
	else
	{
		HGrid = (player.fPlayerY / TILE_SIZE) * TILE_SIZE;
		distToNextHGrid = -TILE_SIZE;
		xtemp = t.fITanTable[c] * (HGrid - player.fPlayerY);
		xI = xtemp + player.fPlayerX;
		HGrid--;
	}
	if (c == ANGLE0 || c == ANGLE180)
		distToHGridBeingHit = (float)9999999;
	else
		return (HHit(w, c, HGrid, xI, distToNextHGrid, t, player, map));
	return (distToHGridBeingHit);
}


/**
 * draw_Walls - Draws the walls
 * @instance: the instance which is used to be rendered.
 * @w: The user defined map.
 * @map: Stores the map dimensions.
 * @t: Stores the trignometric table values.
 * @p: Stores Player's details.
 * Description: Draws the walls
 */
void draw_Walls(SDL_Instance instance, char **w, Map map, Tables t, Player p)
{
	int castArc;
	int castColumn;
	float distToVGridBeingHit;
	float distToHGridBeingHit;
	int pWallHeight;/*projectedWallHeight*/
	int topOfWall;
	int bottomOfWall;
	float dist;
	SDL_Rect fillRect;

	castArc = p.fPlayerArc;
	castArc -= ANGLE30;
	if (castArc < 0)
		castArc = ANGLE360 + castArc;
	for (castColumn = 0; castColumn < PROJECTIONPLANEWIDTH; castColumn++)
	{
		distToHGridBeingHit = getDistToHGridBeingHit(castArc, w, map, t, p);
		distToVGridBeingHit = getDistToVGridBeingHit(castArc, w, map, t, p);
		if (distToHGridBeingHit < distToVGridBeingHit)
		{
			dist = distToHGridBeingHit;
			SDL_SetRenderDrawColor(instance.renderer, 112, 112, 112, 255);
		}
		else
		{
			dist = distToVGridBeingHit;
			SDL_SetRenderDrawColor(instance.renderer, 149, 149, 149, 255);
		}
		dist /= t.fFishTable[castColumn];
		pWallHeight = (int)(WALL_HEIGHT * (float) p.dPP / dist);
		bottomOfWall = p.fProjectionPlaneYCenter + (int)(pWallHeight * 0.5F);
		topOfWall = PROJECTIONPLANEHEIGHT - bottomOfWall;
		if (bottomOfWall >= PROJECTIONPLANEHEIGHT)
			bottomOfWall = PROJECTIONPLANEHEIGHT - 1;
		Init_SDL_Rect(&fillRect, castColumn, topOfWall, 1, pWallHeight);
		SDL_RenderFillRect(instance.renderer, &fillRect);
		castArc += 1;
		if (castArc >= ANGLE360)
			castArc -= ANGLE360;
	}
}

#ifndef _MAZE_H_
#define _MAZE_H_

/**
 * struct Player - Stores players values
 * @fPlayerX: player’s  x position
 * @fPlayerY: player’s  y position
 * @fPlayerArc: angle that the Player / viewer is facing to
 * @dPP: Distance to the Projection Plane
 * @fPlayerHeight: Player / viewer’s height
 * @fPlayerSpeed: Player / viewer’s speed
 * @fProjectionPlaneYCenter: Projection Plane Y Center
 * Stores players values
 */
typedef struct Player
{
	int fPlayerX;
	int fPlayerY;
	int fPlayerArc;
	int dPP; /*fPlayerDistanceToTheProjectionPlane;*/
	int fPlayerHeight;
	int fPlayerSpeed;
	int fProjectionPlaneYCenter;
} Player;

/**
 * struct Map - Stores Map attributes
 * @MAP_WIDTH: width of the map for the game
 * @MAP_HEIGHT: height of the map for the game
 *
 * Stores Map attributes
 */
typedef struct Map
{
	int MAP_WIDTH;
	int MAP_HEIGHT;
} Map;

void init_player(Player *player, Tables tables, int angle);
void draw(SDL_Instance instance, char **w, Map map, Tables tables, Player p);
void move(Player *player, Tables t, char key, Map map);
void orient(Player *player, char key);
void draw_Walls(SDL_Instance instance, char **w, Map map, Tables t, Player p);
float HHit(char **w, int c, int H, float xI, int N, Tables t, Player p, Map m);
float VHit(char **w, int c, int V, float yI, int N, Tables t, Player p, Map m);
float getDistToVGridBeingHit(int c, char **w, Map m, Tables t, Player p);
float getDistToHGridBeingHit(int c, char **w, Map m, Tables t, Player p);
#endif

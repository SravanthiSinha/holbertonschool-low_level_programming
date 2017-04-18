#ifndef _MAZE_H_
#define _MAZE_H_

/* player's attributes */
typedef struct Player
{
int fPlayerX;
int fPlayerY;
int fPlayerArc;
int fPlayerDistanceToTheProjectionPlane;
int fPlayerHeight;
int fPlayerSpeed;
int fProjectionPlaneYCenter;
} Player;

typedef struct Map
{
  int MAP_WIDTH;
  int MAP_HEIGHT;
} Map;

void init_player(Player *player, Tables tables, int angle);
void draw(SDL_Instance instance, char **fMap, Map map, Tables tables, Player p);
void move(Player *player, Tables t, char key);
void orient(Player *player, char key);
void draw_Walls(SDL_Instance instance, char **fMap, Map map, Tables t, Player p);
float DistToHGridBeingHit
(char **fMap, int castArc, int HGrid, float xIntersection, int distToNextHGrid, Tables t, Player player, Map map);
float DistToVGridBeingHit
(char **fMap, int castArc, int VGrid, float yIntersection, int distToNextVGrid, Tables t, Player player, Map map);
float getDistToVGridBeingHit(int castArc, char **fMap, Map map, Tables t, Player player);
float getDistToHGridBeingHit(int castArc, char **fMap, Map map, Tables t, Player player);

#endif

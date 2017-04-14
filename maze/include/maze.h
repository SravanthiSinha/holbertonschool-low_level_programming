/* player's attributes */
int fPlayerX;
int fPlayerY;
int fPlayerArc;
int fPlayerDistanceToTheProjectionPlane;
int fPlayerHeight;
int fPlayerSpeed;
int fProjectionPlaneYCenter;

/* MAP ATTRIBUTES */
int MAP_WIDTH;
int MAP_HEIGHT;

void draw_Walls(SDL_Instance instance, char **fMap);
float getDistToHGridBeingHit(int castArc, char **fMap);
float getDistToVGridBeingHit(int castArc, char **fMap);
float DistToVGridBeingHit
(char **fMap, int castArc, int VGrid, float yIntersection, int distToNextVGrid);
float DistToHGridBeingHit
(char **fMap, int castArc, int HGrid, float xIntersection, int distToNextHGrid);

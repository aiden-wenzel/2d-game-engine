#include <SDL3/SDL.h>

struct Point {
	int x;
	int y;
};

typedef struct Point Point;

// Circle stuff
void plotCirclePoints(SDL_Renderer *renderer, int x, int y, int h, int k);
void renderCircle(SDL_Renderer *renderer, int h, int k, int r);

// Triangle stuff
void renderTriangleFrame();
void renderTriangle();

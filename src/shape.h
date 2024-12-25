#include <SDL3/SDL.h>

typedef struct Vec2 Vec2;

struct Vec2 {
	int x;
	int y;
};

typedef struct Point Point;

// Circle stuff
void plotCirclePoints(SDL_Renderer *renderer, int x, int y, int h, int k);
void renderCircle(SDL_Renderer *renderer, int h, int k, int r);

// Triangle stuff
void renderTriangleFrame(SDL_Renderer* renderer, Vec2 point1, Vec2 point2, Vec2 point3);

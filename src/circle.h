#include <SDL3/SDL.h>

typedef struct Vec2 Vec2;

struct Circle {
	float x;
	float y;
	float radius;
};

typedef struct Point Point;

// Circle stuff
void plotCirclePoints(SDL_Renderer *renderer, int x, int y, int h, int k);
void renderCircle(SDL_Renderer *renderer, int h, int k, int r);

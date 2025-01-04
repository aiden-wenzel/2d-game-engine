#include <SDL3/SDL_render.h>
#include <cglm/cglm.h>
#include <SDL3/SDL.h>

typedef struct GameObject GameObject;

struct GameObject {
	ivec2 position;
	ivec2 velocity;
	SDL_FRect shape;
};

GameObject initializeGameObject(ivec2 initialPos, ivec2 initialVel);

void renderGameObject(GameObject* object, SDL_Renderer* renderer);

void moveGameObject(GameObject* object);

void handleCollision(GameObject* object);

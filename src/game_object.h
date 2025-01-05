#include <SDL3/SDL_render.h>
#include <cglm/cglm.h>
#include <SDL3/SDL.h>

typedef struct GameObject GameObject;

struct GameObject {
	vec2 position;
	vec2 velocity;
	SDL_FRect shape;
};

GameObject initializeGameObject(vec2 initialPos, vec2 initialVel);

void renderGameObject(GameObject* object, SDL_Renderer* renderer);

void moveGameObject(GameObject* object);

void handleEdgeCollision(GameObject* object);

bool detectCollision(GameObject* object1, GameObject* object2);

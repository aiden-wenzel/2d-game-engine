#include <SDL3/SDL_render.h>
#include <cglm/cglm.h>
#include <SDL3/SDL.h>

typedef struct GameObject GameObject;
typedef struct Circle Circle;

struct GameObject {
	vec2 position;
	vec2 velocity;
	SDL_FRect shape;
	float mass;
};

struct Circle {
	float x;
	float y;
	float radius;
}

GameObject initializeGameObject(vec2 initialPos, vec2 initialVel, float mass);

void renderGameObject(GameObject* object, SDL_Renderer* renderer);

void moveGameObject(GameObject* object);

void handleEdgeCollision(GameObject* object);

bool detectCollision(GameObject* object1, GameObject* object2);

void handleCollision(GameObject* object1, GameObject* object2);

void getRectangleCenter(GameObject* object, vec2 objectCenter);

void calculateFinalVelocity(GameObject* object1, GameObject* object2, vec2 dest);

#include <SDL3/SDL_render.h>
#include <cglm/cglm.h>
#include <SDL3/SDL.h>

#include "circle.h"

typedef struct GameObject GameObject;
typedef struct Circle Circle;

struct GameObject {
	vec2 position;
	vec2 velocity;
	Circle shape;
	float mass;
};

GameObject initializeGameObject(vec2 initialPos, vec2 initialVel, float mass, float radius);

void renderGameObject(GameObject* object, SDL_Renderer* renderer);

void moveGameObject(GameObject* object);

void handleEdgeCollision(GameObject* object);

bool detectCollision(GameObject* object1, GameObject* object2);

void handleCollision(GameObject* object1, GameObject* object2);

void getRectangleCenter(GameObject* object, vec2 objectCenter);

void calculateFinalVelocity(GameObject* object1, GameObject* object2, vec2 dest);

void applyGravity(GameObject* object1, float g);

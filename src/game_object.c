#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>
#include <cglm/cglm.h>
#include <stdbool.h>

#include "game_object.h"

extern int WIDTH;
extern int HEIGHT;

GameObject initializeGameObject(ivec2 initialPos, ivec2 initialVel) {
	GameObject newGameObject;

	glm_ivec2_copy(initialPos, newGameObject.position);
	glm_ivec2_copy(initialVel, newGameObject.velocity);

	SDL_FRect objectShape;
	objectShape.x = initialPos[0];
	objectShape.y = initialPos[1];
	objectShape.h = 5;
	objectShape.w = 5;

	newGameObject.shape = objectShape;

	return newGameObject;
}

void renderGameObject(GameObject* object, SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
	SDL_RenderRect(renderer, &object->shape);
}

void moveGameObject(GameObject* object) {
	object->position[0] += object->velocity[0];
	object->position[1] += object->velocity[1];

	object->shape.x = object->position[0];
	object->shape.y = object->position[1];
}

void handleCollision(GameObject* object) {
	bool collideLeft = object->position[0] == 0;	
	bool collideTop = object->position[1] == 0;
	bool collideRight = object->position[0] + object->shape.w == WIDTH;
	bool collideBottom = object->position[1] + object->shape.h == HEIGHT;

	if (collideTop || collideBottom || collideRight || collideLeft) {
		object->velocity[0] = 0;
		object->velocity[1] = 0;
	}
}

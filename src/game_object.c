#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>
#include <cglm/cglm.h>
#include <cglm/vec2-ext.h>
#include <stdbool.h>

#include "game_object.h"

extern int WIDTH;
extern int HEIGHT;

GameObject initializeGameObject(vec2 initialPos, vec2 initialVel) {
	GameObject newGameObject;

	glm_vec2_copy(initialPos, newGameObject.position);
	glm_vec2_copy(initialVel, newGameObject.velocity);

	SDL_FRect objectShape;
	objectShape.x = initialPos[0];
	objectShape.y = initialPos[1];
	objectShape.h = 100;
	objectShape.w = 100;

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

void handleEdgeCollision(GameObject* object) {
	bool collideLeft = object->position[0] <= 0;	
	bool collideTop = object->position[1] <= 0;
	bool collideRight = object->position[0] + object->shape.w >= WIDTH;
	bool collideBottom = object->position[1] + object->shape.h >= HEIGHT;

	if (collideTop || collideBottom ) {
		object->velocity[1] *= -1;
	}
	else if(collideRight || collideLeft) {
		object->velocity[0] *= -1;
	}
}

bool detectCollision(GameObject* object1, GameObject* object2) {
	if (glm_vec2_distance(object1->position, object2->position) < object1->shape.w) {
		return true;
	}
	else {
		return false;
	}
}

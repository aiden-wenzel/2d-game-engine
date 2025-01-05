#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>
#include <cglm/cglm.h>
#include <cglm/vec2-ext.h>
#include <cglm/vec2.h>
#include <stdbool.h>

#include "game_object.h"

extern int WIDTH;
extern int HEIGHT;

GameObject initializeGameObject(vec2 initialPos, vec2 initialVel, float mass) {
	GameObject newGameObject;

	glm_vec2_copy(initialPos, newGameObject.position);
	glm_vec2_copy(initialVel, newGameObject.velocity);

	SDL_FRect objectShape;
	objectShape.x = initialPos[0];
	objectShape.y = initialPos[1];
	objectShape.h = 50;
	objectShape.w = 100;

	newGameObject.shape = objectShape;

	newGameObject.mass = mass;

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
	if (
		object1->position[0] < object2->position[0] + object2->shape.w &&
		object1->position[0] + object1->shape.w > object2->position[0] &&
		object1->position[1] < object2->position[1] + object2->shape.h &&
		object1->position[1] + object1->shape.h > object2->position[1]
	) {
		return true;
	}

	else {
		return false;
	}
}

// https://en.wikipedia.org/wiki/Elastic_collision#Two-dimensional
void handleCollision(GameObject* object1, GameObject* object2) {
	
	vec2 object1FinalVel;
	vec2 object2FinalVel;

	calculateFinalVelocity(object1, object2, object1FinalVel);
	calculateFinalVelocity(object2, object1, object2FinalVel);

	glm_vec2_copy(object1FinalVel, object1->velocity);
	glm_vec2_copy(object2FinalVel, object2->velocity);
}

void getRectangleCenter(GameObject* object, vec2 objectCenter) {
	objectCenter[0] = (object->shape.w / 2) + object->position[0];
	objectCenter[1] = object->position[1] - (object->shape.h / 2);
}

void calculateFinalVelocity(GameObject* object1, GameObject* object2, vec2 dest) {
	vec2 object1Center;
	vec2 object2Center;
	getRectangleCenter(object1, object1Center);
	getRectangleCenter(object2, object2Center);

	vec2 velocityDifference;
	vec2 centerDifference;
	glm_vec2_sub(object1->velocity, object2->velocity, velocityDifference);
	glm_vec2_sub(object1Center, object2Center, centerDifference);

	float dotScalar = glm_vec2_dot(velocityDifference, centerDifference) / (glm_vec2_norm(centerDifference) * glm_vec2_norm(centerDifference));
	float massScalar = (2 * object2->mass) / (object1->mass + object2->mass);
	float massDotProd = dotScalar * massScalar;
	
	vec2 finalVelocity;

	vec2 scaledCenterDifference;
	glm_vec2_scale(centerDifference, massDotProd, scaledCenterDifference);	
	glm_vec2_sub(object1->velocity, scaledCenterDifference, finalVelocity);

	glm_vec2_copy(finalVelocity, dest);

}

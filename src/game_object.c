#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>
#include <cglm/cglm.h>
#include <cglm/vec2-ext.h>
#include <cglm/vec2.h>
#include <stdbool.h>

#include "game_object.h"

extern int WIDTH;
extern int HEIGHT;

GameObject initializeGameObject(vec2 initialPos, vec2 initialVel, float mass, float radius) {
	GameObject newGameObject;

	glm_vec2_copy(initialPos, newGameObject.position);
	glm_vec2_copy(initialVel, newGameObject.velocity);

	Circle objectShape;
	objectShape.radius = radius;
	objectShape.x = initialPos[0];
	objectShape.y = initialPos[1];

	newGameObject.shape = objectShape;

	newGameObject.mass = mass;

	return newGameObject;
}

void renderGameObject(GameObject* object, SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
	renderCircle(renderer, object->shape.x, object->shape.y, object->shape.radius);
}

void moveGameObject(GameObject* object) {
	object->position[0] += object->velocity[0];
	object->position[1] += object->velocity[1];

	object->shape.x = object->position[0];
	object->shape.y = object->position[1];
}

void handleEdgeCollision(GameObject* object) {
	bool collideLeft = object->position[0] - object->shape.radius <= 0;	
	bool collideTop = object->position[1] - object->shape.radius<= 0;
	bool collideRight = object->position[0] + object->shape.radius >= WIDTH;
	bool collideBottom = object->position[1] + object->shape.radius >= HEIGHT;

	if (collideTop || collideBottom ) {
		object->velocity[1] *= -1;
	}
	else if(collideRight || collideLeft) {
		object->velocity[0] *= -1;
	}
}

bool detectCollision(GameObject* object1, GameObject* object2) {
	float sumRadi = object1->shape.radius + object2->shape.radius;
	float distance = glm_vec2_distance(object1->position, object2->position);
	return distance < sumRadi;
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

void calculateFinalVelocity(GameObject* object1, GameObject* object2, vec2 dest) {
	vec2 object1Center = {object1->position[0], object1->position[1]};
	vec2 object2Center = {object2->position[0], object2->position[1]};

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

void applyGravity(GameObject* object1, float g) {
	object1->velocity[1] += g;
}

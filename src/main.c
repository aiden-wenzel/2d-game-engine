#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <cglm/cglm.h>
#include <stdio.h>
#include <stdlib.h>

#include "game_object.h"

const int WIDTH = 800;
const int HEIGHT = 600;

SDL_Window* initializeWindow(int width, int height); 
SDL_Renderer* initializeRenderer(SDL_Window* window); 

int main(int argc, char* argv[]) {
	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return -1;
	}
	
	SDL_Window* window = initializeWindow(WIDTH, HEIGHT);

	SDL_Renderer* renderer = initializeRenderer(window);

	// Main loop flag
	int quit = 0;
	SDL_Event event;
	
	ivec2 objectPos = {50, 50};
	ivec2 objectVel = {0, 1};
	GameObject player = initializeGameObject(objectPos, objectVel);

	// Main loop
	while (!quit) {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);

		// Handle events
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_EVENT_QUIT) {
				quit = 1;
			}
		}
		
		renderGameObject(&player, renderer);
		SDL_RenderPresent(renderer);
		moveGameObject(&player);
	}

	// Clean up and close SDL
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}

SDL_Window* initializeWindow(int width, int height) {
	// Create an SDL window
	SDL_Window* window = SDL_CreateWindow("Simple SDL2 Window",
			width, height, 0);
	if (window == NULL) {
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		SDL_Quit();
		exit(-1);
	}
	return window;

}

SDL_Renderer* initializeRenderer(SDL_Window* window) {
	SDL_Renderer* renderer = SDL_CreateRenderer(window, "gpu");

	if (renderer == NULL) {
		printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		SDL_Quit();
		exit(-2);
	}

	return renderer;
}

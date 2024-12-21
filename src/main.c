#include <SDL2/SDL.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return -1;
	}

	// Create an SDL window
	SDL_Window* window = SDL_CreateWindow("Simple SDL2 Window",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			800, 600, SDL_WINDOW_SHOWN);
	if (window == NULL) {
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		SDL_Quit();
		return -1;
	}

	// Main loop flag
	int quit = 0;
	SDL_Event event;

	// Main loop
	while (!quit) {
		// Handle events
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				quit = 1;
			}
		}
	}

	// Clean up and close SDL
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}


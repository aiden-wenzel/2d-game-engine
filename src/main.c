#include <SDL2/SDL.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return 1;
	}

	// Create a window
	SDL_Window* window = SDL_CreateWindow(
			"SDL2 Window",                  // Window title
			SDL_WINDOWPOS_UNDEFINED,        // Initial x position
			SDL_WINDOWPOS_UNDEFINED,        // Initial y position
			640,                            // Width, in pixels
			480,                            // Height, in pixels
			SDL_WINDOW_SHOWN                 // Flags (show the window)
			);

	if (window == NULL) {
		fprintf(stderr, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	}

	// Wait for 5 seconds
	SDL_Delay(5000);

	// Destroy the window
	SDL_DestroyWindow(window);

	// Quit SDL
	SDL_Quit();

	return 0;
}

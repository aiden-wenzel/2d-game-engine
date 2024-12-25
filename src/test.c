#include <SDL3/SDL.h>
#include <stdio.h>

int main() {
	for (int i = 0; i < SDL_GetNumRenderDrivers() - 1; i++) {
		printf("%s\n",SDL_GetRenderDriver(i));	
	}
}

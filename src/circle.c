#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_render.h>

#include "shape.h"

// Implementation of the midpoint circle rendering algorithm.
// https://en.wikipedia.org/wiki/Midpoint_circle_algorithm
void renderCircle(SDL_Renderer *renderer, int h, int k, int r) {
    int x = 0;
    int y = r;
    int p = 1 - r;  // Initial decision parameter

    // Plot the initial point
    plotCirclePoints(renderer, x, y, h, k);

	while (x < y) {
        x++;

        // Update the decision parameter
        if (p < 0) {
            p = p + 2*x + 1;
        } else {
            y--;
            p = p + 2*x - 2*y + 1;
        }

        // Plot the new points
        plotCirclePoints(renderer, x, y, h, k);
    }
}

// Function to plot a point at (x, y) and reflect the point to all octants
void plotCirclePoints(SDL_Renderer *renderer, int x, int y, int h, int k) {
    SDL_RenderPoint(renderer, h + x, k + y);  // Octant 1
    SDL_RenderPoint(renderer, h - x, k + y);  // Octant 2
    SDL_RenderPoint(renderer, h + x, k - y);  // Octant 4
    SDL_RenderPoint(renderer, h - x, k - y);  // Octant 3
    SDL_RenderPoint(renderer, h + y, k + x);  // Octant 5
    SDL_RenderPoint(renderer, h - y, k + x);  // Octant 6
    SDL_RenderPoint(renderer, h + y, k - x);  // Octant 7
    SDL_RenderPoint(renderer, h - y, k - x);  // Octant 8
}

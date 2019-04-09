#include "bouncyballs.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cstdio>

int main(int argc, char** argv) {
	const int FPS = 60, frameDelay = 1000 / FPS;
	unsigned int frameStart, frameTime;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return -1;

	SDL_Window* window = SDL_CreateWindow(
		"Bouncy Balls",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		600,
		400,
		SDL_WINDOW_SHOWN
	);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_Surface* img = IMG_Load("ball.png");
	SDL_Texture* ball = SDL_CreateTextureFromSurface(renderer, img);

	bouncy::Ball balls[10];
	for (int i = 0; i < 10; i++) {
		balls[i].setPos(10 + i * 74, 100);
		balls[i].setTexture(ball);
	}

	SDL_Event event;
	bool running = true;
	while (running) {
		frameStart = SDL_GetTicks();

		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				running = false;
			}
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		for (int j = 0; j < 10; j++) {
			balls[j].update();
			balls[j].draw(renderer);
		}

		SDL_RenderPresent(renderer);

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
			SDL_Delay(frameDelay - frameTime);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

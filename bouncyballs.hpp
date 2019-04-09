#ifndef BOUNCYBALLS
#define BOUNCYBALLS

#include <SDL2/SDL.h>

namespace bouncy {
	class Ball {
	public:
		void setTexture(SDL_Texture* texture);
		void setPos(float x, float y);
		void draw(SDL_Renderer* renderer);
		void update();
	private:
		SDL_Texture* texture = nullptr;
		float x = 0, y = 0;
		float vx = 0, vy = 0;
		float ax = 0, ay = 0.5;
	};
}

#include "bouncyballs.cpp"
#endif

#include "bouncyballs.hpp"

void bouncy::Ball::setTexture(SDL_Texture* texture) {
	this->texture = texture;
}

void bouncy::Ball::setPos(float x, float y) {
	this->x = x;
	this->y = y;
}

void bouncy::Ball::draw(SDL_Renderer* renderer) {
	SDL_Rect rect = {(int) x, (int) y, 64, 64};
	SDL_RenderCopy(renderer, texture, nullptr, &rect);
}

void bouncy::Ball::update() {
	if (y + 64 < 400 || vy < 0) {
		vy += ay;
		y += vy;
	} else {
		vy *= -0.7;
	}
	if (fabs(vy) < 0.1)
		vy = 0;
}

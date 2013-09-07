/*
 * MouseFigure.cpp
 *
 *  Created on: Sep 6, 2013
 *      Author: Alles Rebel
 */

#include "MouseFigure.h"

MouseFigure::MouseFigure(int x, int y, Surface& image, SDL_Surface* screen, Gravity gravityEnabled, bool leader,
		double speed, double gravity, double jumpStrength, int numClips, int levelWidth, int levelHeight,
		Resolves resolve, Surface* p1, Surface* p2, Surface* p3, Surface* p4) :
		Figure(x, y, image, screen, gravityEnabled, leader, speed, gravity, jumpStrength, numClips, levelWidth,
				levelHeight, resolve, p1, p2, p3, p4) {

	this->className = "MouseFigure";
	container = NULL;
}

MouseFigure::~MouseFigure() {
}

bool MouseFigure::checkCollision(CircFigure* other) {
	return false;
}

bool MouseFigure::checkCollision(RectFigure* other) {
	return false;
}

void MouseFigure::handleInput(SDL_Event& event) {
	if (event.type == SDL_MOUSEMOTION) {
		camera->x = p.x = event.motion.x;
		camera->y = p.y = event.motion.y;
	}
	else if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
			case SDLK_UP:

				break;
			case SDLK_DOWN:
				break;

			case SDLK_LEFT:
				break;

			case SDLK_RIGHT:
				break;

			default:
				break;
		}
	}
}

void MouseFigure::setContainer(vector<Figure*>* src) {
	container = src;
}

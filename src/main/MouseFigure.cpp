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
	SDL_GetMouseState(&x, &y);
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
		p.x = event.motion.x;
		p.y = event.motion.y;
	}
	else if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
			case SDLK_1:{
				//get location of mouse currently
				SDL_GetMouseState(&x, &y);

				//add offsets to it based on camera clip
				x += camera->x;
				y += camera->y;

				//load image
				Surface* rect = new Surface("images/rectangle.png");

				//and place the object there
				RectFigure* newFig = new RectFigure(x, y, *rect, screen, Figure::GRAVITY_DISABLED, false, 0, 0, 0, 1, lvlWidth,
						lvlHeight, Figure::BOUNDARY);

				printf("Size of container %d -> ",container->size());

				//and place it into the map
				container->push_back(newFig);

				printf(" %d\n",container->size());

				printf("pushed new object in! at %d %d\n", newFig->getX(),newFig->getY());
				printf("Current mouse location is: %d, %d \n",x,y);

				break;
			}
			case SDLK_2:
				break;

			case SDLK_3:
				break;

			case SDLK_4:
				break;

			default:
				break;
		}
	}
}

void MouseFigure::setContainer(vector<Figure*>* src) {
	container = src;
}

void MouseFigure::setHeightWidth(int h, int w) {
	lvlHeight = h;
	lvlWidth = w;
}

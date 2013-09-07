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
	currentObject = none;
	tempObject = NULL;
}

MouseFigure::~MouseFigure() {
	if (image != NULL) delete image;
	if (p1 != NULL) delete p1;
	if (p2 != NULL) delete p2;
	if (p3 != NULL) delete p3;
	if (p4 != NULL) delete p4;
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

		if (tempObject != NULL) {
			tempObject->setPosition(event.motion.x + camera->x, event.motion.y + camera->y);
		}
	}
	else if (event.type == SDL_MOUSEBUTTONDOWN) {
		switch (event.button.button) {
			case SDL_BUTTON_LEFT: {
				//get location of mouse currently
				SDL_GetMouseState(&x, &y);

				//add offsets to it based on camera clip
				x += camera->x;
				y += camera->y;

				//check which is selected
				switch (currentObject) {
					case rect: {
						//load image
						Surface* rect = new Surface("images/rectangle.png");

						//and place the object there
						Figure* newFig = new RectFigure(x, y, *rect, screen, Figure::GRAVITY_DISABLED, false, 0, 0, 0,
								1, lvlWidth, lvlHeight, Figure::BOUNDARY);

						//and place it into the map
						container->push_back(newFig);
						break;
					}
				}
				break;
			}
		}
	}
	else if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
			case SDLK_1: {

				if (currentObject != rect) {

					//get location of mouse currently
					SDL_GetMouseState(&x, &y);

					//add offsets to it based on camera clip
					x += camera->x;
					y += camera->y;

					//load image
					Surface* rectsurf = new Surface("images/rectangle.png");

					//and place the object there
					tempObject = new MouseFigure(x, y, *rectsurf, screen, Figure::GRAVITY_DISABLED, false, 0, 0, 0, 1,
							lvlWidth, lvlHeight, Figure::BOUNDARY);

					currentObject = rect;
				}
				break;
			}
			case SDLK_2:
				break;

			case SDLK_3:
				break;

			case SDLK_4:
				break;

			case SDLK_ESCAPE:
				if (currentObject != none) {
					delete tempObject;
					tempObject = NULL;

					currentObject = none;
				}
				break;

			default:
				break;
		}
	}
}

void MouseFigure::setContainer(vector<Figure*>* src) {
	container = src;
}

void MouseFigure::setPosition(int x, int y) {
	this->p.x = x;
	this->p.y = y;
}

void MouseFigure::setHeightWidth(int h, int w) {
	lvlHeight = h;
	lvlWidth = w;
}

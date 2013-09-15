/*
 * MouseFigure.h
 *
 *  Created on: Sep 6, 2013
 *      Author: Alles Rebel
 */

#ifndef MOUSEFIGURE_H_
#define MOUSEFIGURE_H_

#include "Figure.h"
#include "Editor/Editor.h"
#include "GrabbableFigure.h"
#include "PlayerFigure.h"
#include "TempFigure.h"
#include "RectBoundaryFigure.h"
#include "CursorFigure.h"
#include "CircBoundaryFigure.h"
#include <cmath>

class MouseFigure: public Figure {
	public:
	MouseFigure(int x, int y, Surface* image, SDL_Surface* screen,
			int levelWidth, int levelHeight, int numClips);
	~MouseFigure();

	void setPosition(int x, int y);

	void handleInput(SDL_Event&);

	virtual bool checkCollision(CircFigure* other);
	virtual bool checkCollision(RectFigure* other);

	float distance(int x, int y);

	//Level Container - all objects in the level are stored here
	void setContainer(vector<Figure*>* src);

	//sets the level  properties TODO: include background
	void setHeightWidth(int, int);
	void setHeader(Header*);

	void clearLocalMemory();

	vector<Figure*>* container;

	int x, y;
	Header* header;

	enum objects {
		none,redWall, cloud, coin, blackdot
	};

	objects currentObject;

	Editor::types currentObjectType;

	MouseFigure* tempObject;
	Surface* imageSurf;

	int lvlHeight;
	int lvlWidth;

};

#endif /* MOUSEFIGURE_H_ */

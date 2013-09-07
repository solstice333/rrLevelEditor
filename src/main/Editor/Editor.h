/*
 * 	Editor v.5
 *
 * 	Encoding and decoding module
 * 	Reads a pretty simple formated txt
 * 	and creates a Vector<Figure*>*
 * 	with all memory it needs allocated
 *
 *  Created on: Sep 7, 2013
 *      Author: Alles Rebel
 */


#ifndef EDITOR_H_
#define EDITOR_H_

#include <string>
#include <vector>
#include "../Figure.h"

using namespace std;

class Editor {
public:
	void encode(string, vector<Figure*>*);
	vector<Figure*>* decode(string);
};

#endif /* EDITOR_H_ */

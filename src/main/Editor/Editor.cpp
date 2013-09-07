/*
 * Editor.cpp
 *
 *  Created on: Sep 7, 2013
 *      Author: Alles Rebel
 */

#include "Editor.h"

Editor::Editor() {
	headerInfo = NULL;
	file = NULL;
}

Editor::Editor(string filepath, state rw) {
	setFile(filepath, rw);
}

/*
 * Change the file being read/written to
 * If a previous file was opened, it will close
 * the previous file, and attempt to open the next
 */
void Editor::setFile(string filepath, state rw) {
	if (file != NULL) fclose(file);
	if (rw == read) file = fopen(filepath.c_str(), "r");
	if (rw == write) file = fopen(filepath.c_str(), "w");
}

/*
 * Write the header information to a file
 * Not required, just for flexibility
 * TODO: Probably should put a line here so reading will work
 * 		 like header v2 or something
 */
void Editor::writeHeader(Header header) {
	checkFile();

	fprintf(file, "%d %d %d %d\n", header.bg_w, header.bg_h, header.screen_w, header.screen_h);
	fprintf(file, "%s\n", header.bg_path.c_str());
	fprintf(file, "%s\n", header.bgm_path.c_str());
}

/*
 * If the file contains header information, it
 * cane be read with this function
 * Previous Header info will be deleted
 * TODO: probably should put a check in (like header v2 or something)
 */
Header* Editor::readHeader() {
	checkFile();

	if (headerInfo != NULL) {
		delete headerInfo;
	}

	headerInfo = new Header;

	char buffer[100];

	fscanf(file, "%d %d %d %d", &headerInfo->bg_w, &headerInfo->bg_h, &headerInfo->screen_w, &headerInfo->screen_h);
	fscanf(file, "%s", buffer);

	stringstream ss;
	ss << buffer;
	headerInfo->bg_path = ss.str();

	char buffer2[100];
	fscanf(file, "%s", buffer2);
	stringstream ss2;
	ss2 <<buffer2;
	headerInfo->bgm_path = ss2.str();

	return headerInfo;
}

/*
 * Encode the figures stored in the vector given
 * to the file opened. File should be opened
 * with write permissions!
 */
void Editor::encode(vector<Figure*>* container) {
	checkFile();

}

/*
 * Decode the file, and creates a vector container
 * with the result. File should be opened with
 * read permissions!
 */
vector<Figure*>* Editor::decode() {
	checkFile();
	return NULL;
}

Editor::~Editor() {
	if (file != NULL) fclose(file);
}

void Editor::checkFile() {
	if (file == NULL) {
		printf("Error! File pointer isn't assigned!\n");
		exit(1);
	}
}

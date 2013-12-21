#Level Editor Using SDLGameEngine API#

##Dependencies##
SDL 1.2, SDL_image 1.2, SDL_mixer 1.2, SDL_ttf 2.0

##Suggested Developer Tools##
Eclipse Kepler 4.3 for C/C++ Developers - http://www.eclipse.org/downloads/packages/eclipse-ide-cc-developers/keplersr1

##How to Setup and Build Using Eclipse on Ubuntu 13.10##
1. Fork the project 
2. Clone the project to your local filesystem
3. cd to the parent directory of the repository
4. In the terminal,
    ./setup
    ./run

5. If project runs fine, import to Eclipse

##So this is a VERY basic level editor!##
***_To Add Figures_***

1. Select what piece you wish to place with numbers 1-9
	-This will remove you from delete mode if a valid piece is selected

2. Click to add piece to scene
	-A figure will be following your mouse, once you click it should not move

***_To Remove Figures_***

1. Press escape to exit placing mode 
	-This will get rid of any pieces following your mouse
2. Click on a figure in the scene to delete it
	-Will only work if you click with in the figure

***_To Save Scene_***

1. Simply press s on the keyboard
	-Scene will be saved to level.txt

***_To Load Scene_***

1. Simply restart the editor

##Playing Your Level##
Close the level editor window to load and play your level.
Use w, a, s, d to move, and the mouse with left click to aim and grab the clouds!

#ifndef GLOBALS_H
#define GLOBALS_H

#include <iostream>
using namespace std;

namespace globals 
{
	const int SCREEN_WIDTH = 600;
	const int SCREEN_HEIGHT = 480;

	const float SPRITE_SCALE = 1.0f;
}

/* Global SDL error logging procedure
 * Used to have a error output convention for SDL_GetError
 */
void logSDLError(const string msg)
{
	cout << msg << " error: " << SDL_GetError() << endl;
}

#endif

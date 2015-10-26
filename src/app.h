#ifndef APP_H
#define APP_H

#include <SDL2/SDL.h>
#include "graphics.h"
#include "input.h"

class Graphics;

class APP {
	public:
		APP();
		~APP();
	private:
		void APPLoop();
		void draw(Graphics &graphics);
		void update(float elapsedTime);
};


/* Game class
 *  * This class holds all information for our main game loop
 *   */

namespace {
	const int FPS = 50;
	const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}

APP::APP() {
		SDL_Init(SDL_INIT_EVERYTHING);
		this->APPLoop();
}

APP::~APP() {

}

void APP::APPLoop() {
		Graphics graphics;
		Input input;
		SDL_Event event;

		int LAST_UPDATE_TIME = SDL_GetTicks();
		//Start the app loop
		while (true) {
		input.beginNewFrame();
		
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN) {
				if (event.key.repeat == 0) {
					input.keyDownEvent(event);
				}
			}
			else if (event.type == SDL_KEYUP) {
				input.keyUpEvent(event);
			}
			else if (event.type == SDL_QUIT) {
				return;
			}
		}
		if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true) {
				return;
		}
		
		const int CURRENT_TIME_MS = SDL_GetTicks();
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
		this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
		LAST_UPDATE_TIME = CURRENT_TIME_MS;
	}
}

void APP::draw(Graphics &graphics) {

}

void APP::update(float elapsedTime) {

}

#endif

#ifndef GRAPHICS_H
#define GRAPHICS_H

struct SDL_Window;
struct SDL_Renderer;

class Graphics {
	public:
		Graphics();
		~Graphics();
	private:
		SDL_Window* _window;
		SDL_Renderer* _renderer;
};

Graphics::Graphics() {
		SDL_CreateWindowAndRenderer(640, 480, 0, &this->_window, &this->_renderer);
			SDL_SetWindowTitle(this->_window, "SDL TEMPLATE");
}

Graphics::~Graphics() {
		SDL_DestroyWindow(this->_window);
}

#endif

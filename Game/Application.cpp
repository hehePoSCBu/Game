#include<SDL3/SDL.h>

int main()
{
	SDL_Window* window;
	SDL_Renderer* renderer;

	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("Game", 1280, 720, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	if (window==NULL)
	{
		SDL_Quit();
		return 1;
	}
	renderer = SDL_CreateRenderer(window,NULL);

	bool running = true;
	while (running)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_EVENT_QUIT:
				running = false;
				break;
			default:
				break;
			}

			SDL_SetRenderDrawColor(renderer, 1, 1, 1, 255);
			SDL_RenderClear(renderer);

			// ----------- 绘制内容 ----------- //



			// ----------- 结束绘制 ----------- //

			SDL_RenderPresent(renderer);
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
#include<SDL.h>
#include<iostream>
#include<random>


int SDL_main(int argc, char* argv[]) {

	SDL_Init(SDL_INIT_EVERYTHING);
	std::cout << "hello" << "\n";

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_CreateWindowAndRenderer(50 * 20, 50 * 20, 0, &window, &renderer);
	SDL_RenderSetScale(renderer, 20, 20);

	int x = 25;
	int y = 25;

	std::random_device dev;
	std::uniform_int_distribution<int> rd(0, 4);

	while (1)
	{
		int dir = rd(dev);

		switch (dir) { //defines the direction
			case 0 :
				x -= 1;
				y -= 1;
				break;
			case 1 :
				x += 1;
				y -= 1;
				break;
			case 2 :
				x += 1;
				y += 1;
				break;
			case 3 :
				x -= 1;
				y += 1;
				break;

		}


		Uint8 r = static_cast<Uint8>(x * 5); // Red component
		Uint8 g = static_cast<Uint8>(y * 5); // Green component
		Uint8 b = 255 - static_cast<Uint8>((x + y) * 5); // Blue component


		SDL_SetRenderDrawColor(renderer, r,g,b,255);
		SDL_RenderDrawPoint(renderer, x, y);
		SDL_RenderPresent(renderer);

		if (x > 50 || x < 0 || y > 50 || y < 0) {
			x = 25;
			y = 25;
		}
		SDL_Delay(50);
	}






	return 0;
}
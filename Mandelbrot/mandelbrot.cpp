#include <SDL.h>
#include <iostream>
#include <complex>

const int WIDTH = 800;
const int HEIGHT = 600;
const int MAX_ITERATIONS = 1000;

void renderMandelbrotSet(SDL_Renderer* renderer) {
    for (int x = 0; x < WIDTH; ++x) {
        for (int y = 0; y < HEIGHT; ++y) {
            double zx = 0;
            double zy = 0;
            double cx = (x - WIDTH / 2.0) * 4.0 / WIDTH;
            double cy = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
            std::complex<double> c(cx, cy);
            std::complex<double> z(0, 0);
            int iterations = 0;

            while (std::abs(z) < 2 && iterations < MAX_ITERATIONS) {
                z = z * z + c;
                ++iterations;
            }

            Uint8 r = 0;
            Uint8 g = 0;
            Uint8 b = 0;

            if (iterations < MAX_ITERATIONS) {
                double t = static_cast<double>(iterations) / MAX_ITERATIONS;
                r = static_cast<Uint8>(9 * (1 - t) * t * t * t * 255);
                g = static_cast<Uint8>(15 * (1 - t) * (1 - t) * t * t * 255);
                b = static_cast<Uint8>(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
            }

            SDL_SetRenderDrawColor(renderer, r, g, b, 255);
            SDL_RenderDrawPoint(renderer, x, y);
        }
    }
}

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Mandelbrot Set", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    renderMandelbrotSet(renderer);

    SDL_RenderPresent(renderer);

    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = false;
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}


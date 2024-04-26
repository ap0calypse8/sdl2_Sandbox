#include <SDL.h>
#include <iostream>
#include<math.h>
#include<string>
using namespace std;

const int width = 640; 
const int height = 480;
double zoom = 1.0;
SDL_Window* window = nullptr;
SDL_Renderer* Renderer = nullptr;


bool initSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cerr << "SDL could not run!!" << SDL_GetError() << "\n";
        return false;
    }

    window = SDL_CreateWindow("SHAPE", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        cerr << "window not created" << SDL_GetError() << "\n";
        return false;
    }
    Renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (Renderer == nullptr) {
        cerr << "Rendering was not successful" << SDL_GetError() << "\n";
        return false;
    }
    return true;
}

void close() {
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void handlezoom(SDL_Event& e) {
    if (e.type == SDL_MOUSEWHEEL) {
        if (e.wheel.y > 0) {
            zoom += 0.1;
        }
        else if (e.wheel.y < 0) {
            zoom -= 0.1;

            if (zoom < 0.1) {
                zoom = 0.1;
            }
        }
    }
}

bool isPrime(int n) {
    
    if (n == 0 || n == 1) {
        return false;
    }

    
    for (int i = 2; i < n; ++i) {
        
        if (n % i == 0) {
            return false; // Not prime
        }
    }

    return true; // Prime
}


void generateData() {
   
    for (int num = 4; num <= width; num++) {
        int count = 0;

        for (int i = 2; i<= num / 2; ++i) {

            if (isPrime(i) && isPrime(num - i)) {
                count += 1;
            }
        }
        cout<<"Number: "<<num<<", ways " << count << "\n";
    }
}



void plotData(SDL_Renderer* renderer, double zoomf) {

    for (int num = 4; num <= width; num += 2) {
        int count = 0;
        for (int i = 2; i <= num / 2; ++i) {
            if (isPrime(i) && isPrime(num - i)) {
                ++count;
            }
        }
        int radius = count * 2 * zoomf; //calculating circle info
        int x = num;
        int y = height - count * 10 * zoomf;



        int intensity = 255 - count * 10; //intensity for color gradient
        intensity = max(0, min(255, intensity));//ensure that intensitry is within range
        SDL_SetRenderDrawColor(renderer, 255, intensity, 0, 255);
       
        //drawing the circles using polar coordiantes
        for (int i = 0; i < 360; ++i) {
            int xPos = x + radius * cos(i * M_PI / 180);
            int yPos = y + radius * sin(i * M_PI / 180);
            SDL_RenderDrawPoint(renderer, xPos, yPos);
        }

    }
}


 

int main(int argc, char* argv[]) {

    if (!initSDL()) {
        cerr << "Failed to initialise SDL" << "\n";
        return -1;
    }

    generateData();

    bool quit = false;

    SDL_Event e;

    while (!quit) { //main loop

        while (SDL_PollEvent(&e) != 0) {//to handle the events

            if (e.type == SDL_QUIT) { //checks if the user quits 
                quit = true;
            }
            handlezoom(e); //handles the zooming event
        }

        SDL_SetRenderDrawColor(Renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(Renderer);

        // Plot data
        plotData(Renderer,zoom);

        // Update screen
        SDL_RenderPresent(Renderer);
    }

     

     close();
    


    return 0;
}


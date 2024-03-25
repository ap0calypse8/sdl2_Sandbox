# Mandelbrot Set Visualization using SDL2

This project implements a Mandelbrot set visualization using SDL2, a popular multimedia library for graphics applications. The Mandelbrot set is a fascinating mathematical object that exhibits complex and intricate fractal patterns.
- The Mandelbrot set visualization is based on mathematical concepts developed by Benoit B. Mandelbrot.

## Features

- Renders the Mandelbrot set in a window using SDL2.
- Allows users to explore the Mandelbrot set by zooming and panning (not implemented in the provided code).
- Adjustable parameters such as window size, maximum iterations, and color scheme.


## Visualisation
![](https://github.com/ap0calypse8/sdl2_Sandbox/blob/main/Mandelbrot/mandelbrott.png)
  



  
## Getting Started

To run the Mandelbrot set visualization:

1. Make sure you have SDL2 installed on your system. You can download SDL2 from the [official SDL website](https://www.libsdl.org) .
2. Clone or download the project files to your local machine.
3. Compile the source code using a C++ compiler that supports C++11 or later.
4. Run the compiled executable to launch the Mandelbrot set visualization.

## Usage

- Upon running the program, a window titled "Mandelbrot Set" will open, displaying the rendered Mandelbrot set.
- You can explore the Mandelbrot set by clicking and dragging to pan across different regions of the set.
- Zooming functionality can be implemented by modifying the code to respond to mouse wheel events in future.
- The program will exit when you close the window or press the close button.

## Customization

You can customize various aspects of the visualization by modifying the source code:

- Adjust the window size by changing the `WIDTH` and `HEIGHT` constants.
- Change the maximum number of iterations for the Mandelbrot set calculation by modifying the `MAX_ITERATIONS` constant.
- Experiment with different color schemes by adjusting the color calculation formula in the `renderMandelbrotSet` function.

## Dependencies

- SDL2: The Simple DirectMedia Layer version 2.0 library is required for graphics rendering.
- C++11 or later: The source code utilizes features from the C++11 standard and above.

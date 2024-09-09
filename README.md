# Computer Graphics

**⚠️ This repository is currently in development.**

This project is a collection of knowledge and experiments in computer graphics that I have acquired through learning and practice. It aims to consolidate and share various concepts, techniques, and insights gained from lectures and personal exploration in the field of computer graphics. This resource is intended to be useful for anyone interested in understanding and applying graphics principles.

## Acknowledgments

This project uses code from [Tiny Renderer](https://github.com/ssloy/tinyrenderer), created by Dmitry V. Sokolov. 

This project also utilizes the following libraries:
- [GLFW](https://www.glfw.org/) - A library for creating windows and managing input.
- [GLEW](http://glew.sourceforge.net/) - The OpenGL Extension Wrangler Library.
- [GLM](https://github.com/g-truc/glm) - OpenGL Mathematics for graphics software.
- [ImGui](https://github.com/ocornut/imgui) - A bloat-free graphical user interface library for C++.

## Installation

Instructions on how to set up the project locally. You will need have cmake in your machine and a c++ compiler.

1. Clone the repository:
    ```sh
    git clone https://github.com/yourusername/your-repository.git
    ```
2. Navigate to the project directory:
    ```sh
    cd your-repository
    ```
3. Install Projects 3rdparty using git submodule
    ```sh
    git submodule init
    git submodule update
    ```
4. Build project using cmake
    ```sh
    cmake -S . -B build
    ```
5. Then
	```sh
    cmake --build build
    ```
6. All executables are in build/Lectures. Have fun :D
	```sh
    ./build/Lectures/executable_name
    ```

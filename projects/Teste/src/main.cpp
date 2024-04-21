#include <iostream>
#include<GLFW\glfw3.h>

int main() {

    GLFWwindow* window;

    glfwInit();

    window = glfwCreateWindow(1024, 768, "Project Teste", NULL, NULL);
    glfwMakeContextCurrent(window);


    while(!glfwWindowShouldClose(window))
    {

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
 
    std::cout << "Hello, World\n";
    return 0;
}
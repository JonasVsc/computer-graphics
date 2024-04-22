#include<GL\glew.h>
#include<GLFW\glfw3.h>

class core 
{
public:
	core();
	void init(int width, int height, const char *title);
	GLFWwindow* window;
private:
};
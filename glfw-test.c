#include <GLFW/glfw3.h>
#include <stdio.h>

void onWindowClose (GLFWwindow* window);
void errorCallback(int error, const char* description);

int main()
{
	if (!glfwInit())
	    printf("failed to initialize glfw", stderr);

	glfwSetErrorCallback(errorCallback);

	GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
	if (!window)
	    printf("failed to create window", stderr);
	glfwMakeContextCurrent(window);
	glfwSetWindowCloseCallback(window, onWindowClose);
	while (!glfwWindowShouldClose(window)) {
	    // Keep running
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}

void errorCallback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}
void onWindowClose (GLFWwindow* window)
{
	glfwSetWindowShouldClose(window, GLFW_TRUE);
}

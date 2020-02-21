#include <stdio.h>
#include <unistd.h>
#include <GLFW/glfw3.h>

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
	while (!glfwWindowShouldClose(window)) {
		sleep(0.02f); // arbitrary wait period to reduce cpu load
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}

void errorCallback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}

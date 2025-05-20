#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>  

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

int main()  
{  
	glfwInit();  
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);  
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);  
#ifdef __APPLE__  
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);  
#endif  

	GLFWwindow* window;

	window = glfwCreateWindow(1280, 720, "Game", nullptr, nullptr);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))  
	{  
		std::cout << "Failed to initialize GLAD" << std::endl;  
		return -1;  
	}

	while (!glfwWindowShouldClose(window))
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;  
}
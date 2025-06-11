#pragma once
#include"../App.h"

class Scene
{
public:
	Scene();

	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
	static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	static void processInput(GLFWwindow* window);

	void run();

	GLFWwindow* getWindow();
private:
	unsigned int SCREEN_WIDTH;
	unsigned int SCREEN_HEIGHT;

	GLFWwindow* window;

	// settings
	Camera camera;
	float lastX;
	float lastY;
	bool firstMouse;

	// timing
	float deltaTime;
	float lastFrame;
};


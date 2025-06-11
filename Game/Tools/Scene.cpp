#include "Scene.h"

Scene::Scene()
    : camera(glm::vec3(0.0f, 0.0f, 3.0f))
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    this->SCREEN_HEIGHT = 720;
    this->SCREEN_WIDTH = 1280;

    window = glfwCreateWindow(this->SCREEN_WIDTH, this->SCREEN_HEIGHT, "Game", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(1);
    }
    glfwMakeContextCurrent(window);


    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    lastX = this->SCREEN_WIDTH / 2.0f;
    lastY = this->SCREEN_HEIGHT / 2.0f;

    deltaTime=0.0f;	// time between current frame and last frame
    lastFrame = 0.0f;

    this->firstMouse = true;

    glfwSetWindowUserPointer(window, this);


    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        exit(1);
    }

    glEnable(GL_DEPTH_TEST);
}

GLFWwindow* Scene::getWindow()
{
    return window;
}

void Scene::processInput(GLFWwindow* window)
{
    Scene* scene = static_cast<Scene*>(glfwGetWindowUserPointer(window));

    Camera camera = scene->camera;
    float deltaTime = scene->deltaTime;

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
        camera.ProcessKeyboard(UP, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        camera.ProcessKeyboard(DOWN, deltaTime);

    scene->deltaTime = deltaTime;
    scene->camera = camera;
}

void Scene::run()
{
    while (!glfwWindowShouldClose(window))
    {
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;


        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Scene::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

void Scene::mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    Scene* scene = static_cast<Scene*>(glfwGetWindowUserPointer(window));

    bool firstMouse = scene->firstMouse;
    float lastX = scene->lastX;
    float lastY = scene->lastY;

    Camera camera = scene->camera;

    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
    std::cout << xoffset << "\0" << yoffset << "\n";

    scene->camera = camera;
    scene->lastX = lastX;
    scene->lastY = lastY;
    scene->firstMouse = firstMouse;

}

void Scene::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    Scene* scene = static_cast<Scene*>(glfwGetWindowUserPointer(window));
    Camera camera = scene->camera;

    camera.ProcessMouseScroll(static_cast<float>(yoffset));

    scene->camera = camera;
}
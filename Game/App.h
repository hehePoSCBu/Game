#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


constexpr const char* ASSETS_PATH = "$(SolutionDir)assets";

#include "Core/shader.h"
#include "Core/camera.h"
#include"Core/model.h"

#include <iostream>

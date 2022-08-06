#pragma once

// GLM
#include <glm/glm.hpp>
#include <glm/ext.hpp>

// GLAD
#include <glad/glad.h>

// GLFW3
#include <GLFW/glfw3.h>

// ImGui
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

// C++ Headers
#include <iostream>
#include <string>
#include <functional>
#include <filesystem>
#include <exception>
#include <source_location>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <ostream>
#include <fstream>
#include <memory>
#include <set>
#include <map>

// PrimitiveEngine Legacy
#include <Legacy/Data/Debug.hpp>
#include <Legacy/Data/GPU.hpp>
#include <Legacy/Data/Utils.hpp>

#include <Legacy/Utils/Image.hpp>
#include <Legacy/Utils/File.hpp>
#include <Legacy/Utils/Path.hpp>
#include <Legacy/Utils/Time.hpp>

#include <Legacy/GPU/Texture.hpp>
#include <Legacy/GPU/Shader.hpp>

#include <Legacy/Data/Framebuffer.hpp>
#include <Legacy/GPU/Framebuffer.hpp>
#include <Legacy/GPU/Vertex.hpp>
#include <Legacy/GPU/Command.hpp>

#include <Legacy/Data/Window.hpp>
#include <Legacy/Window/GUI.hpp>
#include <Legacy/Window/Window.hpp>

#include <Legacy/Debug/Logging.hpp>
#include <Legacy/Debug/Debugging.hpp>

#include <Legacy/Data/Input.hpp>
#include <Legacy/Input/Mouse.hpp>
#include <Legacy/Input/Keyboard.hpp>

#include <Legacy/Data/Camera.hpp>
#include <Legacy/Camera/Camera2D.hpp>
#include <Legacy/Camera/Camera3D.hpp>

#include <Legacy/Utils/Generator.hpp>

#include <Legacy/Drawing/TextureRenderer.hpp>
#include <Legacy/Drawing/Primitives2D.hpp>
#include <Legacy/Drawing/Primitives3D.hpp>
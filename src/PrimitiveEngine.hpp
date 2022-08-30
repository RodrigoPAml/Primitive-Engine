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

// Json
#include <json_nlohmann.hpp>

// C++ Headers
#include <iostream>
#include <string>
#include <algorithm>
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
#include <any>
#include <set>
#include <map>

// PrimitiveEngine
#include <Engine/Data/UtilsData.hpp>
#include <Engine/Utils/Time.hpp>

#include <Engine/Data/DebugEnums.hpp>
#include <Engine/Data/DebugData.hpp>
#include <Engine/Data/DebugCallbacks.hpp>
#include <Engine/Data/DebugUtils.hpp>

#include <Engine/Data/GPUEnums.hpp>
#include <Engine/Data/GPUData.hpp>
#include <Engine/Data/GPUUtils.hpp>


#include <Engine/Utils/Image.hpp>
#include <Engine/Utils/File.hpp>
#include <Engine/Utils/Path.hpp>

#include <Engine/GPU/Texture.hpp>
#include <Engine/GPU/Shader.hpp>

#include <Engine/Data/FramebufferData.hpp>

#include <Engine/GPU/Framebuffer.hpp>
#include <Engine/GPU/Vertex.hpp>
#include <Engine/GPU/Command.hpp>

#include <Engine/Data/WindowEnums.hpp>
#include <Engine/Data/WindowData.hpp>
#include <Engine/Data/WindowCallbacks.hpp>

#include <Engine/Window/GUI.hpp>
#include <Engine/Window/Window.hpp>

#include <Engine/Debug/Logging.hpp>
#include <Engine/Debug/Debugging.hpp>

#include <Engine/Data/InputEnums.hpp>
#include <Engine/Data/InputCallbacks.hpp>

#include <Engine/Input/Mouse.hpp>
#include <Engine/Input/Keyboard.hpp>

#include <Engine/Data/CameraEnums.hpp>
#include <Engine/Data/CameraData.hpp>

#include <Engine/Camera/Camera2D.hpp>
#include <Engine/Camera/Camera3D.hpp>

#include <Engine/Utils/Generator.hpp>

#include <Engine/Drawing/TextureRenderer.hpp>
#include <Engine/Drawing/Primitives2D.hpp>
#include <Engine/Drawing/Primitives3D.hpp>

// Editor
#include <Editor/Interfaces/Layout.hpp>
#include <Editor/EditorConfiguration.hpp>
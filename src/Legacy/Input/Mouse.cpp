#include <PrimitiveEngine.hpp>
#include "Mouse.hpp"

namespace PrimitiveEngine
{
	namespace Input
	{
		void Mouse::SetMouseButtonCallback(MouseButtonCallback callback)
		{
			auto& instance = Instance();
				
			instance.mouseButtonCallback = callback;

			glfwSetMouseButtonCallback(instance.windowPtr, MasterMouseButtonCallback);
		}

		void Mouse::SetMousePositionCallback(MousePositionCallback callback)
		{
			auto& instance = Instance();

			instance.mousePositionCallback = callback;

			glfwSetCursorPosCallback(instance.windowPtr, MasterCursorPositionCallback);
		}

		void Mouse::SetMouseScrollCallback(MouseScrollCallback callback)
		{
			Instance().mouseScrollCallback = callback;
		}

		void Mouse::SetMouseEnterWindowCallback(MouseEnterWindowCallback callback)
		{
			Instance().mouseEnterWindowCallback = callback;
		}

		InputAction Mouse::GetMouseButtonState(const MouseButton button)
		{
			return (InputAction)glfwGetMouseButton(Instance().windowPtr, (int)button);
		}

		glm::vec<2, int> Mouse::GetMousePosition()
		{
			double xpos, ypos;
			glfwGetCursorPos(Instance().windowPtr, &xpos, &ypos);

			return {xpos, ypos};
		}

		glm::vec<2, int> Mouse::GetMouseVariation()
		{
			return Instance().lastPosition -  GetMousePosition();
		}

		void Mouse::SetMouseMode(const MouseMode mode)
		{
			glfwSetInputMode(Instance().windowPtr, GLFW_CURSOR, (int)mode);
		}

		float Mouse::GetScroll()
		{
			auto& mouse = Instance();

			auto& tempScroll = mouse.scroll;

			mouse.scroll = 0;

			return tempScroll;
		}

		bool Mouse::IsMouseInsideWindow()
		{
			return Instance().isInsideWindow;
		}

		Mouse& Mouse::Instance()
		{
			static Mouse* instance = new Mouse();

			return *instance;
		}

		void Mouse::Init(GLFWwindow* windowPtr)
		{
			this->windowPtr = windowPtr;

			glfwSetScrollCallback(windowPtr, MasterScrollCallback);
			glfwSetCursorEnterCallback(windowPtr, MasterCursorEnterWindow);

			this->mouseButtonCallback = nullptr;
			this->mousePositionCallback = nullptr;
			this->mouseScrollCallback = nullptr;
			this->mouseEnterWindowCallback = nullptr;

			this->lastPosition = { 0.0f, 0.0f };
			this->scroll  = 0;
			this->isInsideWindow = false;

			Debug::Logging::Log("Mouse", "Initialized");
		}

		void Mouse::Release()
		{
			glfwSetScrollCallback(this->windowPtr, nullptr);
			glfwSetCursorEnterCallback(this->windowPtr, nullptr);
			glfwSetCursorPosCallback(this->windowPtr, nullptr);
			glfwSetMouseButtonCallback(this->windowPtr, nullptr);

			this->mouseButtonCallback = nullptr;
			this->mousePositionCallback = nullptr;
			this->mouseScrollCallback = nullptr;
			this->mouseEnterWindowCallback = nullptr;

			this->lastPosition = { 0.0f, 0.0f };
			this->scroll = 0;
			this->isInsideWindow = false;
			this->windowPtr = nullptr;

			Debug::Logging::Log("Mouse", "Released");
		}

		void Mouse::MasterCursorEnterWindow(GLFWwindow* window, int entered)
		{
			auto& mouse = Instance();

			mouse.isInsideWindow = (bool)entered;

			if (mouse.mouseEnterWindowCallback != nullptr)
				mouse.mouseEnterWindowCallback((bool)entered);
		}

		void Mouse::MasterCursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
		{
			auto& mouse = Instance();

			if (mouse.mousePositionCallback != nullptr)
				mouse.mousePositionCallback({ xpos, ypos });
		}

		void Mouse::MasterMouseButtonCallback(GLFWwindow* window, int button, int action, int mod)
		{
			auto& mouse = Instance();

			if (mouse.mouseButtonCallback != nullptr)
				mouse.mouseButtonCallback((MouseButton)button, (InputAction)action, (InputModifier)mod);
		}

		void Mouse::MasterScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
		{
			auto& mouse = Instance();

			mouse.scroll += yoffset;

			if (mouse.mouseScrollCallback != nullptr)
				mouse.mouseScrollCallback(yoffset);
		}
	}
}

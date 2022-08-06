#include <PrimitiveEngine.hpp>
#include "Window.hpp"

namespace PrimitiveEngine
{
	namespace Window
	{
		void Window::Init(
			const WindowConfiguration& windowConfig,
			const Debug::DebugConfiguration& debugConfiguration,
			const Debug::LoggingConfiguration& loggingConfiguration)
		{
			auto& instance = Instance();

			if (instance.isInitialized)
				Debug::Logging::LogException("Window", "Already initialized", true);

			Debug::Logging::Instance().Init(loggingConfiguration);
			
			if(!glfwInit())
			{
				instance.isInitialized = false;

				glfwDestroyWindow(instance.windowPtr);

				Debug::Logging::LogException("Window", "Failed to initialized GLFW", true);
			}

			if(debugConfiguration.enableGlfwDebugging)
				glfwSetErrorCallback(Debug::Debugging::GLFW_ERROR_CALLBACK);

			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, (int)windowConfig.openGlVersionMax);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, (int)windowConfig.openGlVersionMin);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

			bool HaveMSAA = (windowConfig.windowMSAA > 0);

			if(HaveMSAA) 
				glfwWindowHint(GLFW_SAMPLES, windowConfig.windowMSAA);

			instance.windowPtr = glfwCreateWindow(
				windowConfig.windowSize.x, 
				windowConfig.windowSize.y, 
				windowConfig.windowName.c_str(), 
				NULL, 
				NULL
			);

			if(instance.windowPtr == nullptr)
			{
				instance.isInitialized = false;

				glfwDestroyWindow(instance.windowPtr);
				glfwTerminate();

				Debug::Logging::LogException("Window", "Failed to create window", true);
			}

			glfwMakeContextCurrent(instance.windowPtr);

			if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			{
				instance.isInitialized = false;

				glfwDestroyWindow(instance.windowPtr);
				glfwTerminate();

				Debug::Logging::LogException("Window", "Failed to initialize GLAD", true);
			}
			
			if (debugConfiguration.enableOpenGLDebugging)
			{
				glEnable(GL_DEBUG_OUTPUT);
				glDebugMessageCallback(Debug::Debugging::OPENGL_ERROR_CALLBACK, 0);
			}

			glfwSetWindowPos(instance.windowPtr, windowConfig.windowPosition.x, windowConfig.windowPosition.y);
			glfwSetFramebufferSizeCallback(instance.windowPtr, WindowResizeCallback);
			glfwSetWindowCloseCallback(instance.windowPtr, WindowCloseCallback);
			glfwSetWindowPosCallback(instance.windowPtr, WindowPositionCallback);
			glfwSetWindowMaximizeCallback(instance.windowPtr, WindowMaximizeCallback);
			glfwSetWindowIconifyCallback(instance.windowPtr, WindowMinimizeCallback);
			glfwSetWindowFocusCallback(instance.windowPtr, WindowFocusCallback);

			if(HaveMSAA) 
				glEnable(GL_MULTISAMPLE);

			glViewport(0, 0, Window::GetSize().x, Window::GetSize().y);

			Input::Keyboard::Instance().Init(instance.windowPtr);
			Input::Mouse::Instance().Init(instance.windowPtr);
			Debug::Debugging::Instance().Init(debugConfiguration);
			Drawing::Primitives3D::Instance().Init();
			Drawing::Primitives2D::Instance().Init();
			Drawing::TextureRenderer::Instance().Init();

			instance.config = windowConfig;
			instance.isInitialized = true;

			Debug::Logging::Log("Window", "Initialized");
		}

		void Window::Destroy()
		{
			auto& instance = Instance();

			if (!instance.isInitialized)
				Debug::Logging::LogException("Window", "Window is not initialized, can't destroy it");

			instance.isInitialized = false;
			instance.isFocused = false;
			instance.isHide = false;
			instance.isMinimized = false;
			instance.config = WindowConfiguration();
			instance.closeWindowCallback = nullptr;
			instance.focusWindowCallback = nullptr;
			instance.minimizeWindowCallback = nullptr;
			instance.repositionWindowCallback = nullptr;
			instance.resizeWindowCallback = nullptr;
			instance.maximizeWindowCallback = nullptr;

			Debug::Logging::Log("Window", "Destroyed");

			Input::Keyboard::Instance().Release();
			Input::Mouse::Instance().Release();
			Debug::Debugging::Instance().Release();
			Drawing::Primitives3D::Instance().Release();
			Drawing::Primitives2D::Instance().Release();
			Drawing::TextureRenderer::Instance().Release();
			Debug::Logging::Instance().Release();
			
			glfwDestroyWindow(instance.windowPtr);
			glfwTerminate();

			instance.windowPtr = nullptr;
		}

		bool Window::ShouldRun()
		{
			return (Instance().isInitialized && !glfwWindowShouldClose(Instance().windowPtr));
		}

		void Window::Resize(const glm::vec2& newSize)
		{
			auto& instance = Instance();

			if (!instance.isInitialized)
				Debug::Logging::LogException("Window", "Window is not initialized");

			glfwSetWindowSize(instance.windowPtr, newSize.x, newSize.y);

			int x, y;

			glfwGetWindowSize(instance.windowPtr, &x, &y);

			instance.config.windowSize.x = x;
			instance.config.windowSize.y = y;
		}

		glm::vec2 Window::GetSize()
		{
			return Instance().config.windowSize;
		}

		void Window::SetPosition(const glm::vec2& pos)
		{
			auto& instance = Instance();
			
			if (!instance.isInitialized)
				Debug::Logging::LogException("Window", "Window is not initialized");

			glfwSetWindowPos(instance.windowPtr, pos.x, pos.y);

			int x, y;

			glfwGetWindowPos(instance.windowPtr, &x, &y);

			instance.config.windowPosition.x = x;
			instance.config.windowPosition.y = y;
		}

		glm::vec2 Window::GetPosition()
		{
			return Instance().config.windowPosition;
		}

		std::string Window::GetName()
		{
			return Instance().config.windowName;
		}

		void Window::SetName(const std::string& title)
		{
			auto& instance = Instance();

			if (!instance.isInitialized)
				Debug::Logging::LogException("Window", "Window is not initialized");

			glfwSetWindowTitle(instance.windowPtr, title.c_str());
		}

		void Window::SetFullscreen()
		{
			auto& instance = Instance();

			if (!instance.isInitialized)
				Debug::Logging::LogException("Window", "Window is not initialized");

			const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

			glfwSetWindowMonitor(
				instance.windowPtr, 
				glfwGetPrimaryMonitor(), 
				0, 
				0, 
				mode->width, 
				mode->height,
				mode->refreshRate
			);

			int x, y;

			glfwGetWindowSize(instance.windowPtr, &x, &y);

			instance.config.windowSize.x = x;
			instance.config.windowSize.y = y;

			glfwGetWindowPos(instance.windowPtr, &x, &y);

			instance.config.windowPosition.x = x;
			instance.config.windowPosition.y = y;

			instance.isFullscreen = true;
		}

		void Window::RemoveFullscreen(const glm::vec2& newSize, const glm::vec2& newPos)
		{
			auto& instance = Instance();

			if (!instance.isInitialized)
				Debug::Logging::LogException("Window", "Window is not initialized");

			glfwSetWindowMonitor(
				instance.windowPtr,
				NULL, 
				0, 
				0, 
				newSize.x, 
				newSize.y, 
				GLFW_DONT_CARE
			);

			int x, y;
			glfwGetWindowSize(instance.windowPtr, &x, &y);

			instance.config.windowSize.x = x;
			instance.config.windowSize.y = y;

			instance.isFullscreen = false;

			instance.SetPosition(newPos);
		}

		void Window::Hide()
		{
			auto& instance = Instance();

			if (!instance.isInitialized)
				Debug::Logging::LogException("Window", "Window is not initialized");

			glfwHideWindow(instance.windowPtr);

			instance.isHide = true;
		}

		void Window::Show()
		{
			auto& instance = Instance();

			if (!instance.isInitialized)
				Debug::Logging::LogException("Window", "Window is not initialized");

			glfwShowWindow(instance.windowPtr);

			instance.isHide = false;
		}

		void Window::Maximize()
		{
			auto& instance = Instance();

			if (!instance.isInitialized)
				Debug::Logging::LogException("Window", "Window is not initialized");

			glfwMaximizeWindow(instance.windowPtr);

			int x, y;

			glfwGetWindowSize(instance.windowPtr, &x, &y);

			instance.config.windowSize.x = x;
			instance.config.windowSize.y = y;

			glfwGetWindowPos(instance.windowPtr, &x, &y);

			instance.config.windowPosition.x = x;
			instance.config.windowPosition.y = y;
		}

		void Window::Minimize()
		{
			auto& instance = Instance();

			if (!instance.isInitialized)
				Debug::Logging::LogException("Window", "Window is not initialized");

			glfwIconifyWindow(instance.windowPtr);

			instance.isMinimized = true;
		}

		void Window::Restore()
		{
			auto& instance = Instance();

			if (!instance.isInitialized)
				Debug::Logging::LogException("Window", "Window is not initialized");

			glfwRestoreWindow(instance.windowPtr);

			instance.isMinimized = false;
		}

		void Window::Close()
		{
			auto& instance = Instance();

			if (!instance.isInitialized)
				Debug::Logging::LogException("Window",  "Window is not initialized");

			glfwSetWindowShouldClose(instance.windowPtr, 1);
		}

		void Window::RequestAttention()
		{
			auto&& instance = Instance();

			if (!instance.isInitialized)
				Debug::Logging::LogException("Window",  "Window is not initialized");

			glfwRequestWindowAttention(instance.windowPtr);
		}

		void Window::SwapAndPollEvents()
		{
			auto& instance = Instance();

			if (!instance.isInitialized)
				Debug::Logging::LogException("Window", "Window is not initialized");

			auto& mouseIstance = Input::Mouse::Instance();
			mouseIstance.scroll = 0;
			mouseIstance.lastPosition = Input::Mouse::GetMousePosition();

			if(!instance.isInitialized)
				return;

			glfwSwapBuffers(instance.windowPtr);
			glfwPollEvents();
		}

		void Window::SetResizeWindowCallback(ResizeWindowCallback callback)
		{
			Instance().resizeWindowCallback = callback;
		}

		void Window::SetRepositionWindowCallback(RepositionWindowCallback callback)
		{
			Instance().repositionWindowCallback = callback;
		}

		void Window::SetMaximizeWindowCallback(MaximizeWindowCallback callback)
		{
			Instance().maximizeWindowCallback = callback;
		}

		void Window::SetMinimizeWindowCallback(MinimizeWindowCallback callback)
		{
			Instance().minimizeWindowCallback = callback;
		}

		void Window::SetCloseWindowCallback(CloseWindowCallback callback)
		{
			Instance().closeWindowCallback = callback;
		}

		void Window::SetFocusWindowCallback(FocusWindowCallback callback)
		{
			Instance().focusWindowCallback = callback;
		}

		bool Window::IsMinimized()
		{
			return Instance().isMinimized;
		}

		bool Window::IsHide()
		{
			return Instance().isHide;
		}

		bool Window::IsFullscreen()
		{
			return Instance().isFullscreen;
		}

		bool Window::IsFocused()
		{
			return Instance().isFocused;
		}

		void Window::SetIcons(const std::vector<Utils::ImagePtr>& icons)
		{
			for (auto icon : icons)
			{
				if (icon == nullptr)
					Debug::Logging::LogException("Window", "Icon " + icon->GetLoadedPath() + " is null");

				if (icon->GetFormat() != GPU::TextureFormat::RGBA)
					Debug::Logging::LogException("Window", "Icon " + icon->GetLoadedPath()  + " must have RGBA format");

				auto size = icon->GetSize();

				if (size.x != size.y)
					Debug::Logging::LogException("Window", "Icon " + icon->GetLoadedPath() + " must have same X and Y size");
			}

			GLFWimage* img = new GLFWimage[icons.size()];

			for (int i = 0; i < icons.size(); i++)
			{
				auto size = icons[i]->GetSize();

				img[i].height = (int)size.y;
				img[i].width = (int)size.x;
				img[i].pixels = icons[i]->GetData();
			}

			glfwSetWindowIcon(Instance().windowPtr, icons.size(), img);

			delete[] img;
		}

		glm::vec2 Window::GetScreenLimits()
		{
			auto& instance = Instance();

			if (!instance.isInitialized)
				Debug::Logging::LogException("Window", "Window is not initialized");

			GLFWmonitor* monitor = glfwGetPrimaryMonitor();
			const GLFWvidmode* mode = glfwGetVideoMode(monitor);

			return {mode->width, mode->height};
		}

		Window& Window::Instance()
		{
			static Window* instance = new Window();

			return *instance;
		}

		void Window::WindowResizeCallback(GLFWwindow* window, int width, int height)
		{
			auto& instance = Instance();

			instance.config.windowSize = { width, height };

			if (instance.resizeWindowCallback != nullptr)
				instance.resizeWindowCallback({ width, height });
		}

		void Window::WindowCloseCallback(GLFWwindow* window)
		{
			auto& instance = Instance();

			if (instance.closeWindowCallback != nullptr)
				instance.closeWindowCallback();
		}

		void Window::WindowPositionCallback(GLFWwindow* window, int xpos, int ypos)
		{
			auto& instance = Instance();

			instance.config.windowPosition = glm::vec2(xpos, ypos);

			if (instance.repositionWindowCallback != nullptr)
				instance.repositionWindowCallback({ xpos, ypos });
		}

		void Window::WindowMaximizeCallback(GLFWwindow* window, int maximized)
		{
			auto& instance = Instance();

			if (instance.maximizeWindowCallback != nullptr)
				instance.maximizeWindowCallback((bool)maximized);
		}

		void Window::WindowMinimizeCallback(GLFWwindow* window, int minimized)
		{
			auto& instance = Instance();

			instance.isMinimized = (bool)minimized;

			if (instance.minimizeWindowCallback != nullptr)
				instance.minimizeWindowCallback((bool)minimized);
		}

		void Window::WindowFocusCallback(GLFWwindow* window, int focused)
		{
			auto& instance = Instance();

			instance.isFocused = (bool)focused;

			if (instance.focusWindowCallback != nullptr)
				instance.focusWindowCallback((bool)focused);
		}
	}
}

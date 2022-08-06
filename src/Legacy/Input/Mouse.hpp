#pragma once
#include <PrimitiveEngine.hpp>

namespace PrimitiveEngine
{
	namespace Input
	{
		/// <summary>
		/// A class to read the mouse input.
		/// This class is a Singleton.
		/// </summary>
		class Mouse
		{
			friend class PrimitiveEngine::Window::Window;
		private:
			/// <summary>
			/// The mouse last saved position.
			/// Used to calculate mouse delta.
			/// </summary>
			glm::vec<2, int> lastPosition;

			/// <summary>
			/// The frame scroll of the mouse.
			/// </summary>
			float scroll;

			/// <summary>
			/// If the mouse is inside the display
			/// </summary>
			bool isInsideWindow;

			/// <summary>
			/// Callbacks for mouse events notification.
			/// </summary>
			MouseButtonCallback mouseButtonCallback;
			MousePositionCallback mousePositionCallback;
			MouseScrollCallback mouseScrollCallback;
			MouseEnterWindowCallback mouseEnterWindowCallback;

			/// <summary>
			/// Reference to current GLFW Window in use.
			/// </summary>
			GLFWwindow* windowPtr;
		public:
			/// <summary>
			/// Set callbacks to recieve mouse events.
			/// </summary>
			static void SetMouseButtonCallback(MouseButtonCallback callback);
			static void SetMousePositionCallback(MousePositionCallback callback);
			static void SetMouseScrollCallback(MouseScrollCallback callback);
			static void SetMouseEnterWindowCallback(MouseEnterWindowCallback callback);

			/// <summary>
			/// Get the current state of some mouse button.
			/// </summary>
			static InputAction GetMouseButtonState(const MouseButton button);

			/// <summary>
			/// Returns the current mouse position.
			/// </summary>
			static glm::vec<2, int> GetMousePosition();

			/// <summary>
			/// Returns the current mouse delta.
			/// </summary>
			static glm::vec<2, int> GetMouseVariation();

			/// <summary>
			/// Sets the mouse visualization mode.
			/// </summary>
			void SetMouseMode(const MouseMode mode);

			/// <summary>
			/// Get the mouse scroll.
			/// Based on current frame.
			/// </summary>
			float GetScroll();

			/// <summary>
			/// Get if the mouse is inside the window.
			/// </summary>
			bool IsMouseInsideWindow();
		private:
			Mouse() {};
			Mouse(Mouse const&);
			void operator=(Mouse const&);

			/// <summary>
			/// Returns current instance.
			/// </summary>
			static Mouse& Instance();

			/// <summary>
			/// State control.
			/// </summary>
			void Init(GLFWwindow* windowPtr);
			void Release();

			/// <summary>
			/// Callbacks to recieve events directly from GLFW.
			/// Internal usage.
			/// </summary>
			static void MasterCursorEnterWindow(GLFWwindow* window, int entered);
			static void MasterCursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
			static void MasterMouseButtonCallback(GLFWwindow* window, int button, int action, int mod);
			static void MasterScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
		};
	}
}
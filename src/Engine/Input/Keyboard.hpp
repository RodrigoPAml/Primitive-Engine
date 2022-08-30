 #pragma once
#include <PrimitiveEngine.hpp>

namespace PrimitiveEngine {
namespace Input {

	/// <summary>
	/// A class to read the keyboard input.
	/// This class is a Singleton.
	/// </summary>
	class Keyboard
	{
		friend class PrimitiveEngine::Window::Window;
	private:
		/// <summary>
		/// Callback to notify users about input event.
		/// </summary>
		std::map<std::string, KeyboardCallback> callbacks;

		/// <summary>
		/// To manage keys.
		/// </summary>
		std::set<KeyboardKey> frameClickedKeys;

		/// <summary>
		/// Reference to current GLFW Window in use.
		/// </summary>
		GLFWwindow* windowPtr;
	public:
		/// <summary>
		/// Register callback to recieve keyboard event.
		/// </summary>
		static void RegisterKeyboardEventCallback(const std::string& identifier, const KeyboardCallback callback);
		static void RemoveKeyboardEventCallback(const std::string& identifier);

		/// <summary>
		/// Get state of an key.
		/// </summary>
		static InputAction GetKeyState(const KeyboardKey key);
	private:
		Keyboard() {};
		Keyboard(Keyboard const&) {};
		void operator=(Keyboard const&);

		/// <summary>
		/// Returns current instance.
		/// </summary>
		static Keyboard& Instance();

		void Init(GLFWwindow* windowPtr);
		void Release();

		/// <summary>
		/// Recieve events directly from GLFW.
		/// Internal usage.
		/// </summary>
		static void MasterKeyboardEventCallback(GLFWwindow* window, int key, int scancode, int action, int mod);
	};
}}


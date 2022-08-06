#include <PrimitiveEngine.hpp>
#include "Keyboard.hpp"

namespace PrimitiveEngine
{
	namespace Input
	{
		void Keyboard::RegisterKeyboardEventCallback(const KeyboardCallback callback)
		{
			Instance().callback = callback;
		}

		InputAction Keyboard::GetKeyState(const KeyboardKey key)
		{
			auto&& instance = Instance();

			if(instance.frameClickedKeys.find(key) != instance.frameClickedKeys.end())
				return InputAction::REPEAT;

			return (InputAction)glfwGetKey(instance.windowPtr, (int)key);
		}

		Keyboard& Keyboard::Instance()
		{
			static Keyboard* keyboard = new Keyboard();

			return *keyboard;
		}

		void Keyboard::Init(GLFWwindow* windowPtr)
		{
			this->windowPtr = windowPtr;
			this->callback = nullptr;

			glfwSetKeyCallback(windowPtr, MasterKeyboardEventCallback);

			Debug::Logging::Log("Keyboard", "Initialized");
		}

		void Keyboard::Release()
		{
			glfwSetKeyCallback(windowPtr, nullptr);

			this->callback = nullptr;
			this->frameClickedKeys.clear();
			this->windowPtr = nullptr;

			Debug::Logging::Log("Keyboard", "Released");
		}

		void Keyboard::MasterKeyboardEventCallback(GLFWwindow* window, int key, int scancode, int action, int mod)
		{
			auto& keyboard = Instance();

			if ((InputAction)action == InputAction::REPEAT)
				keyboard.frameClickedKeys.insert((KeyboardKey)key);
			else if ((InputAction)action == InputAction::RELEASE)
				keyboard.frameClickedKeys.erase((KeyboardKey)key);

			if (keyboard.callback != nullptr)
				keyboard.callback((KeyboardKey)key, (InputAction)action, (InputModifier)mod);
		}
	}
}

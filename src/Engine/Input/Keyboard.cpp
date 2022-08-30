#include <PrimitiveEngine.hpp>
#include "Keyboard.hpp"

namespace PrimitiveEngine {
namespace Input {

	void Keyboard::RegisterKeyboardEventCallback(const std::string& identifier, const KeyboardCallback callback)
	{
		if(callback != nullptr)
			Instance().callbacks[identifier] = callback;
	}

	void Keyboard::RemoveKeyboardEventCallback(const std::string& identifier)
	{
		auto& instance = Instance();

		if(instance.callbacks.contains(identifier))
			instance.callbacks.erase(identifier);
	}

	InputAction Keyboard::GetKeyState(const KeyboardKey key)
	{
		auto instance = Instance();

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
		this->callbacks.clear();

		glfwSetKeyCallback(windowPtr, MasterKeyboardEventCallback);

		Debug::Logging::Log("Keyboard Initialized", Debug::LogSeverity::Notify, Debug::LogOrigin::Engine);
	}

	void Keyboard::Release()
	{
		glfwSetKeyCallback(windowPtr, nullptr);

		this->callbacks.clear();
		this->frameClickedKeys.clear();
		this->windowPtr = nullptr;

		Debug::Logging::Log("Keyboard Released", Debug::LogSeverity::Notify, Debug::LogOrigin::Engine);
	}

	void Keyboard::MasterKeyboardEventCallback(GLFWwindow* window, int key, int scancode, int action, int mod)
	{
		auto keyboard = Instance();

		if((InputAction)action == InputAction::REPEAT)
			keyboard.frameClickedKeys.insert((KeyboardKey)key);
		else if((InputAction)action == InputAction::RELEASE)
			keyboard.frameClickedKeys.erase((KeyboardKey)key);

		for(auto callback : keyboard.callbacks )
			callback.second((KeyboardKey)key, (InputAction)action, (InputModifier)mod);
	}
}}

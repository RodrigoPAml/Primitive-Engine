#pragma once
#include <PrimitiveEngine.hpp>

namespace PrimitiveEngine {
namespace Input {

	/// <summary>
	/// Callbacks for mouse events.
	/// </summary>
	typedef std::function<void(const MouseButton, const InputAction, const InputModifier)> MouseButtonCallback;
	typedef std::function<void(const glm::vec<2, int>&)> MousePositionCallback;
	typedef std::function<void(const float)> MouseScrollCallback;
	typedef std::function<void(const bool)> MouseEnterWindowCallback;

	/// <summary>
	/// Keyboard event callback.
	/// </summary>
	typedef std::function<void(const KeyboardKey, const InputAction, const InputModifier)> KeyboardCallback;
}}
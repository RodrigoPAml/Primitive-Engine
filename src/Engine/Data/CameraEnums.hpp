#pragma once
#include <PrimitiveEngine.hpp>

namespace PrimitiveEngine { 
namespace Camera
{
	/// <summary>
	/// Represents how a camera should move.
	/// </summary>
	enum class CameraMovement
	{
		FORWARD,
		BACKWARD,
		LEFT,
		RIGHT,
		UP,
		DOWN,
	};
}}
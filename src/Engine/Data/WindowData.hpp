#pragma once
#include <PrimitiveEngine.hpp>

namespace PrimitiveEngine {
namespace Window {

	/// <summary>
	/// Initial window configuration.
	/// </summary>
	struct WindowConfiguration
	{
		std::string windowName = "Primitive Engine";

		glm::vec2 windowPosition = { 40, 40 }, windowSize = { 800, 600 };

		std::uint8_t windowMSAA = 8;

		unsigned int openGlVersionMin = 3;
		unsigned int openGlVersionMax = 4;
	};
	
	/// <summary>
	/// Represents an item in a ListBox
	/// </summary>
	struct GUIListBoxItem
	{
		std::string value;

		glm::vec4 color;

		bool selected = false;

		GUIListBoxItem(std::string value, glm::vec4 color)
		{
			this->value = value;
			this->color = color;
		}
	};
}}
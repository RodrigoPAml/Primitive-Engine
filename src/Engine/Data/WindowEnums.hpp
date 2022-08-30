#pragma once
#include <PrimitiveEngine.hpp>

namespace PrimitiveEngine {
namespace Window {
	
	/// <summary>
	/// Flags for customize GUI Window.
	/// </summary>
	enum class GUIWindowFlags
	{
		None = ImGuiWindowFlags_None,
		TitleBar = ImGuiWindowFlags_NoTitleBar,
		NoResize = ImGuiWindowFlags_NoResize,
		NoMove = ImGuiWindowFlags_NoMove,
		NoScrollbar = ImGuiWindowFlags_NoScrollbar,
		NoScrollWithMouse = ImGuiWindowFlags_NoScrollWithMouse,
		NoCollapse = ImGuiWindowFlags_NoCollapse,
		AlwaysAutoResize = ImGuiWindowFlags_AlwaysAutoResize,
		NoBackground = ImGuiWindowFlags_NoBackground,
		NoSavedSettings = ImGuiWindowFlags_NoSavedSettings,
		NoMouseInputs = ImGuiWindowFlags_NoMouseInputs,
		MenuBar = ImGuiWindowFlags_MenuBar,
		HorizontalScrollbar = ImGuiWindowFlags_HorizontalScrollbar,
		NoFocusOnAppearing = ImGuiWindowFlags_NoFocusOnAppearing,
		NoBringToFrontOnFocus = ImGuiWindowFlags_NoBringToFrontOnFocus,
		AlwaysVerticalScrollbar = ImGuiWindowFlags_AlwaysVerticalScrollbar,
		AlwaysHorizontalScrollbar = ImGuiWindowFlags_AlwaysHorizontalScrollbar,
		AlwaysUseWindowPadding = ImGuiWindowFlags_AlwaysUseWindowPadding,
		NoNavInputs = ImGuiWindowFlags_NoNavInputs,
		NoNavFocus = ImGuiWindowFlags_NoNavFocus,
		UnsavedDocument = ImGuiWindowFlags_UnsavedDocument,
		NoNav = ImGuiWindowFlags_NoNavInputs | ImGuiWindowFlags_NoNavFocus,
		NoDecoration = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoCollapse,
		NoInputs = ImGuiWindowFlags_NoMouseInputs | ImGuiWindowFlags_NoNavInputs | ImGuiWindowFlags_NoNavFocus,
	};
}}
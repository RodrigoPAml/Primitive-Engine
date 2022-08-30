#pragma once
#include <PrimitiveEngine.hpp>

namespace PrimitiveEngine { 
namespace Window {
namespace GUI {

	void Init(GLFWwindow* windowPtr);
	void Release();

	// Frame limiters
	void BeginFrame();
	void EndFrame();

	// Texts
	void Text(const std::string& label);
	void DisabledText(const std::string& label);
	void BulletText(const std::string& label);
	void ColoredText(const std::string& label, const glm::vec4& color);
	void WrappedText(const std::string& label);

	// Buttons and Selectables
	bool CheckBox(const std::string& label, bool& checked);
	bool Button(const std::string& label);
	bool RadioButton(const std::string& label, bool& selected);
	bool Selectable(const std::string& label, bool& selected);

	// Images
	void Image(GPU::TexturePtr texture, const glm::vec2& size);
	bool ImageButton(GPU::TexturePtr texture, const glm::vec2& size);

	// Inputs
	bool Input(const std::string& label, std::string& text);
	bool Input(const std::string& label, const std::string& hint, std::string& text);
	bool Input(const std::string& label, double& val);
	bool Input(const std::string& label, float& val);
	bool Input(const std::string& label, int& val);
	bool Input(const std::string& label, glm::vec2& val);
	bool Input(const std::string& label, glm::vec3& val);
	bool Input(const std::string& label, glm::vec4& val);

	bool MultilineText(const std::string& label, std::string& text);

	// Drags
	bool Drag(const std::string& label, int& val);
	bool Drag(const std::string& label, float& val);
	bool Drag(const std::string& label, glm::vec2& val);
	bool Drag(const std::string& label, glm::vec3& val);
	bool Drag(const std::string& label, glm::vec4& val);

	// Sliders
	bool Slider(const std::string& label, const glm::vec<2,int>& limits, int& val);
	bool Slider(const std::string& label, const glm::vec2& limits, float& val);
	bool Slider(const std::string& label, const glm::vec2& limits, glm::vec2& val);
	bool Slider(const std::string& label, const glm::vec2& limits, glm::vec3& val);
	bool Slider(const std::string& label, const glm::vec2& limits, glm::vec4& val);

	// Color
	bool ColorSelectable(const std::string& label, glm::vec3& color);
	bool ColorSelectable(const std::string& label, glm::vec4& color);

	// List box
	void ListBox(const std::string& label, std::vector<GUIListBoxItem>& items);

	// Combo box
	void ComboBox(const std::string& label, const std::vector<std::string>& itens, int& currItem);

	// Tabs
	bool BeginTabBar(const std::string& label);
	void EndTabBar();

	bool BeginTabItem(const std::string& label);
	void EndTabItem();

	// Trees
	bool BeginTreeNode(const std::string& label);
	void EndTreeNode();

	// Window Componentes
	bool IsCurrentWindowAppearing();
	bool IsCurrentWindowCollased();
	bool IsCurrentWindowFocused();
	bool IsCurrentWindowHovered();

	void SetNextWindowPosition(const glm::vec2& pos);
	void SetNextWindowSize(const glm::vec2& size);
	void SetWindowPosition(const glm::vec2& pos);
	void SetWindowSize(const glm::vec2& size);

	glm::vec2 GetWindowPosition();
	glm::vec2 GetWindowSize();

	bool BeginWindow(const std::string& label, bool* open = nullptr, const std::set<GUIWindowFlags>& flags = { GUIWindowFlags::None});
	void EndWindow();

	void BeginHintWindow();
	void EndHintWindow();

	bool BeginPopUp(const std::string& label);
	void EndPopUp();
	void OpenPopUp(const std::string& label);

	bool Header(const std::string& label);

	// Layouts
	void ContinueSameLine(const float spacing = -1);
	void Separator();
	void Space();

	// GUI State
	bool IsCurrentItemClicked();
	bool IsCurrentItemActive();
	bool IsCurrentItemFocused();
	bool IsCurrentItemHovered();

	void SetNextItemWidth(float width);

	// Menus
	bool BeginMainMenuBar();
	void EndMainMenuBar();

	bool BeginMenuBar();
	void EndMenuBar();

	bool BeginMenu(const std::string& label, const bool enabled = true);
	void EndMenu();    

	bool MenuItem(const std::string& label, const bool enabled = true, const std::string& shortcut = "");
}}}
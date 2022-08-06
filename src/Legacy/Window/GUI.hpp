#pragma once
#include <PrimitiveEngine.hpp>

namespace PrimitiveEngine
{ 
	namespace Window
	{
		class GUI
		{
		public:
			// Frame limiters
			static void BeginFrame();
			static void EndFrame();

			// Texts
			static void Text(const std::string& text);
			static void DisabledText(const std::string& text);
			static void BulletText(const std::string& text);
			static void ColoredText(const std::string& text, const glm::vec4& color);
			static void WrappedText(const std::string& text);

			// Buttons and Selectables
			static bool	CheckBox(std::string id, bool& checked);
			static bool Button(const std::string& text);
			static bool RadioButton(const std::string& text, bool& selected);
			static bool Selectable(const std::string& text, bool& selected);

			// Images
			static void Image(GPU::TexturePtr texture, const glm::vec2& size, glm::vec2 uv1, glm::vec2 uv2);
	
			// Inputs
			static void Input(std::string id, std::string& text);
			static void Input(std::string id, const std::string& hint, std::string& text);
			static void Input(std::string id, double& val);
			static void Input(std::string id, float& val);
			static void Input(std::string id, int& val);
			static void Input(std::string id, glm::vec2& val);
			static void Input(std::string id, glm::vec3& val);
			static void Input(std::string id, glm::vec4& val);
			static void MultilineText(std::string id, std::string& text);

			// Drags
			static void Drag(std::string id, int& val);
			static void Drag(std::string id, float& val);
			static void Drag(std::string id, glm::vec2& val);
			static void Drag(std::string id, glm::vec3& val);
			static void Drag(std::string id, glm::vec4& val);

			// Sliders
			static void Slider(std::string id, const int max, const int min, int& val);
			static void Slider(std::string id, const float min, const float max, float& val);
			static void Slider(std::string id, const float min, const float max, glm::vec2& val);
			static void Slider(std::string id, const float min, const float max, glm::vec3& val);
			static void Slider(std::string id, const float min, const  float max, glm::vec4& val);

			// Color
			static void ColorSelectable(std::string id, glm::vec3& color);
			static void ColorSelectable(std::string id, glm::vec4& color);

			// List box
			static bool ListBox(std::string id, const std::vector<std::string>& itens, int& currItem, const int heightInItems = 10);

			// Combo box
			static void ComboBox(std::string id, const std::vector<std::string>& itens, int& currItem);

			// Trees
			static bool BeginTreeNode(const std::string& text);
			static void EndTreeNode();

			// Window Componentes
			static bool IsCurrentWindowAppearing();
			static bool IsCurrentWindowCollased();
			static bool IsCurrentWindowFocused();
			static bool IsCurrentWindowHovered();

			static void SetNextWindowPosition(const glm::vec2& pos);
			static void SetNextWindowSize(const glm::vec2& size);
			static glm::vec2 GetWindowPosition();
			static glm::vec2 GetWindowSize();

			static bool BeginWindow(const std::string& title, bool* open = nullptr, const std::set<GUIWindowFlags>& flags = { GUIWindowFlags::None});
			static void EndWindow();

			static void BeginHintWindow();
			static void EndHintWindow();

			static bool Header(const std::string& name);

			// Layouts
			static void ContinueSameLine(const float offset = 0, const float spacing = -1);
			static void Separator();
			static void Space();

			// GUI State
			static bool IsCurrentItemClicked();
			static bool IsCurrentItemActive();
			static bool IsCurrentItemFocused();
			static bool IsCurrentItemHovered();

			static void SetNextItemWidth(float width);

			// Menus
			static bool BeginMainMenuBar();
			static void EndMainMenuBar();

			static bool BeginMenuBar();
			static void EndMenuBar();

			static bool BeginMenu(const std::string& name, const bool enabled = true);
			static void EndMenu();    

			static bool MenuItem(const std::string& name, const std::string& shortcut, const bool enabled = true);
		private:
			void Init(GLFWwindow* windowPtr);
			void Release();
		};
	}
}
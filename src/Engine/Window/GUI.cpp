#include <PrimitiveEngine.hpp>
#include "GUI.hpp"

// ImGui
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

namespace PrimitiveEngine {
namespace Window {

	void GUI::BeginFrame()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void GUI::EndFrame()
	{
		ImGui::Render();

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void GUI::Text(const std::string& text)
	{
		ImGui::Text(text.c_str());
	}

	void GUI::DisabledText(const std::string& text)
	{
		ImGui::TextDisabled(text.c_str());
	}

	void GUI::BulletText(const std::string& text)
	{
		ImGui::BulletText(text.c_str());
	}

	void GUI::ColoredText(const std::string& text, const glm::vec4& color)
	{
		ImGui::TextColored(ImVec4(color.x, color.y, color.z, color.w), text.c_str());
	}

	void GUI::WrappedText(const std::string& text)
	{
		ImGui::TextWrapped(text.c_str());
	}

	bool GUI::CheckBox(const std::string& label, bool& checked)
	{
		auto id = "##" + label;

		ImGui::Checkbox(id.c_str(), &checked);

		return checked;
	}

	bool GUI::Button(const std::string& label)
	{
		return ImGui::Button(label.c_str());
	}

	bool GUI::RadioButton(const std::string& label, bool& selected)
	{
		ImGui::RadioButton(label.c_str(), selected);

		return selected;
	}

	bool GUI::Selectable(const std::string& label, bool& selected)
	{
		ImGui::Selectable(label.c_str(), &selected);
		return selected;
	}

	void GUI::Image(GPU::TexturePtr texture, const glm::vec2& size)
	{
		ImTextureID my_tex_id = ImTextureID(texture->GetId());
						
		ImGui::Image(my_tex_id, ImVec2(size.x, size.y), ImVec2(0, 0), ImVec2(1, 1));
	}

	bool GUI::ImageButton(GPU::TexturePtr texture, const glm::vec2& size)
	{
		ImTextureID my_tex_id = ImTextureID(texture->GetId());

		return ImGui::ImageButton(my_tex_id, ImVec2(size.x, size.y), ImVec2(0, 0), ImVec2(1, 1));
	}

	bool GUI::Input(const std::string& label, std::string& text)
	{
		auto id = "##" + label;

		char* cstr = new char[4096];
		strcpy(cstr, text.c_str());

		bool changed = ImGui::InputText(id.c_str(), cstr, 4096);

		text = cstr;
		delete[] cstr;

		return changed;
	}

	bool GUI::Input(const std::string& label, const std::string& hint, std::string& text)
	{
		auto id = "##" + label;

		char* cstr = new char[4096];
		strcpy(cstr, text.c_str());

		bool changed = ImGui::InputTextWithHint(id.c_str(), hint.c_str(), cstr, 4096);

		text = cstr;
		delete[] cstr;

		return changed;
	}

	bool GUI::Input(const std::string& label, double& val)
	{
		auto id = "##" + label;

		return ImGui::InputDouble(id.c_str(), &val, 0, 0, "%.6f");
	}

	bool GUI::Input(const std::string& label, float& val)
	{
		auto id = "##" + label;

		return ImGui::InputFloat(id.c_str(), &val, 0, 0, "%.3f");
	}

	bool GUI::Input(const std::string& label, int& val)
	{
		auto id = "##" + label;

		return ImGui::InputInt(id.c_str(), &val, 1, 100);
	}

	bool GUI::Input(const std::string& label, glm::vec2& val)
	{
		auto id = "##" + label;

		float v[2];

		v[0] = val.x;
		v[1] = val.y;

		bool changed = ImGui::InputFloat2(id.c_str(), v, "%.3f");

		val.x = v[0];
		val.y = v[1];

		return changed;
	}

	bool GUI::Input(const std::string& label, glm::vec3& val)
	{
		auto id = "##" + label;

		float v[3];

		v[0] = val.x;
		v[1] = val.y;
		v[2] = val.z;

		bool changed = ImGui::InputFloat3(id.c_str(), v, "%.3f");

		val.x = v[0];
		val.y = v[1];
		val.z = v[2];

		return changed;
	}

	bool GUI::Input(const std::string& label, glm::vec4& val)
	{
		auto id = "##" + label;

		float v[4];

		v[0] = val.x;
		v[1] = val.y;
		v[2] = val.z;
		v[3] = val.w;

		bool changed = ImGui::InputFloat2(id.c_str(), v, "%.3f");

		val.x = v[0];
		val.y = v[1];
		val.z = v[2];
		val.w = v[3];
	
		return changed;
	}

	bool GUI::MultilineText(const std::string& label, std::string& text)
	{
		auto id = "##" + label;

		char* cstr = new char[8096];
		strcpy(cstr, text.c_str());
		bool changed = ImGui::InputTextMultiline(id.c_str(), cstr, 8096, {0,0});

		text = cstr;
		delete[] cstr;

		return changed;
	}

	bool GUI::Drag(const std::string& label, int& val)
	{
		auto id = "##" + label;

		return ImGui::DragInt(id.c_str(), &val);
	}

	bool GUI::Drag(const std::string& label, float& val)
	{
		auto id = "##" + label;

		return ImGui::DragFloat(id.c_str(), &val);
	}

	bool GUI::Drag(const std::string& label, glm::vec2& val)
	{
		auto id = "##" + label;

		float v[2];

		v[0] = val.x;
		v[1] = val.y;

		bool changed = ImGui::DragFloat2(id.c_str(), v);

		val.x = v[0];
		val.y = v[1];

		return changed;
	}

	bool GUI::Drag(const std::string& label, glm::vec3& val)
	{
		auto id = "##" + label;

		float v[3];

		v[0] = val.x;
		v[1] = val.y;
		v[2] = val.z;

		bool changed = ImGui::DragFloat3(id.c_str(), v);

		val.x = v[0];
		val.y = v[1];
		val.z = v[2];

		return changed;
	}

	bool GUI::Drag(const std::string& label, glm::vec4& val)
	{
		auto id = "##" + label;

		float v[4];

		v[0] = val.x;
		v[1] = val.y;
		v[2] = val.z;
		v[3] = val.w;

		bool changed = ImGui::DragFloat4(id.c_str(), v);

		val.x = v[0];
		val.y = v[1];
		val.z = v[2];
		val.w = v[3];

		return changed;
	}

	bool GUI::Slider(const std::string& label, const glm::vec<2, int>& limits, int& val)
	{
		auto id = "##" + label;

		return ImGui::SliderInt(id.c_str(), &val, limits.x, limits.y, "%d");
	}

	bool GUI::Slider(const std::string& label, const glm::vec2& limits, float& val)
	{
		auto id = "##" + label;

		return ImGui::SliderFloat(id.c_str(), &val, limits.x, limits.y, "%.3f");
	}

	bool GUI::Slider(const std::string& label, const glm::vec2& limits, glm::vec2& val)
	{
		auto id = "##" + label;

		float v[2];

		v[0] = val.x;
		v[1] = val.y;

		bool changed = ImGui::SliderFloat2(id.c_str(), v, limits.x, limits.y, "%.3f");

		val.x = v[0];
		val.y = v[1];

		return changed;
	}

	bool GUI::Slider(const std::string& label, const glm::vec2& limits, glm::vec3& val)
	{
		auto id = "##" + label;

		float v[3];

		v[0] = val.x;
		v[1] = val.y;
		v[2] = val.z;

		bool changed = ImGui::SliderFloat3(id.c_str(), v, limits.x, limits.y, "%.3f");

		val.x = v[0];
		val.y = v[1];
		val.z = v[2];

		return changed;
	}

	bool GUI::Slider(const std::string& label, const glm::vec2& limits, glm::vec4& val)
	{
		auto id = "##" + label;

		float v[4];

		v[0] = val.x;
		v[1] = val.y;
		v[2] = val.z;
		v[3] = val.w;

		bool changed = ImGui::SliderFloat4(id.c_str(), v, limits.x, limits.y, "%.3f");

		val.x = v[0];
		val.y = v[1];
		val.z = v[2];
		val.w = v[3];

		return changed;
	}

	bool GUI::ColorSelectable(const std::string& label, glm::vec3& color)
	{
		auto id = "##" + label;

		float v[3];

		v[0] = color.x;
		v[1] = color.y;
		v[2] = color.z;

		bool changed = ImGui::ColorEdit3(id.c_str(), v);

		color.x = v[0];
		color.y = v[1];
		color.z = v[2];

		return changed;
	}

	bool GUI::ColorSelectable(const std::string& label, glm::vec4& color)
	{
		auto id = "##" + label;

		float v[4];

		v[0] = color.x;
		v[1] = color.y;
		v[2] = color.z;
		v[3] = color.w;

		bool changed = ImGui::ColorEdit4(id.c_str(), v);

		color.x = v[0];
		color.y = v[1];
		color.z = v[2];
		color.w = v[3];

		return changed;
	}

	void GUI::ListBox(
		const std::string& label,
		std::vector<GUIListBoxItem>& items
	)
	{
		auto id = "##" + label;

		ImGui::BeginListBox(id.c_str(), { -FLT_MIN, -FLT_MIN });

		for(GUIListBoxItem& row : items)
		{
			ImGui::Selectable(row.value.c_str(), row.selected);

			if (ImGui::IsItemClicked())
				row.selected = !row.selected;

			ImVec2 p_min = ImGui::GetItemRectMin();
			ImVec2 p_max = ImGui::GetItemRectMax();
			ImGui::GetWindowDrawList()->AddRectFilled(p_min, p_max, IM_COL32(row.color.r * 255, row.color.g * 255, row.color.b * 255, 80));
		}

		ImGui::EndListBox();
	}

	void GUI::ComboBox(const std::string& label, const std::vector<std::string>& itens, int& currItem)
	{
		auto id = "##" + label;

		if(currItem < 0 || currItem > itens.size() - 1)
			currItem = 0;

		if(ImGui::BeginCombo(id.c_str(), itens[currItem].c_str()))
		{
			for(int n = 0; n < itens.size(); n++)
			{
				bool is_selected = (currItem == n);

				if(ImGui::Selectable(itens[n].c_str(), is_selected))
					currItem = n;

				if(is_selected)
					ImGui::SetItemDefaultFocus();
			}

			ImGui::EndCombo();
		}
	}

	bool GUI::BeginTabBar(const std::string& label)
	{
		return ImGui::BeginTabBar(label.c_str());
	}

	void GUI::EndTabBar()
	{
		ImGui::EndTabBar();
	}

	bool GUI::BeginTabItem(const std::string& label)
	{
		return ImGui::BeginTabItem(label.c_str());
	}

	void GUI::EndTabItem()
	{
		ImGui::EndTabItem();
	}

	bool GUI::BeginTreeNode(const std::string& label)
	{
		return ImGui::TreeNode(label.c_str());
	}

	void GUI::EndTreeNode()
	{
		ImGui::TreePop();
	}

	bool GUI::IsCurrentWindowAppearing()
	{
		return ImGui::IsWindowAppearing();
	}

	bool GUI::IsCurrentWindowCollased()
	{
		return ImGui::IsWindowCollapsed();
	}

	bool GUI::IsCurrentWindowFocused()
	{
		return ImGui::IsWindowFocused();
	}

	bool GUI::IsCurrentWindowHovered()
	{
		return ImGui::IsWindowHovered();
	}

	void GUI::SetNextWindowPosition(const glm::vec2& pos)
	{
		ImGui::SetNextWindowPos(ImVec2(pos.x, pos.y));
	}

	void GUI::SetNextWindowSize(const glm::vec2& size)
	{
		ImGui::SetNextWindowSize(ImVec2(size.x, size.y));
	}

	void GUI::SetWindowPosition(const glm::vec2& pos)
	{
		ImGui::SetWindowPos({ pos.x, pos.y });
	}

	void GUI::SetWindowSize(const glm::vec2& size)
	{
		ImGui::SetWindowSize({ size.x, size.y });
	}

	glm::vec2 GUI::GetWindowPosition()
	{
		return {ImGui::GetWindowPos().x, ImGui::GetWindowPos().y};
	}

	glm::vec2 GUI::GetWindowSize()
	{
		return {ImGui::GetWindowSize().x, ImGui::GetWindowSize().y};
	}

	bool GUI::BeginWindow(const std::string& label, bool* open, const std::set<GUIWindowFlags>& flags)
	{
		int flagsCode = 0;

		for(GUIWindowFlags flag : flags)
		{
			flagsCode |=  (int)flag;
;			}

		return ImGui::Begin(label.c_str(), open, flagsCode);
	}

	void GUI::EndWindow()
	{
		ImGui::End();
	}

	void GUI::BeginHintWindow()
	{
		ImGui::BeginTooltip();
	}

	void GUI::EndHintWindow()
	{
		ImGui::EndTooltip();
	}

	bool GUI::BeginPopUp(const std::string& label)
	{
		return ImGui::BeginPopupContextItem(label.c_str());
	}

	void GUI::EndPopUp()
	{
		ImGui::EndPopup();
	}

	void GUI::OpenPopUp(const std::string& label)
	{
		ImGui::OpenPopup(label.c_str());
	}

	bool GUI::Header(const std::string& label)
	{
		return ImGui::CollapsingHeader(label.c_str());
	}

	void GUI::ContinueSameLine(float spacing)
	{
		ImGui::SameLine(0, spacing);
	}

	void GUI::Separator()
	{
		ImGui::Separator();
	}

	void GUI::Space()
	{
		ImGui::Spacing();
	}

	bool GUI::IsCurrentItemClicked()
	{
		return ImGui::IsItemClicked();
	}

	bool GUI::IsCurrentItemActive()
	{
		return ImGui::IsItemActive();
	}

	bool GUI::IsCurrentItemFocused()
	{
		return ImGui::IsItemFocused();
	}

	bool GUI::IsCurrentItemHovered()
	{
		return ImGui::IsItemHovered();
	}

	void GUI::SetNextItemWidth(float width)
	{
		ImGui::SetNextItemWidth(width);
	}

	bool GUI::BeginMainMenuBar()
	{
		return ImGui::BeginMainMenuBar();
	}

	void GUI::EndMainMenuBar()
	{
		return ImGui::EndMainMenuBar();
	}

	bool GUI::BeginMenuBar()
	{
		return ImGui::BeginMenuBar();
	}

	void GUI::EndMenuBar()
	{
		ImGui::EndMenuBar();
	}

	bool GUI::BeginMenu(const std::string& label, const bool enabled)
	{
		return ImGui::BeginMenu(label.c_str(), enabled);
	}

	void GUI::EndMenu()
	{
		ImGui::EndMenu();
	}

	bool GUI::MenuItem(const std::string& name, const bool enabled, const std::string& shortcut)
	{
		return ImGui::MenuItem(name.c_str(), shortcut.c_str(), nullptr, enabled);
	}

	void GUI::Init(GLFWwindow* windowPtr)
	{
		IMGUI_CHECKVERSION();

		ImGui::CreateContext();

		ImVec4* colors = ImGui::GetStyle().Colors;
		colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
		colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
		colors[ImGuiCol_WindowBg] = ImVec4(0.10f, 0.10f, 0.10f, 1.00f);
		colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		colors[ImGuiCol_PopupBg] = ImVec4(0.19f, 0.19f, 0.19f, 0.92f);
		colors[ImGuiCol_Border] = ImVec4(0.19f, 0.19f, 0.19f, 0.29f);
		colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.24f);
		colors[ImGuiCol_FrameBg] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
		colors[ImGuiCol_FrameBgHovered] = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
		colors[ImGuiCol_FrameBgActive] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
		colors[ImGuiCol_TitleBg] = ImVec4(0.26f, 0.26f, 0.26f, 1.00f);
		colors[ImGuiCol_TitleBgActive] = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
		colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
		colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
		colors[ImGuiCol_ScrollbarBg] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
		colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
		colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.40f, 0.40f, 0.40f, 0.54f);
		colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
		colors[ImGuiCol_CheckMark] = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
		colors[ImGuiCol_SliderGrab] = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
		colors[ImGuiCol_SliderGrabActive] = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
		colors[ImGuiCol_Button] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
		colors[ImGuiCol_ButtonHovered] = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
		colors[ImGuiCol_ButtonActive] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
		colors[ImGuiCol_Header] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
		colors[ImGuiCol_HeaderHovered] = ImVec4(0.00f, 0.00f, 0.00f, 0.36f);
		colors[ImGuiCol_HeaderActive] = ImVec4(0.20f, 0.22f, 0.23f, 0.33f);
		colors[ImGuiCol_Separator] = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
		colors[ImGuiCol_SeparatorHovered] = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
		colors[ImGuiCol_SeparatorActive] = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
		colors[ImGuiCol_ResizeGrip] = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
		colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
		colors[ImGuiCol_ResizeGripActive] = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
		colors[ImGuiCol_Tab] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
		colors[ImGuiCol_TabHovered] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
		colors[ImGuiCol_TabActive] = ImVec4(0.20f, 0.20f, 0.20f, 0.36f);
		colors[ImGuiCol_TabUnfocused] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
		colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
		colors[ImGuiCol_PlotLines] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
		colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
		colors[ImGuiCol_PlotHistogram] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
		colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
		colors[ImGuiCol_TableHeaderBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
		colors[ImGuiCol_TableBorderStrong] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
		colors[ImGuiCol_TableBorderLight] = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
		colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
		colors[ImGuiCol_TextSelectedBg] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
		colors[ImGuiCol_DragDropTarget] = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
		colors[ImGuiCol_NavHighlight] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
		colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 0.00f, 0.00f, 0.70f);
		colors[ImGuiCol_NavWindowingDimBg] = ImVec4(1.00f, 0.00f, 0.00f, 0.20f);
		colors[ImGuiCol_ModalWindowDimBg] = ImVec4(1.00f, 0.00f, 0.00f, 0.35f);

		ImGuiStyle& style = ImGui::GetStyle();
		style.WindowPadding = ImVec2(8.00f, 8.00f);
		style.FramePadding = ImVec2(5.00f, 2.00f);
		style.CellPadding = ImVec2(6.00f, 6.00f);
		style.ItemSpacing = ImVec2(6.00f, 6.00f);
		style.ItemInnerSpacing = ImVec2(6.00f, 6.00f);
		style.TouchExtraPadding = ImVec2(0.00f, 0.00f);
		style.IndentSpacing = 25;
		style.ScrollbarSize = 15;
		style.GrabMinSize = 10;
		style.WindowBorderSize = 1;
		style.ChildBorderSize = 1;
		style.PopupBorderSize = 1;
		style.FrameBorderSize = 1;
		style.TabBorderSize = 1;
		style.WindowRounding = 0;
		style.ChildRounding = 4;
		style.FrameRounding = 3;
		style.PopupRounding = 4;
		style.ScrollbarRounding = 9;
		style.GrabRounding = 3;
		style.LogSliderDeadzone = 4;
		style.TabRounding = 4;
		style.WindowTitleAlign.x = 0.5f;

		ImGui_ImplGlfw_InitForOpenGL(windowPtr, true);
		ImGui_ImplOpenGL3_Init("#version 330");
	}

	void GUI::Release()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}
}}
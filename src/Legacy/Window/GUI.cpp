#include <PrimitiveEngine.hpp>
#include "GUI.hpp"

// ImGui
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

namespace PrimitiveEngine
{
	namespace Window
	{
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

		bool GUI::CheckBox(std::string id, bool& checked)
		{
		    id = "##" + id;

			ImGui::Checkbox(id.c_str(), &checked);

			return checked;
		}

		bool GUI::Button(const std::string& text)
		{
			return ImGui::Button(text.c_str());
		}

		bool GUI::RadioButton(const std::string& text, bool& selected)
		{
			ImGui::RadioButton(text.c_str(), selected);

			return selected;
		}

		bool GUI::Selectable(const std::string& text, bool& selected)
		{
			ImGui::Selectable(text.c_str(), &selected);

			return selected;
		}

		void GUI::Image(GPU::TexturePtr texture, const glm::vec2& size, glm::vec2 uv1, glm::vec2 uv2)
		{
			ImTextureID my_tex_id = ImTextureID(texture->GetId());

			ImGui::Image(my_tex_id, ImVec2(size.x, size.y), ImVec2(uv1.x, uv1.y), ImVec2(uv2.x, uv2.y));
		}

		void GUI::Input(std::string id, std::string& text)
		{
			id = "##" + id;

			char* cstr = new char[4096];
			strcpy(cstr, text.c_str());

			ImGui::InputText(id.c_str(), cstr, 4096);

			text = cstr;
			delete[] cstr;
		}

		void GUI::Input(std::string id, const std::string& hint, std::string& text)
		{
			id = "##" + id;

			char* cstr = new char[4096];
			strcpy(cstr, text.c_str());

			ImGui::InputTextWithHint(id.c_str(), hint.c_str(), cstr, 4096);

			text = cstr;
			delete[] cstr;
		}

		void GUI::Input(std::string id, double& val)
		{
			id = "##" + id;

			ImGui::InputDouble(id.c_str(), &val, 0, 0, "%.6f");
		}

		void GUI::Input(std::string id, float& val)
		{
			id = "##" + id;

			ImGui::InputFloat(id.c_str(), &val, 0, 0, "%.3f");
		}

		void GUI::Input(std::string id, int& val)
		{
			id = "##" + id;

			ImGui::InputInt(id.c_str(), &val, 1, 100);
		}

		void GUI::Input(std::string id, glm::vec2& val)
		{
			id = "##" + id;

			float v[2];

			v[0] = val.x;
			v[1] = val.y;

			ImGui::InputFloat2(id.c_str(), v, "%.3f");

			val.x = v[0];
			val.y = v[1];
		}

		void GUI::Input(std::string id, glm::vec3& val)
		{
			id = "##" + id;

			float v[3];

			v[0] = val.x;
			v[1] = val.y;
			v[2] = val.z;

			ImGui::InputFloat3(id.c_str(), v, "%.3f");

			val.x = v[0];
			val.y = v[1];
			val.z = v[2];
		}

		void GUI::Input(std::string id, glm::vec4& val)
		{
			id = "##" + id;

			float v[4];

			v[0] = val.x;
			v[1] = val.y;
			v[2] = val.z;
			v[3] = val.w;

			ImGui::InputFloat2(id.c_str(), v, "%.3f");

			val.x = v[0];
			val.y = v[1];
			val.z = v[2];
			val.w = v[3];
		}

		void GUI::MultilineText(std::string id, std::string& text)
		{
			id = "##" + id;

			char* cstr = new char[8096];
			strcpy(cstr, text.c_str());
			ImGui::InputTextMultiline(id.c_str(), cstr, 8096, {0,0});

			text = cstr;
			delete[] cstr;
		}

		void GUI::Drag(std::string id, int& val)
		{
			id = "##" + id;

			ImGui::DragInt(id.c_str(), &val);
		}

		void GUI::Drag(std::string id, float& val)
		{
			id = "##" + id;

			ImGui::DragFloat(id.c_str(), &val);
		}

		void GUI::Drag(std::string id, glm::vec2& val)
		{
			id = "##" + id;

			float v[2];

			v[0] = val.x;
			v[1] = val.y;

			ImGui::DragFloat2(id.c_str(), v);

			val.x = v[0];
			val.y = v[1];
		}

		void GUI::Drag(std::string id, glm::vec3& val)
		{
			id = "##" + id;

			float v[3];

			v[0] = val.x;
			v[1] = val.y;
			v[2] = val.z;

			ImGui::DragFloat3(id.c_str(), v);

			val.x = v[0];
			val.y = v[1];
			val.z = v[2];
		}

		void GUI::Drag(std::string id, glm::vec4& val)
		{
			id = "##" + id;

			float v[4];

			v[0] = val.x;
			v[1] = val.y;
			v[2] = val.z;
			v[3] = val.w;

			ImGui::DragFloat4(id.c_str(), v);

			val.x = v[0];
			val.y = v[1];
			val.z = v[2];
			val.w = v[3];
		}

		void GUI::Slider(std::string id, const int max, const int min, int& val)
		{
			id = "##" + id;

			ImGui::SliderInt(id.c_str(), &val, min, max, "%d");
		}

		void GUI::Slider(std::string id, const float min, const float max, float& val)
		{
			id = "##" + id;

			ImGui::SliderFloat(id.c_str(), &val, min, max, "%.3f");
		}

		void GUI::Slider(std::string id, const float min, const float max, glm::vec2& val)
		{
			id = "##" + id;

			float v[2];

			v[0] = val.x;
			v[1] = val.y;

			ImGui::SliderFloat2(id.c_str(), v, min, max, "%.3f");

			val.x = v[0];
			val.y = v[1];
		}

		void GUI::Slider(std::string id, const float min, const float max, glm::vec3& val)
		{
			id = "##" + id;

			float v[3];

			v[0] = val.x;
			v[1] = val.y;
			v[2] = val.z;

			ImGui::SliderFloat3(id.c_str(), v, min, max, "%.3f");

			val.x = v[0];
			val.y = v[1];
			val.z = v[2];
		}

		void GUI::Slider(std::string id, const float min, const float max, glm::vec4& val)
		{
			id = "##" + id;

			float v[4];

			v[0] = val.x;
			v[1] = val.y;
			v[2] = val.z;
			v[3] = val.w;

			ImGui::SliderFloat4(id.c_str(), v, min, max, "%.3f");

			val.x = v[0];
			val.y = v[1];
			val.z = v[2];
			val.w = v[3];
		}

		void GUI::ColorSelectable(std::string id, glm::vec3& color)
		{
			id = "##" + id;

			float v[3];

			v[0] = color.x;
			v[1] = color.y;
			v[2] = color.z;

			ImGui::ColorEdit3(id.c_str(), v);

			color.x = v[0];
			color.y = v[1];
			color.z = v[2];
		}

		void GUI::ColorSelectable(std::string id, glm::vec4& color)
		{
			id = "##" + id;

			float v[4];

			v[0] = color.x;
			v[1] = color.y;
			v[2] = color.z;
			v[3] = color.w;

			ImGui::ColorEdit4(id.c_str(), v);

			color.x = v[0];
			color.y = v[1];
			color.z = v[2];
			color.w = v[3];
		}

		bool GUI::ListBox(std::string id, const std::vector<std::string>& itens, int& currItem, const int heightInItems)
		{
			id = "##" + id;

			ImGui::ListBoxHeader(id.c_str(), itens.size(), heightInItems);

			if(currItem > itens.size() - 1)
			{
				currItem = -1;
			}

			bool clicked = false;

			int i = 0;
			for(std::string item : itens)
			{
				bool isSelected = (i == currItem);

				if(ImGui::Selectable(item.c_str(), isSelected))
				{
					clicked = true;

					currItem = i;
				}

				i++;
			}

			ImGui::ListBoxFooter();

			return clicked;
		}

		void GUI::ComboBox(std::string id, const std::vector<std::string>& itens, int& currItem)
		{
			id = "##" + id;

			if(currItem < 0 || currItem > itens.size() - 1)
			{
				currItem = 0;
			}

			if(ImGui::BeginCombo(id.c_str(), itens[currItem].c_str()))
			{
				for(int n = 0; n < itens.size(); n++)
				{
					bool is_selected = (currItem == n);

					if(ImGui::Selectable(itens[n].c_str(), is_selected))
					{
						currItem = n;
					}

					if(is_selected)
					{
						ImGui::SetItemDefaultFocus();
					}
				}

				ImGui::EndCombo();
			}
		}

		bool GUI::BeginTreeNode(const std::string& text)
		{
			return ImGui::TreeNode(text.c_str());
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

		glm::vec2 GUI::GetWindowPosition()
		{
			return {ImGui::GetWindowPos().x, ImGui::GetWindowPos().y};
		}

		glm::vec2 GUI::GetWindowSize()
		{
			return {ImGui::GetWindowSize().x, ImGui::GetWindowSize().y};
		}

		bool GUI::BeginWindow(const std::string& title, bool* open, const std::set<GUIWindowFlags>& flags)
		{
			int flagsCode = 0;

			for(GUIWindowFlags flag : flags)
			{
				flagsCode |=  (int)flag;
;			}

			return ImGui::Begin(title.c_str(), open, flagsCode);
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

		bool GUI::Header(const std::string& name)
		{
			return ImGui::CollapsingHeader(name.c_str());
		}

		void GUI::ContinueSameLine(float offset, float spacing)
		{
			ImGui::SameLine(offset, spacing);
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

		bool GUI::BeginMenu(const std::string& name, const bool enabled)
		{
			return ImGui::BeginMenu(name.c_str(), enabled);
		}
		void GUI::EndMenu()
		{
			ImGui::EndMenu();
		}

		bool GUI::MenuItem(const std::string& name, const std::string& shortcut, const bool enabled)
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
	}
}
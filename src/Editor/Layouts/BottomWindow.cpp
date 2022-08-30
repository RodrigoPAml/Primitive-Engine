#include <PrimitiveEngine.hpp>
#include "BottomWindow.hpp"

namespace PrimitiveEngine
{
	namespace Editor
	{
		void BottomWindow::Awake()
		{
			this->logTab.Awake();
		}

		void BottomWindow::Start()
		{
			this->logTab.Start();
		}

		void BottomWindow::Update()
		{
			using namespace PrimitiveEngine::Window;
			using Window = PrimitiveEngine::Window::Window;

			auto size = Window::GetSize();

			if (this->reset)
			{
				GUI::SetNextWindowPosition({ 0, size.y * 0.7 });
				GUI::SetNextWindowSize({ size.x, (size.y * 0.3) });

				this->reset = false;
			}

			if (GUI::BeginWindow("Navigator", nullptr, { GUIWindowFlags::NoMove, GUIWindowFlags::NoCollapse }))
			{
				auto guiPosition = GUI::GetWindowPosition();
				auto guiSize = GUI::GetWindowSize();

				if (guiSize.x != size.x || guiPosition.y + guiPosition.y > size.y)
				{
					GUI::SetWindowPosition({ 0, size.y * 0.7 });
					GUI::SetWindowSize({ size.x, (size.y * 0.3) });
				}

				if (menuActivated == 2)
					this->logTab.DrawTop();

				if (GUI::BeginTabBar("NavigatorTabs"))
				{
					if (GUI::BeginTabItem("Files"))
					{
						menuActivated = 1;

						GUI::EndTabItem();
					}

					if (GUI::BeginTabItem("Logs"))
					{
						menuActivated = 2;
						this->logTab.Update();
						GUI::EndTabItem();
					}

					GUI::EndTabBar();
				}

				GUI::EndWindow();
			}
		}

		void BottomWindow::Destroy()
		{
			this->logTab.Destroy();
		}

		void BottomWindow::Reset()
		{
			this->logTab.Reset();

			this->reset = true;
		}
	}
}


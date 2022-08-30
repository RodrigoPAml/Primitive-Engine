#include <PrimitiveEngine.hpp>
#include "Editor.hpp"

namespace PrimitiveEngine
{
	namespace Editor
	{
		void Editor::Awake()
		{
			this->bottomBar.Awake();
		}

		void Editor::Start()
		{
			Debug::Logging::Log(
				"Editor started",
				Debug::LogSeverity::Warning,
				Debug::LogOrigin::Engine
			);

			this->bottomBar.Start();
		}

		void Editor::Update()
		{
			namespace GUI = PrimitiveEngine::Window::GUI;

			GUI::BeginFrame();

			this->bottomBar.Update();

			GUI::EndFrame();
		}

		void Editor::Destroy()
		{
			this->bottomBar.Destroy();

			Debug::Logging::Log(
				"Editor released",
				Debug::LogSeverity::Warning,
				Debug::LogOrigin::Engine
			);
		}
	}
}
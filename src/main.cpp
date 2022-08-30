#include <PrimitiveEngine.hpp>
#include <Editor/Editor.hpp>

int main()
{
	PrimitiveEngine::Editor::EditorConfiguration::Load();

	using namespace PrimitiveEngine::Window;
	using namespace PrimitiveEngine::GPU;
	using namespace PrimitiveEngine::Editor;
	using namespace PrimitiveEngine::Debug;

	Editor* editor = new Editor();
	editor->Awake();

	Window::LoadDependencies();
	Window::Init();
	Window::Maximize();

	editor->Start();

	while(Window::ShouldRun())
	{	
		Framebuffer::SetClearModes({ ClearMode::COLOR, ClearMode::DEPTH });
		Framebuffer::Clear({0.0f, 0.0f, 0.0f, 0.0f});

		editor->Update();

		Window::SwapAndPollEvents();
	}

	editor->Destroy();
	delete editor;

	Window::Destroy();

	return 0;
}
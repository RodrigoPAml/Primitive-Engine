#include <PrimitiveEngine.hpp>

int main()
{
	using namespace PrimitiveEngine::Window;
	using namespace PrimitiveEngine::Debug;
	using namespace PrimitiveEngine::GPU;
	using namespace PrimitiveEngine::Utils;
	using namespace PrimitiveEngine::Camera;
	using namespace PrimitiveEngine::Drawing;

	Window::Init();

	ImagePtr image(new Image(Path::GetCurrentPath() + "/../../../res/icon.png"));
	Window::SetIcons({ image });

	Camera2DPtr cam(new Camera2D());
	Camera2D::SetCurrentCamera(cam);

	while (Window::ShouldRun())
	{
		Primitives2D::DrawRectangle({ 100, 100 }, { 100, 100 }, 0, { 1, 0, 0 }, false);
		Primitives2D::DrawRectangle({ 200, 200 }, { 100, 100 }, 0, { 1, 1, 0 }, true);

		Window::SwapAndPollEvents();
	}

	Window::Destroy();

	return 0;
}
#include <PrimitiveEngine.hpp>
#include "TopBar.hpp"

namespace PrimitiveEngine
{
	namespace Editor
	{
		void TopBar::Reset()
		{
			this->reset;
		}

		void TopBar::DrawTopBar(Engine::Project& project)
		{
			using namespace PrimitiveEngine::Window;

			if (GUI::BeginMainMenuBar())
			{
				if (GUI::BeginMenu("File"))
				{
					if (GUI::MenuItem("Create Project", !project.IsLoaded()))
					{
						std::string filename = Utils::File::OpenFileDialog
						(
							"Select a file",
							true,
							"Primitive Project File\0*.primitive"
						);

						if (filename.length() != 0)
						{
							if (!filename.ends_with(".primitive"))
								project.Save(filename + ".primitive");
							else 
								project.Save(filename);
						}
					}

					GUI::MenuItem("Open Project", !project.IsLoaded());
					GUI::MenuItem("Save Project", project.IsLoaded());
					GUI::MenuItem("Exit", project.IsLoaded());

					GUI::EndMenu();
				}

				GUI::EndMainMenuBar();
			}
		}
	}
}


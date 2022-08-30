#pragma once
#include <PrimitiveEngine.hpp>
#include <Other/Project.hpp>

namespace PrimitiveEngine
{
	namespace Editor
	{
		class TopBar
		{
		private:
			bool reset = true;
		public:
			void Reset();
			void DrawTopBar(Engine::Project& project);
		};
	}
}
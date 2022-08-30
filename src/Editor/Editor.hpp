#pragma once
#include <PrimitiveEngine.hpp>

#include <Other/GameObject.hpp>
#include <Other/Project.hpp>

#include "Layouts/TopBar.hpp"
#include "Layouts/BottomWindow.hpp"

namespace PrimitiveEngine
{
	namespace Editor
	{
		class Editor : public Layout
		{
		private:
			BottomWindow bottomBar;
		public:
			Editor() = default;
			~Editor() = default;

			void Start();
			void Awake();
			void Update();
			void Destroy();
		};
	}
}
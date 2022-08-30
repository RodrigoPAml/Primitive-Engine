#pragma once
#include <PrimitiveEngine.hpp>
#include <Other/Project.hpp>

#include "LogTab.hpp"

namespace PrimitiveEngine
{
	namespace Editor
	{
		class BottomWindow : public Layout
		{
		private:
			LogTab logTab;

			bool reset = false;
			unsigned int menuActivated = -1;
		public:
			BottomWindow() = default;
			~BottomWindow() = default;

			void Awake();
			void Start();
			void Update();
			void Destroy();
			void Reset();
		};
	}
}
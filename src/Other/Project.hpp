#pragma once
#include <PrimitiveEngine.hpp>

namespace PrimitiveEngine
{
	namespace Engine
	{
		class Project
		{
		private:
			std::string name;

			bool isLoaded = false;
		public:
			void Save(const std::string& path);
			void Load(const std::string& path);
			bool IsLoaded() const;
		};
	}
}


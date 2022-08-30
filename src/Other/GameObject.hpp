#pragma once

#include <PrimitiveEngine.hpp>
#include <Other/Component.hpp>

namespace PrimitiveEngine
{
	namespace Engine
	{
		class GameObject
		{
		public:
			std::string id;

			GameObject* father;

			std::vector<GameObject> childrens;
			std::vector<Component> components;
		};
	}
}
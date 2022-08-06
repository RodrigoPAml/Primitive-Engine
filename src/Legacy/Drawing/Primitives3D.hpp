#pragma once
#include <PrimitiveEngine.hpp>

namespace PrimitiveEngine
{
	namespace Drawing
	{
		class Primitives3D
		{
			friend class PrimitiveEngine::Window::Window;
		private:
			GPU::VertexPtr meshCube;
			GPU::VertexPtr meshUnfilledCube;
			GPU::VertexPtr meshSphere;
			GPU::VertexPtr meshUnfilledSphere;
			GPU::VertexPtr meshPoint;
			GPU::VertexPtr meshLine;
			GPU::VertexPtr meshRect;
			GPU::VertexPtr meshUnfilledRect;
			GPU::VertexPtr meshCircle;
			GPU::VertexPtr meshUnfilledCircle;
			GPU::VertexPtr meshTriangle;

			GPU::ShaderPtr shader;
		public:
			static void DrawCube(const glm::vec3& position, const glm::vec3& size, const glm::vec3& eulerAngles, const glm::vec3& color, bool filled = true);

			static void DrawSphere(const glm::vec3& position, const glm::vec3& size, const glm::vec3& eulerAngles, const glm::vec3& color, bool filled = true);

			static void DrawPoint(const glm::vec3& position, const glm::vec3& color);

			static void DrawLine(const glm::vec3& pos1, const glm::vec3& pos2, const glm::vec3& color);

			static void DrawRect(const glm::vec3& position, const glm::vec3& size, const glm::vec3& eulerAngles, const glm::vec3& color, bool filled = true);

			static void DrawTriangle(const glm::vec3& pos1, const glm::vec3& pos2, const glm::vec3& pos3, const glm::vec3& color, bool filled = true);

			static void DrawCircle(const glm::vec3& pos, const glm::vec3& size, const glm::vec3& eulerAngles, const glm::vec3& color, bool filled = true);

			static void DrawMeshTest(GPU::VertexPtr mesh, glm::vec3 position, glm::vec3 color, GPU::DrawingType type);
		private:
			Primitives3D() {};
			void operator=(Primitives3D const&);

			/// <summary>
			/// Returns current instance.
			/// </summary>
			static Primitives3D& Instance();

			void Init();
			void Release();

			void Setup(const glm::vec3& position, const glm::vec3& size, const glm::vec3& eulerAngles, const glm::vec3& color);
		};
	}
}

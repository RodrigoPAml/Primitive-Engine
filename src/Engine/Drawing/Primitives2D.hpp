#pragma once
#include <PrimitiveEngine.hpp>

namespace PrimitiveEngine {
namespace Drawing {

	/// <summary>
	/// Draw 2D Primitives.
	/// </summary>
	class Primitives2D
	{
		friend class PrimitiveEngine::Window::Window;
	private:
		GPU::VertexPtr rectMesh;
		GPU::VertexPtr rectUnfilledMesh;
		GPU::VertexPtr circleMesh;
		GPU::VertexPtr circleUnfilledMesh;
		GPU::VertexPtr pointMesh; 
		GPU::VertexPtr lineMesh;
		GPU::VertexPtr triangleMesh;

		GPU::ShaderPtr shader;
	public:
		static void DrawRectangle(const glm::vec2& position, const glm::vec2& size, const float rotation, const glm::vec3& color, const bool filled = true);
		static void DrawCircle(const glm::vec2& position, const glm::vec2& size, const float rotation, const glm::vec3& color, const bool filled = true);
		static void DrawTriangle(const glm::vec2& pos1, const glm::vec2& pos2, const glm::vec2& pos3, const glm::vec3& color, const bool filled = true);
		static void DrawPoint(const glm::vec2& position, const glm::vec3& color);
		static void DrawLine(const glm::vec2& pos1, const glm::vec2& pos2, const glm::vec3& color);
	private:
		Primitives2D() {};
		void operator=(Primitives2D const&);

		/// <summary>
		/// Returns current instance.
		/// </summary>
		static Primitives2D& Instance();

		void Init();
		void Release();

		void Setup(const glm::vec2& position, const glm::vec2& size, const float rotation, const glm::vec3& color);
	};
}}

#pragma once
#include <PrimitiveEngine.hpp>

namespace PrimitiveEngine {
namespace Drawing {	

	/// <summary>
	/// Used to draw a texture.
	/// </summary>
	class TextureRenderer
	{
		friend class PrimitiveEngine::Window::Window;
	private:
		GPU::ShaderPtr shader;

		GPU::VertexPtr mesh;
	public:
		static void Draw(const GPU::TexturePtr texture, const glm::vec2& position, const glm::vec2& size, const float rotation);
	private:
		TextureRenderer() {};
		void operator=(TextureRenderer const&);

		/// <summary>
		/// Returns current instance.
		/// </summary>
		static TextureRenderer& Instance();

		void Init();
		void Release();
	};
}}
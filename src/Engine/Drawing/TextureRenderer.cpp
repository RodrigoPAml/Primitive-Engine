#include <PrimitiveEngine.hpp>
#include "TextureRenderer.hpp"

namespace PrimitiveEngine {
namespace Drawing {

	void TextureRenderer::Draw(const GPU::TexturePtr texture, const glm::vec2& position, const glm::vec2& size, const float rotation)
	{
		const Camera::Camera2DPtr cam = Camera::Camera2D::GetCurrentCamera();

		if (cam == nullptr)
			Debug::Logging::LogException("Attempt to draw a texture without a camera", Debug::LogOrigin::Engine);

		if (texture == nullptr)
			Debug::Logging::LogException("Attempt to draw an null texture", Debug::LogOrigin::Engine);

		auto instance = Instance();

		if (instance.shader == nullptr)
			Debug::Logging::LogException("Attempt to draw an texture without a shader", Debug::LogOrigin::Engine);

		if (instance.mesh == nullptr)
			Debug::Logging::LogException("Attempt to draw an texture without a mesh", Debug::LogOrigin::Engine);

		instance.shader->Use();

		glm::mat4 model(glm::mat4(1.0f));

		model = glm::translate(model, glm::vec3(position, 0.0f));
		model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));
		model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::scale(model, glm::vec3(size, 1.0f));

		texture->Use(0);

		instance.shader->SetMat4("model", model);
		instance.shader->SetMat4("projection", cam->GetOrthoMatrix());
		instance.shader->SetInt("image", 0);

		instance.mesh->Use();
		instance.mesh->Draw(GPU::DrawingType::TRIANGLES);
	}

	TextureRenderer& TextureRenderer::Instance()
	{
		static TextureRenderer* instance = new TextureRenderer();

		return *instance;
	}

	void TextureRenderer::Init()
	{
		const std::string vertShader = { 
			"#version 330 core\n"
			"layout(location = 0) in vec4 vertex;\n"
			"out vec2 uv;\n"
			"uniform mat4 model;\n"
			"uniform mat4 projection;\n"
			"void main()\n"
			"{\n"
			"  uv = vertex.zw;\n"
			"  gl_Position = projection * model * vec4(vertex.xy, 0.0, 1.0);\n"
			"}"
		};

		const std::string fragShader = {
			"#version 330 core\n"
			"out vec4 outColor;\n"
			"in vec2 uv;\n"
			"uniform sampler2D image;\n"
			"void main()\n"
			"{\n"
			"  vec4 texFrag = texture(image, uv);\n"
			"  if(texFrag.a < 0.5f)\n"
			"  {\n"
			"    discard;\n"
			"  }\n"
			"  outColor =  vec4(texFrag.xyz, 1.0f);\n"
			"}"
		};

		this->shader = GPU::ShaderPtr(new GPU::Shader(vertShader, fragShader, ""));

		float vertices[] =
		{
			0.0f, 1.0f, 0.0f, 1.0f,
			1.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 1.0f,
			1.0f, 1.0f, 1.0f, 1.0f,
			1.0f, 0.0f, 1.0f, 0.0f
		};

		const GPU::VertexElement element(GPU::VertexDataType::FLOAT, 4);
		const GPU::VertexDescriptor descriptor({{{element}, vertices, GPU::DataUse::STATIC_DRAW} }, 6);

		this->mesh = GPU::VertexPtr(new GPU::Vertex(descriptor));

		Debug::Logging::Log("TextureRenderer Initialized", Debug::LogSeverity::Notify, Debug::LogOrigin::Engine);
	}

	void TextureRenderer::Release()
	{
		mesh.~shared_ptr();
		shader.~shared_ptr();
		mesh = nullptr;
		shader = nullptr;

		Debug::Logging::Log("TextureRenderer Released", Debug::LogSeverity::Notify, Debug::LogOrigin::Engine);
	}
}}
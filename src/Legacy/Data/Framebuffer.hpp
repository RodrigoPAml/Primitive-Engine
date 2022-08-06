#pragma once
#include <PrimitiveEngine.hpp>

namespace PrimitiveEngine
{
	namespace GPU
	{
		#pragma region FramebufferData

		struct RenderBufferAttachment
		{
			RenderBufferAttachmentType type = RenderBufferAttachmentType::DONT_USE;

			RenderBufferFormat format = RenderBufferFormat::DEPTH32F_STENCIL8;

			glm::vec2 size = { 0,0 };

			RenderBufferAttachment() = default;

			RenderBufferAttachment(const RenderBufferAttachmentType type, const RenderBufferFormat format, const glm::vec2& size)
			{
				this->type = type;
				this->format = format;
				this->size = size;
			}
		};

		struct DepthAttachment
		{
			TexturePtr texture = nullptr;

			DepthAttachment() = default;

			DepthAttachment(const TexturePtr texture)
			{
				this->texture = texture;
			}
		};

		struct FramebufferConfiguration
		{
			std::vector<TexturePtr> textureAttachments;

			RenderBufferAttachment renderBufferAttachment;

			DepthAttachment depthAttachment;

			FramebufferConfiguration() = default;

			FramebufferConfiguration(
				const std::vector<TexturePtr>& textureAttachments,
				const RenderBufferAttachment& renderBufferAttachment,
				const DepthAttachment& depthAttachment
			)
			{
				this->textureAttachments = textureAttachments;
				this->renderBufferAttachment = renderBufferAttachment;
				this->depthAttachment = depthAttachment;
			}
		};

		#pragma endregion
	}
}
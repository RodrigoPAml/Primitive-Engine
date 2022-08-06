#include <PrimitiveEngine.hpp>
#include "Framebuffer.hpp"

namespace PrimitiveEngine
{
	namespace GPU
	{
		unsigned int Framebuffer::ClearModeSum = (unsigned int)ClearMode::COLOR;

		Framebuffer::Framebuffer(const FramebufferConfiguration& configuration)
		{
			this->id = 0;
			this->renderBufferId = 0;

			if(configuration.textureAttachments.empty())
				Debug::Logging::LogException("Framebuffer", "Attempt to create a framebuffer without texture attachments");

			glGenFramebuffers(1, &this->id);
			glBindFramebuffer(GL_FRAMEBUFFER, this->id);

			GLenum attach = GL_COLOR_ATTACHMENT0;

			unsigned int* attachments = new unsigned int[configuration.textureAttachments.size()]();

			for(auto i = 0; i < configuration.textureAttachments.size(); i++)
			{
				glFramebufferTexture2D(GL_FRAMEBUFFER, attach, GL_TEXTURE_2D, configuration.textureAttachments[i]->GetId(), 0);

				attachments[i] = attach;
				attach++;

				this->texturesAttachments.push_back(configuration.textureAttachments[i]);
			}

			if (configuration.textureAttachments.size() > 0)
				glDrawBuffers(configuration.textureAttachments.size(), attachments);

			if(configuration.depthAttachment.texture != nullptr)
				glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, configuration.depthAttachment.texture->GetId(), 0);
		
			delete[] attachments;

			if(configuration.renderBufferAttachment.type != RenderBufferAttachmentType::DONT_USE)
			{
				glGenRenderbuffers(1, &this->renderBufferId);
				glBindRenderbuffer(GL_RENDERBUFFER, this->renderBufferId);

				glRenderbufferStorage(
					GL_RENDERBUFFER, 
					(GLenum)configuration.renderBufferAttachment.format,
					configuration.renderBufferAttachment.size.x, 
					configuration.renderBufferAttachment.size.y
				);

				glFramebufferRenderbuffer(GL_FRAMEBUFFER, (GLenum)configuration.renderBufferAttachment.type, GL_RENDERBUFFER, this->renderBufferId);
			}

			if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
			{
				if (configuration.textureAttachments.empty())
					Debug::Logging::LogException("Framebuffer", "Failed to complete framebuffer creation");
			}

			glBindFramebuffer(GL_FRAMEBUFFER, 0);
			glBindRenderbuffer(GL_RENDERBUFFER, 0);

			if (this->id == 0)
				Debug::Logging::LogException("Framebuffer", "Failed to create framebuffer");

			if (this->renderBufferId == 0)
				Debug::Logging::LogException("Framebuffer", "Failed to create render buffer");
		}

		Framebuffer::~Framebuffer()
		{
			if(this->id != 0)
				glDeleteFramebuffers(1, &this->id);

			if (this->renderBufferId != 0)
				glDeleteRenderbuffers(1, &this->renderBufferId);

			glBindFramebuffer(GL_FRAMEBUFFER, 0);
			glBindRenderbuffer(GL_RENDERBUFFER, 0);
		}

		void Framebuffer::Use() 
		{
			if (this->renderBufferId == 0)
				Debug::Logging::LogException("Framebuffer", "Can't use an empty framebuffer");

			glBindFramebuffer(GL_FRAMEBUFFER, this->id);
		}

		unsigned int Framebuffer::GetAttachmentSize() const
		{
			return this->texturesAttachments.size();
		}

		TexturePtr Framebuffer::GetTextureAttachment(const unsigned int index) const
		{
			if(index < 0 || index > this->texturesAttachments.size())
				Debug::Logging::LogException("Framebuffer", "Can't access texture attachment out of index");

			return this->texturesAttachments[index];
		}

		void Framebuffer::ActiveDefault()
		{
			glBindFramebuffer(GL_FRAMEBUFFER, 0);
			glBindRenderbuffer(GL_RENDERBUFFER, 0);
		}

		void Framebuffer::SwitchViewPort(const glm::vec2& pos, const glm::vec2& size)
		{
			glViewport(pos.x, pos.y, size.x, size.y);
		}

		void Framebuffer::SetClearModes(const std::set<ClearMode>& clearModes)
		{
			if(clearModes.empty()) return;

			Framebuffer::ClearModeSum = 0;

			for(ClearMode mode : clearModes)
			{
				Framebuffer::ClearModeSum |= (unsigned int)mode;
			}
		}

		void Framebuffer::Clear(const glm::vec4& color)
		{
			glClearColor(color.x, color.y, color.z, color.w);

			glClear((GLbitfield)Framebuffer::ClearModeSum);
		}
	}
}
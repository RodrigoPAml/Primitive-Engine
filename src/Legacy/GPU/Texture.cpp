#include <PrimitiveEngine.hpp>
#include "Texture.hpp"

namespace PrimitiveEngine
{
	namespace GPU
	{
		Texture::Texture(const TextureDataConfiguration& configuration, Utils::ImagePtr image)
		{
			if (image == nullptr)
				throw new std::exception("Texture is null");

			this->id = 0;
			this->size = image->GetSize();
			this->format = image->GetFormat();

			glGenTextures(1, &this->id);
			glBindTexture(GL_TEXTURE_2D, this->id);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, (int)configuration.textureWrapS);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, (int)configuration.textureWrapT);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, (int)configuration.minifyingFilter);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, (int)configuration.magnificationFilter);

			if(configuration.textureWrapS == TextureWrap::CLAMP_TO_BORDER || configuration.textureWrapT == TextureWrap::CLAMP_TO_EDGE)
			{
				float color[] = { configuration.borderColor.x, configuration.borderColor.y, configuration.borderColor.z, 1.0f};
				glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color);
			}

			if(configuration.ansiotropicFilter > 0 && glfwExtensionSupported("GL_ARB_texture_filter_anisotropic"))
			{
				float largest_supported_anisotropy;
				glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &largest_supported_anisotropy);
				
				unsigned int supported = std::min((unsigned int)largest_supported_anisotropy, configuration.ansiotropicFilter);

				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, supported);
			}

			glTexImage2D(
				GL_TEXTURE_2D, 
				0, 
				(GLint)configuration.internalFormat,
				image->GetSize().x,
				image->GetSize().y,
				0, 
				(GLint)image->GetFormat(),
				(GLenum)configuration.pixelFormat,
				image->GetData()
			);

			if(configuration.minifyingFilter != MinifyingFilter::ONLY_LINEAR && configuration.minifyingFilter != MinifyingFilter::ONLY_NEAREST)
				glGenerateMipmap(GL_TEXTURE_2D);

			if (this->id == 0)
				Debug::Logging::LogException("Texture", "Failed to create shader, unknow exception");
		}

		Texture::Texture(const TextureConfiguration& configuration)
		{
			if (configuration.size.x <= 0 || configuration.size.y <= 0)
				throw new std::exception("Texture have invalid size");

			this->id = 0;
			this->size = configuration.size;
			this->format = configuration.format;

			glGenTextures(1, &this->id);
			glBindTexture(GL_TEXTURE_2D, this->id);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, (int)configuration.textureWrapS);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, (int)configuration.textureWrapT);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, (int)configuration.minifyingFilter);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, (int)configuration.magnificationFilter);

			if (configuration.textureWrapS == TextureWrap::CLAMP_TO_BORDER || configuration.textureWrapT == TextureWrap::CLAMP_TO_EDGE)
			{
				float color[] = { configuration.borderColor.x, configuration.borderColor.y, configuration.borderColor.z, 1.0f };
				glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color);
			}

			if (configuration.ansiotropicFilter > 0 && glfwExtensionSupported("GL_ARB_texture_filter_anisotropic"))
			{
				float largest_supported_anisotropy;
				glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &largest_supported_anisotropy);

				unsigned int supported = std::min((unsigned int)largest_supported_anisotropy, configuration.ansiotropicFilter);

				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, supported);
			}

			glTexImage2D(
				GL_TEXTURE_2D,
				0,
				(GLint)configuration.internalFormat,
				this->size.x,
				this->size.y,
				0,
				(GLint)this->format,
				(GLenum)configuration.pixelFormat,
				nullptr
			);

			if (configuration.minifyingFilter != MinifyingFilter::ONLY_LINEAR && configuration.minifyingFilter != MinifyingFilter::ONLY_NEAREST)
				glGenerateMipmap(GL_TEXTURE_2D);

			if (this->id == 0)
				Debug::Logging::LogException("Texture", "Failed to create shader, unknow exception");
		}

		Texture::~Texture()
		{
			if (this->id != 0)
				glDeleteTextures(1, &this->id);
		}

		unsigned int Texture::GetId() const
		{
			return this->id;
		}

		void Texture::Use(unsigned int slot) const
		{
			if(this->id == 0)
				Debug::Logging::LogException("Texture", "Cannot use a texture if its empty");

			glActiveTexture(GL_TEXTURE0 + slot);
			glBindTexture(GL_TEXTURE_2D, this->id);
		}

		void Texture::Modify(const glm::vec<2, unsigned int>& start, const glm::vec<2, unsigned int>& size, void* data) const
		{
			if (this->id == 0)
				Debug::Logging::LogException("Texture", "Cannot modify texture if its empty");

			if (start.x > this->size.x ||
				start.y > this->size.y ||
				start.x < 0 ||
				start.y < 0)
			{
				Debug::Logging::LogException("Texture", "Modifying  texture out of index");
			}

			if (start.x + size.x > this->size.x ||
				start.y + size.y > this->size.y ||
				start.x + size.x < 0 ||
				start.y + size.y < 0)
			{
				Debug::Logging::LogException("Texture", "Modifying  texture out of index");
			}

			glTexSubImage2D(
				GL_TEXTURE_2D, 
				0, 
				start.x, 
				start.y,
				size.x,
				size.y, 
				(GLenum)this->format, 
				GL_UNSIGNED_BYTE, 
				data
			);
		}

		void Texture::DisableTextureUnit(const unsigned int slot)
		{
			glActiveTexture(GL_TEXTURE0 + slot);
			glDisable(GL_TEXTURE_2D);
		}

		unsigned int Texture::GetMaxTextureUnits()
		{
			int max = 0;

			glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &max);

			return (unsigned int)max;
		}
	}
}

#include <PrimitiveEngine.hpp>
#include "Image.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace PrimitiveEngine
{
	namespace Utils
	{
		Image::Image(const std::string& path)
		{
			int numComponents = 0;
			this->data = stbi_load(path.c_str(), &this->size.x, &this->size.y, &numComponents, 0);

			if (!this->data)
				Debug::Logging::LogException("TextureData", "Failed to open texture: " + path);

			if (this->size.x <= 0 || this->size.y <= 0)
				Debug::Logging::LogException("TextureData", "Failed to open texture because size can't be zero or negative: " + path);

			this->path = path;

			switch (numComponents)
			{
				case 1:
					this->format = GPU::TextureFormat::R;
					break;
				case 3:
					this->format = GPU::TextureFormat::RGB;
					break;
				case 4:
					this->format = GPU::TextureFormat::RGBA;
					break;
				default:
					throw new std::exception(
						("Formato com " +
						std::to_string(numComponents) + 
						" componentes não é suportado ao abrir arquivo " 
						+ path).c_str()
					);
			}
		}

		Image::~Image()
		{
			if (this->data != nullptr)
				delete[] this->data;
		}

		void Image::SetSize(const glm::vec<2, int>& size)
		{
			this->size = size;
		}

		void Image::SetData(unsigned char* data)
		{
			this->data = data;
		}

		void Image::SetFormat(const  GPU::TextureFormat& format)
		{
			this->format = format;
		}

		glm::vec<2, int> Image::GetSize() const
		{
			return this->size;
		}

		unsigned char* Image::GetData() const
		{
			return this->data;
		}

		GPU::TextureFormat Image::GetFormat() const
		{
			return this->format;
		}
		std::string Image::GetLoadedPath() const
		{
			return this->path;
		}
	}
}
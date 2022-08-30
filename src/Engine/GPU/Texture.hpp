#pragma once
#include <PrimitiveEngine.hpp>

namespace PrimitiveEngine {
namespace GPU {

	/// <summary>
	/// Represents a texture in GPU memory.
	/// </summary>
	class Texture
	{
	private:
		/// <summary>
		/// Texture identifier.
		/// </summary>
		unsigned int id;

		/// <summary>
		/// Texture Size
		/// </summary>
		glm::vec<2, unsigned int> size;

		/// <summary>
		/// Texture format
		/// </summary>
		TextureFormat format;
	public:
		Texture(const TextureDataConfiguration& configuration, Utils::ImagePtr texture);
		Texture(const TextureConfiguration& configuration);
		~Texture();

		/// <summary>
		/// Return the texture id.
		/// </summary>
		unsigned int GetId() const;

		/// <summary>
		/// Activate texture in slot.
		/// </summary>
		void Use(const unsigned int slot) const;

		/// <summary>
		/// Modify texture data.
		/// </summary>
		void Modify(const glm::vec<2, unsigned int>& start, const glm::vec<2, unsigned int>& size, void* data) const;

		/// <summary>
		/// Disable texture in slot.
		/// </summary>
		/// <param name="slot"></param>
		static void DisableTextureUnit(const unsigned int slot);

		/// <summary>
		/// Get max slots for textures.
		/// </summary>
		static unsigned int GetMaxTextureUnits();
	};

	typedef std::shared_ptr<Texture> TexturePtr;
}}

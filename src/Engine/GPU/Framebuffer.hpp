#pragma once
#include <PrimitiveEngine.hpp>

namespace PrimitiveEngine {
namespace GPU {

	/// <summary>
	/// Represents a frame buffer in GPU.
	/// </summary>
	class Framebuffer
	{
	private:
		unsigned int id;
		unsigned int renderBufferId;

		std::vector<TexturePtr> texturesAttachments;
	public:
		Framebuffer(const FramebufferConfiguration& configuration);
		~Framebuffer();

		/// <summary>
		/// Use this frame buffer.
		/// </summary>
		void Use();

		/// <summary>
		/// Get the number of attachments.
		/// </summary>
		unsigned int GetAttachmentSize() const;

		/// <summary>
		/// Get a texture attachment.
		/// </summary>
		TexturePtr GetTextureAttachment(const unsigned int index) const;

		/// <summary>
		/// Activates the default frame buffer.
		/// </summary>
		static void ActiveDefault();

		/// <summary>
		/// Switch the view port.
		/// </summary>
		static void SwitchViewPort(const glm::vec2& pos, const glm::vec2& size);

		/// <summary>
		/// Control the clear mode of the current used frame buffer.
		/// </summary>
		static void SetClearModes(const std::set<ClearMode>& clearModes);

		/// <summary>
		/// Clear the current used frame buffer.
		/// </summary>
		static void Clear(const glm::vec4& color);
	private:
		static unsigned int ClearModeSum;
	};

	typedef std::shared_ptr<Framebuffer> FramebufferPtr;
}}

#pragma once
#include <PrimitiveEngine.hpp>

namespace PrimitiveEngine
{
	namespace GPU
	{
		/// <summary>
		/// Represents how data will be used in GPU memory.
		/// </summary>
		enum class DataUse
		{
			STREAM_DRAW = GL_STREAM_DRAW,
			STREAM_READ = GL_STREAM_READ,
			STREAM_COPY = GL_STREAM_COPY,
			STATIC_DRAW = GL_STATIC_DRAW,
			STATIC_READ = GL_STATIC_READ,
			STATIC_COPY = GL_STATIC_COPY,
			DYNAMIC_DRAW = GL_DYNAMIC_DRAW,
			DYNAMIC_READ = GL_DYNAMIC_READ,
			DYNAMIC_COPY = GL_DYNAMIC_COPY
		};

		/// <summary>
		/// The polygon mode will be used to draw.
		/// </summary>
		enum class PolygonMode
		{
			POINT = GL_POINT,
			LINE = GL_LINE,
			FILL = GL_FILL,
		};

		#pragma region TextureEnums
		
		/// <summary>
		/// OpenGL Texture Internal Format
		/// </summary>
		enum class TextureInternalFormat
		{
			DEPTH_COMPONENT = GL_DEPTH_COMPONENT,
			DEPTH_STENCIL = GL_DEPTH_STENCIL,
			R = GL_RED,
			RG = GL_RG,
			RGB = GL_RGB,
			RGBA = GL_RGBA,
			R8 = GL_R8,
			R8_SNORM = GL_R8_SNORM,
			R16 = GL_R16,
			R16_SNORM = GL_R16_SNORM,
			RG8 = GL_RG8,
			RG8_SNORM = GL_RG8_SNORM,
			RG16 = GL_RG16,
			RG16_SNORM = GL_RG16_SNORM,
			R3_G3_B2 = GL_R3_G3_B2,
			RGB4 = GL_RGB4,
			RGB5 = GL_RGB5,
			RGB8_SNORM = GL_RGB8_SNORM,
			RGB10 = GL_RGB10,
			RGB12 = GL_RGB12,
			RGB16_SNORM = GL_RGB16_SNORM,
			RGBA2 = GL_RGBA2,
			RGBA4 = GL_RGBA4,
			RGB5_A1 = GL_RGB5_A1,
			RGBA8 = GL_RGBA8,
			RGBA8_SNORM = GL_RGBA8_SNORM,
			RGB10_A2 = GL_RGB10_A2,
			RGB10_A2UI = GL_RGB10_A2UI,
			RGBA12 = GL_RGBA12,
			RGBA16 = GL_RGBA16,
			SRGB8 = GL_SRGB8,
			SRGB8_ALPHA8 = GL_SRGB8_ALPHA8,
			R16F = GL_R16F,
			RG16F = GL_RG16F,
			RGB16F = GL_RGB16F,
			RGBA16F = GL_RGBA16F,
			R32F = GL_R32F,
			RG32F = GL_RG32F,
			RGB32F = GL_RGB32F,
			RGBA32F = GL_RGBA32F,
			R11F_G11F_B10F = GL_R11F_G11F_B10F,
			RGB9_E5 = GL_RGB9_E5,
			R8I = GL_R8I,
			R8UI = GL_R8UI,
			R16I = GL_R16I,
			R16UI = GL_R16UI,
			R32I = GL_R32I,
			R32UI = GL_R32UI,
			RG8I = GL_RG8I,
			RG8UI = GL_RG8UI,
			RG16I = GL_RG16I,
			RG16UI = GL_RG16UI,
			RG32I = GL_RG32I,
			RG32UI = GL_RG32UI,
			RGB8I = GL_RGB8I,
			RGB8UI = GL_RGB8UI,
			RGB16I = GL_RGB16I,
			RGB16UI = GL_RGB16UI,
			RGB32I = GL_RGB32I,
			RGB32UI = GL_RGB32UI,
			RGBA8I = GL_RGBA8I,
			RGBA8UI = GL_RGBA8UI,
			RGBA16I = GL_RGBA16I,
			RGBA16UI = GL_RGBA16UI,
			RGBA32I = GL_RGBA32I,
			RGBA32UI = GL_RGBA32UI,
			COMPRESSED_RED = GL_COMPRESSED_RED,
			COMPRESSED_RG = GL_COMPRESSED_RG,
			COMPRESSED_RGB = GL_COMPRESSED_RGB,
			COMPRESSED_RGBA = GL_COMPRESSED_RGBA,
			COMPRESSED_SRGB = GL_COMPRESSED_SRGB,
			COMPRESSED_SRGB_ALPHA = GL_COMPRESSED_SRGB_ALPHA,
			COMPRESSED_RED_RGTC1 = GL_COMPRESSED_RED_RGTC1,
			COMPRESSED_SIGNED_RED_RGTC1 = GL_COMPRESSED_SIGNED_RED_RGTC1,
			COMPRESSED_RG_RGTC2 = GL_COMPRESSED_RG_RGTC2,
			COMPRESSED_SIGNED_RG_RGTC2 = GL_COMPRESSED_SIGNED_RG_RGTC2,
		};

		/// <summary>
		/// OpenGL Texture Format
		/// </summary>
		enum class TextureFormat
		{
			R = GL_RED,
			RG = GL_RG,
			RGB = GL_RGB,
			BGR = GL_BGR,
			RGBA = GL_RGBA,
			BGRA = GL_BGRA,
			RED_INTEGER = GL_RED_INTEGER,
			RG_INTEGER = GL_RG_INTEGER,
			RGB_INTEGER = GL_RGB_INTEGER,
			BGR_INTEGER = GL_BGR_INTEGER,
			RGBA_INTEGER = GL_RGBA_INTEGER,
			BGRA_INTEGER = GL_BGRA_INTEGER,
			STENCIL_INDEX = GL_STENCIL_INDEX,
			DEPTH_COMPONENT = GL_DEPTH_COMPONENT,
			DEPTH_STENCIL = GL_DEPTH_STENCIL,
		};

		/// <summary>
		/// OpenGL Texture Pixel Format
		/// </summary>
		enum class TexturePixelFormat
		{
			UNSIGNED_BYTE = GL_UNSIGNED_BYTE,
			BYTE = GL_BYTE,
			UNSIGNED_SHORT = GL_UNSIGNED_SHORT,
			SHORT = GL_SHORT,
			UNSIGNED_INT = GL_UNSIGNED_INT,
			INT = GL_INT,
			HALF_FLOAT = GL_HALF_FLOAT,
			FLOAT = GL_FLOAT,
			UNSIGNED_BYTE_3_3_2 = GL_UNSIGNED_BYTE_3_3_2,
			UNSIGNED_BYTE_2_3_3_REV = GL_UNSIGNED_BYTE_2_3_3_REV,
			UNSIGNED_SHORT_5_6_5 = GL_UNSIGNED_SHORT_5_6_5,
			UNSIGNED_SHORT_5_6_5_REV = GL_UNSIGNED_SHORT_5_6_5_REV,
			UNSIGNED_SHORT_4_4_4_4 = GL_UNSIGNED_SHORT_4_4_4_4,
			UNSIGNED_SHORT_4_4_4_4_REV = GL_UNSIGNED_SHORT_4_4_4_4_REV,
			UNSIGNED_SHORT_5_5_5_1 = GL_UNSIGNED_SHORT_5_5_5_1,
			UNSIGNED_SHORT_1_5_5_5_REV = GL_UNSIGNED_SHORT_1_5_5_5_REV,
			UNSIGNED_INT_8_8_8_8 = GL_UNSIGNED_INT_8_8_8_8,
			UNSIGNED_INT_8_8_8_8_REV = GL_UNSIGNED_INT_8_8_8_8_REV,
			UNSIGNED_INT_10_10_10_2 = GL_UNSIGNED_INT_10_10_10_2,
			UNSIGNED_INT_2_10_10_10_REV = GL_UNSIGNED_INT_2_10_10_10_REV
		};

		/// <summary>
		/// Texture Minifying method
		/// </summary>
		enum class MinifyingFilter
		{
			ONLY_NEAREST = GL_NEAREST,
			ONLY_LINEAR = GL_LINEAR,
			NEAREST_MIPMAP_NEAREST = GL_NEAREST_MIPMAP_NEAREST,
			LINEAR_MIPMAP_NEAREST = GL_LINEAR_MIPMAP_NEAREST,
			NEAREST_MIPMAP_LINEAR = GL_NEAREST_MIPMAP_LINEAR,
			LINEAR_MIPMAP_LINEAR = GL_LINEAR_MIPMAP_LINEAR
		};

		/// <summary>
		/// Texture Magnification method
		/// </summary>
		enum class MagnificationFilter
		{
			NEAREST = GL_NEAREST,
			LINEAR = GL_LINEAR
		};

		/// <summary>
		/// Texture Wrap Method
		/// </summary>
		enum class TextureWrap
		{
			CLAMP_TO_EDGE = GL_CLAMP_TO_EDGE,
			CLAMP_TO_BORDER = GL_CLAMP_TO_BORDER,
			MIRRORED_REPEAT = GL_MIRRORED_REPEAT,
			REPEATED = GL_REPEAT,
			MIRROR_CLAMP_TO_EDGE = GL_MIRROR_CLAMP_TO_EDGE
		};	

		#pragma endregion

		#pragma region VertexEnums

		/// <summary>
		/// The type used in a vertex.
		/// </summary>
		enum class VertexDataType
		{
			BYTE = GL_BYTE,
			UBYTE = GL_UNSIGNED_BYTE,
			SHORT = GL_SHORT,
			USHORT = GL_UNSIGNED_SHORT,
			INT = GL_INT,
			UINT = GL_UNSIGNED_INT,
			HALF_FLOAT = GL_HALF_FLOAT,
			FLOAT = GL_FLOAT,
			DOUBLE = GL_DOUBLE,
			INT_2_10_10_10_REV = GL_INT_2_10_10_10_REV,
			UINT_2_10_10_10_REV = GL_UNSIGNED_INT_2_10_10_10_REV
		};

		/// <summary>
		/// Represents how the data will be interpreted to draw.
		/// </summary>
		enum class DrawingType
		{
			POINTS = GL_POINTS,
			LINES = GL_LINES,
			LINE_LOOP = GL_LINE_LOOP,
			LINE_STRIP = GL_LINE_STRIP,
			TRIANGLES = GL_TRIANGLES,
			TRIANGLE_STRIP = GL_TRIANGLE_STRIP,
			TRIANGLE_FAN = GL_TRIANGLE_FAN,
			LINE_ADJACENCY = GL_LINES_ADJACENCY,
			LINE_STRIP_ADJACENCY = GL_LINE_STRIP_ADJACENCY,
			TRIANGLES_ADJACENCY = GL_TRIANGLES_ADJACENCY,
			TRIANGLE_STRIP_ADJACENCY = GL_TRIANGLE_STRIP_ADJACENCY,
		};

		#pragma endregion

		#pragma region TextureData

		/// <summary>
		/// Configuration so send a texture in memory to CPU.
		/// </summary>
		struct TextureDataConfiguration
		{
			MinifyingFilter minifyingFilter = MinifyingFilter::LINEAR_MIPMAP_LINEAR;
			MagnificationFilter magnificationFilter = MagnificationFilter::LINEAR;

			TextureWrap textureWrapT = TextureWrap::CLAMP_TO_BORDER;
			TextureWrap textureWrapS = TextureWrap::CLAMP_TO_BORDER;

			TextureInternalFormat internalFormat = TextureInternalFormat::RGB;
			TexturePixelFormat pixelFormat = TexturePixelFormat::FLOAT;

			glm::vec3 borderColor = { 0, 0, 0 };
			unsigned int ansiotropicFilter = 2;
		};

		/// <summary>
		/// Configuration to create an empty texture in CPU.
		/// </summary>
		struct TextureConfiguration : TextureDataConfiguration
		{
			TextureFormat format = TextureFormat::RGB;

			glm::vec<2, int> size = { 0,0 };
		};

		#pragma endregion

		#pragma region VertexData

		/// <summary>
		/// Describe an element that compose a vertex array.
		/// </summary>
		struct VertexElement
		{
			VertexDataType type = VertexDataType::FLOAT;

			unsigned int count = 0;

			bool isNormalized = false;

			VertexElement() = default;

			VertexElement(const VertexDataType type, const unsigned int count, const bool isNormalized = false)
			{
				this->type = type;
				this->count = count;
				this->isNormalized = isNormalized;
			}
		};

		/// <summary>
		/// Describes a buffer of vertices.
		/// </summary>
		struct VertexBufferDescriptor
		{
			std::vector<VertexElement> elements = std::vector<VertexElement>();

			void* data = nullptr;

			DataUse use = DataUse::STATIC_DRAW;

			VertexBufferDescriptor() = default;

			VertexBufferDescriptor(const std::vector<VertexElement>& elements, void* data, const DataUse use)
			{
				this->elements = elements;
				this->data = data;
				this->use = use;
			}
		};

		/// <summary>
		/// Describes a Vertex Array in GPU.
		/// </summary>
		struct VertexDescriptor
		{
			std::vector<VertexBufferDescriptor> buffers = std::vector<VertexBufferDescriptor>();

			unsigned int verticesCount = 0;

			VertexDescriptor() = default;

			VertexDescriptor(const std::vector<VertexBufferDescriptor>& buffers, const unsigned int verticesCount)
			{
				this->buffers = buffers;
				this->verticesCount = verticesCount;
			}
		};

		/// <summary>
		/// Describes a the indices of a Vertex Array.
		/// </summary>
		struct VertexIndicesDescriptor
		{
			unsigned int* indices = nullptr;

			unsigned int count = 0;

			DataUse use = DataUse::STATIC_DRAW;

			VertexIndicesDescriptor() = default;

			VertexIndicesDescriptor(unsigned int* indices, const unsigned int count, const DataUse use)
			{
				this->indices = indices;
				this->count = count;
				this->use = use;
			}
		};

		#pragma endregion 

		#pragma region FramebufferEnums

		enum class ClearMode
		{
			DEPTH = GL_DEPTH_BUFFER_BIT,
			STENCIL = GL_STENCIL_BUFFER_BIT,
			COLOR = GL_COLOR_BUFFER_BIT,
		};

		enum class RenderBufferAttachmentType
		{
			DONT_USE = GL_NONE,
			DEPTH_ATTACHMENT = GL_DEPTH_ATTACHMENT,
			STENCIL_ATTACHEMT = GL_STENCIL_ATTACHMENT,
			DEPTH_STENCIL_ATTACHMENT = GL_DEPTH_STENCIL_ATTACHMENT
		};

		enum class RenderBufferFormat
		{
			DEPTH_COMPONENT16 = GL_DEPTH_COMPONENT16,
			DEPTH_COMPONENT24 = GL_DEPTH_COMPONENT24,
			DEPTH_COMPONENT32F = GL_DEPTH_COMPONENT32F,
			DEPTH24_STENCIL8 = GL_DEPTH24_STENCIL8,
			DEPTH32F_STENCIL8 = GL_DEPTH32F_STENCIL8,
			STENCIL_INDEX8 = GL_STENCIL_INDEX8,
		};

		#pragma endregion

		/// <summary>
		/// Get the size of each vertex data type in bytes.
		/// </summary>
		static unsigned int GetSizeOfVertexDataType(const VertexDataType type)
		{
			switch (type)
			{
			case VertexDataType::BYTE:
				return 1;
			case VertexDataType::UBYTE:
				return 1;
			case VertexDataType::SHORT:
				return 2;
			case VertexDataType::USHORT:
				return 2;
			case VertexDataType::INT:
				return 4;
			case VertexDataType::UINT:
				return 4;
			case VertexDataType::HALF_FLOAT:
				return 2;
			case VertexDataType::FLOAT:
				return 4;
			case VertexDataType::DOUBLE:
				return 8;
			case VertexDataType::INT_2_10_10_10_REV:
				return 4;
			case VertexDataType::UINT_2_10_10_10_REV:
				return 4;
			default:
				return 0;
			}
		}
	}
}
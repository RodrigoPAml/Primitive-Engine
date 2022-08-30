#pragma once
#include <PrimitiveEngine.hpp>

namespace PrimitiveEngine {
namespace GPU {

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
}}
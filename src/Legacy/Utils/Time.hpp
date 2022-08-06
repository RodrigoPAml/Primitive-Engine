#pragma once
#include <PrimitiveEngine.hpp>

namespace PrimitiveEngine
{
	namespace Utils
	{
		namespace Time
		{
			/// <summary>
			/// Get executable time since start.
			/// </summary>
			double GetTimestamp();

			/// <summary>
			/// Get current DateTime.
			/// </summary>
			DateTime GetDateTime();
		};
	}
}

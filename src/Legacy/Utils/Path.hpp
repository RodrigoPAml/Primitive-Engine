#pragma once
#include <PrimitiveEngine.hpp>

namespace PrimitiveEngine
{
	namespace Utils
	{
		namespace Path
		{
			/// <summary>
			/// Get .exe current path.
			/// </summary>
			std::string GetCurrentPath();

			/// <summary>
			/// Check if give path is a directory.
			/// </summary>
			bool IsDirectory(const std::string& path);

			/// <summary>
			/// Check if give path is a file.
			/// </summary>
			bool IsFile(const std::string& path);

			/// <summary>
			/// Check if file or folder exists.
			/// </summary>
			bool Exists(const std::string& path);

			/// <summary>
			/// List files in path provided by string.
			/// </summary>
			/// <param name="returnOnlyName"> if only files/folders should be returned </param>
			std::vector<std::string> ListDirectories(const std::string& root, const bool returnOnlyName = true);

			/// <summary>
			/// Return last name from path.
			/// </summary>
			/// <param name="path"></param>
			std::string GetLastPartFromPath(const std::string path);

			/// <summary>
			/// Remove parts of provided path.
			/// </summary>
			std::string RemovePartsFromPath(const std::string& path, unsigned int n = 0);
		};
	}
}


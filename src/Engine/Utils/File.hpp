#pragma once
#include <PrimitiveEngine.hpp>

namespace PrimitiveEngine {
namespace Utils {
namespace File {

	/// <summary>
	/// Read file into string.
	/// </summary>
	std::string ReadFile(std::string file);

	/// <summary>
	/// Create directories provided by string.
	/// </summary>
	bool CreateDirectory(std::string path);

	/// <summary>
	/// Create file and write string content into it.
	/// </summary>
	/// <returns></returns>
	void CreateFile(std::string path, std::string content);

	/// <summary>
	/// Delete file or folder.
	/// </summary>
	/// <param name="deleteNonEmptyFolder"> If true, non empty folder will be deleted any way </param>
	bool Delete(std::string path, bool deleteNonEmptyFolder = false);

	/// <summary>
	/// Open File Dialog to select file.
	/// </summary>
	/// <param name="message"></param>
	/// <param name="types"></param>
	/// <returns></returns>
	std::string OpenFileDialog(const std::string& message, bool mustExist, const char* extension = "");
}}}

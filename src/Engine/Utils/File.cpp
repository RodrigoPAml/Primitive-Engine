#include <PrimitiveEngine.hpp>
#include "File.hpp"

#include <tchar.h>

namespace PrimitiveEngine {
namespace Utils {
namespace File {

	std::string ReadFile(std::string path)
	{
		std::ifstream file(path);
				
		if (!file.is_open())
			throw new std::runtime_error(std::string("Cannont open file: " + path).c_str());

		std::stringstream buffer;

		buffer << file.rdbuf();

		return buffer.str();
	}

	bool CreateDirectory(std::string path)
	{
		return std::filesystem::create_directories(path);
	}

	void CreateFile(std::string path, std::string content)
	{
		std::ofstream outfile(path);

		if (!outfile.is_open())
			throw new std::runtime_error(std::string("Cannont open file: " + path).c_str());

		outfile << content << std::endl;

		outfile.close();
	}

	bool Delete(std::string path, bool deleteNonEmptyFolder)
	{
		if(deleteNonEmptyFolder)
			return std::filesystem::remove_all(path);

		return std::filesystem::remove(path);
	}
			
	#include <Windows.h>
	std::string OpenFileDialog(const std::string& message, bool mustExist, const char* extension)
	{
		char filename[MAX_PATH];
				
		OPENFILENAMEA ofn;
		ZeroMemory(&filename, sizeof(filename));
		ZeroMemory(&ofn, sizeof(ofn));
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;
		ofn.lpstrFilter = extension;
		ofn.lpstrFile = filename;
		ofn.nMaxFile = MAX_PATH;
		ofn.lpstrTitle = message.c_str();

		if(mustExist)
			ofn.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;
		else
			ofn.Flags = OFN_DONTADDTORECENT;

		if (GetOpenFileNameA(&ofn))
			return std::string(filename);

		return "";
	}
}}}

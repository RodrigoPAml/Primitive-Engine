#include <PrimitiveEngine.hpp>
#include "File.hpp"

namespace PrimitiveEngine
{
	namespace Utils
	{
		namespace File
		{
			std::string ReadFile(std::string path)
			{
				std::ifstream file(path);
				
				if (!file.is_open())
					throw new std::exception(std::string("Cannont open file: " + path).c_str());

				std::stringstream buffer;

				buffer << file.rdbuf();

				return buffer.str();
			}

			bool CreateDirectory(std::string path)
			{
				return std::filesystem::create_directories(path);
			}

			bool CreateFile(std::string path, std::string content)
			{
				std::ofstream outfile(content);

				if (!outfile.is_open())
					return false;

				outfile << content << std::endl;

				outfile.close();

				return true;
			}

			bool Delete(std::string path, bool deleteNonEmptyFolder)
			{
				if(deleteNonEmptyFolder)
					return std::filesystem::remove_all(path);

				return std::filesystem::remove(path);
			}
		}
	}
}

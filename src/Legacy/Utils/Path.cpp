#include <PrimitiveEngine.hpp>
#include "Path.hpp"

#include <Windows.h>

namespace PrimitiveEngine
{
	namespace Utils
	{
		namespace Path
		{
			std::string GetCurrentPath()
			{
				char buffer[MAX_PATH];

				GetModuleFileNameA(NULL, buffer, MAX_PATH);

				return std::string(buffer);
			}

			bool IsDirectory(const std::string& path)
			{
				return std::filesystem::is_directory(path);
			}

			bool IsFile(const std::string& path)
			{
				return std::filesystem::is_regular_file(path);
			}

			bool Exists(const std::string& path)
			{
				return std::filesystem::exists(path);
			}

			std::vector<std::string> ListDirectories(const std::string& root, const bool returnOnlyName)
			{
				std::vector<std::string> paths;

				for (auto& it : std::filesystem::directory_iterator(root))
				{
					if (returnOnlyName)
					{
						std::string name = GetLastPartFromPath(it.path().generic_string());

						paths.push_back(name);
					}
					else
						paths.push_back(it.path().generic_string());
				}

				return paths;
			}

			std::string GetLastPartFromPath(const std::string path)
			{
				int size = path.find_last_of('/');

				if (size != -1)
				{
					return path.substr(size + 1);
				}
				else
				{
					return path;
				}
			}

			std::string RemovePartsFromPath(const std::string& path, unsigned int parts)
			{
				if (!path.empty())
				{
					int cut = path.size();

					for (int i = path.size() - 1; i >= 0; i--)
					{
						if (parts == 0) break;

						if (path[i] == '/' || path[i] == '\\')
						{
							cut = i;
							parts--;
						}
					}

					return path.substr(0, cut);
				}

				return path;
			}
		}
	}
}

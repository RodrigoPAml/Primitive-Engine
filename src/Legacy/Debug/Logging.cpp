#include <PrimitiveEngine.hpp>
#include "Logging.hpp"

namespace PrimitiveEngine
{
	namespace Debug
	{
		void Logging::Log(const std::string& module, const std::string& content, const std::source_location& location)
		{
			auto& instance = Instance();
			
			const std::string id = {
				"[Date: " + Utils::Time::GetDateTime().ToStringDateTime() +
				" File: " + location.file_name() +
				" Function: " + location.function_name() + '-' + std::to_string(location.line()) +
				"]\n[" + module + "]: "
			};

			if(instance.config.logConsole)
				std::cout << id << content << '\n';

			if(instance.file.is_open() && instance.config.logFile)
				instance.file << id << content << '\n';
		}

		void Logging::LogException(const std::string& module, const std::string& content, const bool release, const std::source_location& location)
		{
			Log(module, content, location);

			if (release)
				Instance().Release();

			throw new std::exception(content.c_str());
		}

		Logging& Logging::Instance()
		{
			static Logging* instance = new Logging();

			return *instance;
		}

		void Logging::Init(const LoggingConfiguration& logConfig)
		{
			this->config = logConfig;

			if (logConfig.logFile)
			{
				std::string filename = Utils::Time::GetDateTime().ToFileNameDateTime() + ".log";

				Utils::File::CreateDirectory("logs");

				this->file = std::ofstream(("logs/" + filename).c_str());
			}

			Log("Logging", "Initialized");
		}

		void Logging::Release()
		{
			Log("Logging", "Released");

			if(this->file.is_open())
				this->file.close();
		}
	}
}
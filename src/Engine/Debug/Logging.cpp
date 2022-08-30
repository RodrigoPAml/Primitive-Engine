#include <PrimitiveEngine.hpp>
#include "Logging.hpp"

namespace PrimitiveEngine {
namespace Debug {

	LoggingConfiguration Logging::GetConfiguration()
	{
		return Instance().config;
	}

	void Logging::SetConfiguration(const LoggingConfiguration& config)
	{
		Instance().config = config;
	}

	void Logging::RegisterLogCallback(const std::string& identifier, LogCallback callback)
	{
		if(callback != nullptr)
			Instance().callbacks[identifier] = callback;
	}

	void Logging::RemoveLogCallback(const std::string& identifier)
	{
		auto& instance = Instance();

		if(instance.callbacks.contains(identifier))
			instance.callbacks.erase(identifier);
	}

	void Logging::UserLog(std::string& content, const LogSeverity severity)
	{
		auto& instance = Instance();
		auto datetime = Utils::Time::GetDateTime();

		const std::string contentId = {
			datetime.ToStringDateTime() + "|||" +
			LogOriginToString(LogOrigin::UserGenerated) + "|" +
			LogSeverityToString(severity) + "|"
		};

		for(auto callback : instance.callbacks)
			callback.second(Utils::Time::GetDateTime(), content, severity, LogOrigin::UserGenerated, "", "");

		if(instance.config.logConsole)
			std::cout << contentId << content << '\n';

		if(instance.file.is_open() && instance.config.logFile)
			instance.file << contentId << content << '\n';
	}

	void Logging::Log(
		const std::string& content,
		const LogSeverity severity,
		const LogOrigin origin,
		const std::source_location& location
	)
	{
		auto& instance = Instance();
			
		const std::string contentId = {
			Utils::Time::GetDateTime().ToStringDateTime() + "|" +
			location.file_name() + "|" +
			location.function_name() + ':' + std::to_string(location.line()) + "|" +
			LogOriginToString(origin) + "|" +
			LogSeverityToString(severity) + "|"
		};

		for(auto callback : instance.callbacks)
			callback.second(
				Utils::Time::GetDateTime(), 
				content, 
				severity, 
				origin, 
				location.function_name() + ':' + std::to_string(location.line()), 
				location.file_name()
			);

		if(instance.config.logConsole)
			std::cout << contentId << content << '\n';

		if(instance.file.is_open() && instance.config.logFile)
			instance.file << contentId << content << '\n';
	}

	void Logging::LogException(
		const std::string& content, 
		const LogOrigin origin,
		const bool release, 
		const std::source_location& location
	)
	{
		Log(content, LogSeverity::Error, origin, location);

		if(release)
			Instance().Release();

		throw new std::runtime_error(content.c_str());
	}

	Logging& Logging::Instance()
	{
		static Logging* instance = new Logging();

		return *instance;
	}

	void Logging::Init(const LoggingConfiguration& logConfig)
	{
		this->config = logConfig;

		if(logConfig.logFile)
		{
			std::string filename = Utils::Time::GetDateTime().ToFileNameDateTime() + ".csv";

			Utils::File::CreateDirectory("logs");

			this->file = std::ofstream(("logs/" + filename).c_str());
		}

		Log("Logging Initialized", LogSeverity::Notify, LogOrigin::Engine);
	}

	void Logging::Release()
	{
		this->callbacks.clear();

		Log("Logging Released", LogSeverity::Notify, LogOrigin::Engine);

		if(this->file.is_open())
			this->file.close();
	}
}}
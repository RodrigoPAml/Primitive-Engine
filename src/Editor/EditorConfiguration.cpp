#include <PrimitiveEngine.hpp>
#include "EditorConfiguration.hpp"

namespace PrimitiveEngine {
namespace Editor {
namespace EditorConfiguration {

	void Save()
	{
		using json = nlohmann::json;
		using namespace PrimitiveEngine::Utils;
		using namespace PrimitiveEngine::Debug;

		auto debugConfig = Debugging::GetConfiguration();
		auto loggingConfig = Logging::GetConfiguration();

		json jsonFile = {
			{"debugging.autoLogGLFWErrors", debugConfig.autoLogGLFWErrors},
			{"debugging.autoLogOpenGLErrors", debugConfig.autoLogOpenGLErrors},
			{"debugging.enableGlfwDebugging", debugConfig.enableGlfwDebugging},
			{"debugging.enableOpenGLDebugging", debugConfig.enableOpenGLDebugging},
			{"debugging.severities", debugConfig.severities},
			{"logging.logConsole", loggingConfig.logConsole},
			{"logging.logFile", loggingConfig.logFile},
		};

		File::CreateFile("editor_config.json", jsonFile.dump(4));
	}

	void Load()
	{
		using json = nlohmann::json;
		using namespace PrimitiveEngine::Utils;
		using namespace PrimitiveEngine::Debug;

		std::string rawJson = "";
		json data;

		try
		{
			rawJson  = File::ReadFile("editor_config.json");
			data = json::parse(rawJson);
		}
		catch(...)
		{
			// Create and empty one if its invalid.
			Save();

			return;
		}

		DebugConfiguration debugConfig;

		debugConfig.autoLogGLFWErrors = data["debugging.autoLogGLFWErrors"];
		debugConfig.autoLogOpenGLErrors = data["debugging.autoLogGLFWErrors"];
		debugConfig.enableGlfwDebugging = data["debugging.enableGlfwDebugging"];
		debugConfig.enableOpenGLDebugging = data["debugging.enableOpenGLDebugging"];
		debugConfig.severities.clear();

		auto severitiesData = data["debugging.severities"];

		for (auto it = severitiesData.begin(); it != severitiesData.end(); ++it)
		{
			int value = it.value();

			debugConfig.severities.insert((Debug::OpenGlErrorSeverity)value);
		}

		LoggingConfiguration loggingConfig;

		loggingConfig.logConsole = data["logging.logConsole"];
		loggingConfig.logFile = data["logging.logFile"];

		Debugging::SetConfiguration(debugConfig);
		Logging::SetConfiguration(loggingConfig);
	}
}}}
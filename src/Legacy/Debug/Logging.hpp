#pragma once
#include <PrimitiveEngine.hpp>

namespace PrimitiveEngine
{
	namespace Debug
	{
		/// <summary>
		/// Used to logs events of the program.
		/// Allows to log events of openGL, GLFW and user provided.
		/// This class is a Singleton.
		/// </summary>
		class Logging
		{
			friend class PrimitiveEngine::Window::Window;
		private:
			/// <summary>
			/// File to output log.
			/// </summary>
			std::ofstream file;

			/// <summary>
			/// The current logging configuration;
			/// </summary>
			LoggingConfiguration config;
		public:
			/// <summary>
			/// Log something.
			/// </summary>
			static void Log(const std::string& module, const std::string& content, const std::source_location& location = std::source_location::current());

			/// <summary>
			/// Log and throw exception.
			/// </summary>
			static void LogException(const std::string& module, const std::string& content, const bool release = false, const std::source_location& location = std::source_location::current());
		private:
			Logging() {};
			Logging(Logging const&);
			void operator=(Logging const&);

			/// <summary>
			/// Returns current instance.
			/// </summary>
			/// <returns></returns>
			static Logging& Instance();

			/// <summary>
			/// Initializate the loggin. 
			/// Used from Window Context initialization.
			/// </summary>
			void Init(const LoggingConfiguration& logConfig);

			/// <summary>
			/// Release resources, like closing the log file.
			/// </summary>
			void Release();
		};
	}
}
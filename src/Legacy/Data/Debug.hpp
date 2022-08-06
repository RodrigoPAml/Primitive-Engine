#pragma once
#include <PrimitiveEngine.hpp>

namespace PrimitiveEngine
{
	namespace Debug
	{
		#pragma region ErrorEnums
		
		/// <summary>
		/// Represents an GLFW Error.
		/// </summary>
		enum class GLFWError
		{
			NO_ERROR = GLFW_NO_ERROR,
			API_UNAVAILABLE = GLFW_API_UNAVAILABLE,
			FORMAT_UNAVAILABLE = GLFW_FORMAT_UNAVAILABLE,
			INVALID_ENUM = GLFW_INVALID_ENUM,
			INVALID_VALUE = GLFW_INVALID_VALUE,
			NO_CURRENT_CONTEXT = GLFW_NO_CURRENT_CONTEXT,
			NOT_INITIALIZED = GLFW_NOT_INITIALIZED,
			OUT_OF_MEMORY = GLFW_OUT_OF_MEMORY,
			PLATFORM_ERROR = GLFW_PLATFORM_ERROR,
			VERSION_UNAVAILABLE = GLFW_VERSION_UNAVAILABLE
		};

		/// <summary>
		/// Represents an OpenGL Error.
		/// </summary>
		enum class OpenGlError
		{
			NO_ERROR = GL_NO_ERROR,
			INVALID_ENUM = GL_INVALID_ENUM,
			INVALID_VALUE = GL_INVALID_VALUE,
			INVALID_OPERATION = GL_INVALID_OPERATION,
			STACK_OVERFLOW = GL_STACK_OVERFLOW,
			STACK_UNDERFLOW = GL_STACK_UNDERFLOW,
			OUT_OF_MEMORY = GL_OUT_OF_MEMORY,
			INVALID_FRAMEBUFFER_OPERATION = GL_INVALID_FRAMEBUFFER_OPERATION,
			CONTEXT_LOST = GL_CONTEXT_LOST,
			TABLE_TOO_LARGE = GL_TABLE_TOO_LARGE,
		};

		/// <summary>
		/// Represents the source of an OpenGL Error.
		/// </summary>
		enum class OpenGlErrorSource
		{
			SOURCE_API = GL_DEBUG_SOURCE_API,
			SOURCE_WINDOW_SYSTEM = GL_DEBUG_SOURCE_WINDOW_SYSTEM,
			SOURCE_SHADER_COMPILER = GL_DEBUG_SOURCE_SHADER_COMPILER,
			SOURCE_THIRD_PARTY = GL_DEBUG_SOURCE_THIRD_PARTY,
			SOURCE_APPLICATION = GL_DEBUG_SOURCE_APPLICATION,
			SOURCE_OTHER = GL_DEBUG_SOURCE_OTHER
		};

		/// <summary>
		/// Represents the type of an OpenGL Error.
		/// </summary>
		enum class OpenGlErrorType
		{
			TYPE_ERROR = GL_DEBUG_TYPE_ERROR,
			TYPE_DEPRECATED_BEHAVIOR = GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR,
			TYPE_UNDEFINED_BEHAVIOR = GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR,
			TYPE_PORTABILITY = GL_DEBUG_TYPE_PORTABILITY,
			TYPE_PERFORMANCE = GL_DEBUG_TYPE_PERFORMANCE,
			TYPE_MARKER = GL_DEBUG_TYPE_MARKER,
			TYPE_PUSH_GROUP = GL_DEBUG_TYPE_PUSH_GROUP,
			TYPE_POP_GROUP = GL_DEBUG_TYPE_POP_GROUP,
			TYPE_OTHER = GL_DEBUG_TYPE_OTHER
		};

		/// <summary>
		/// Represents the severity of an OpenGL Error.
		/// </summary>
		enum class OpenGlErrorSeverity
		{
			SEVERITY_HIGH = GL_DEBUG_SEVERITY_HIGH,
			SEVERITY_MEDIUM = GL_DEBUG_SEVERITY_MEDIUM,
			SEVERITY_LOW = GL_DEBUG_SEVERITY_LOW,
			SEVERITY_NOTIFICATION = GL_DEBUG_SEVERITY_NOTIFICATION,
		};

		#pragma endregion

		#pragma region ErrorCallbacks

		/// <summary>
		/// Callback to recieve errors events
		/// </summary>
		typedef std::function<void(std::string)> ErrorCallback;

		/// <summary>
		/// GLFW Callback to recieve errors events
		/// </summary>
		typedef std::function<void(GLFWError, std::string)> GLFWErrorCallback;

		/// <summary>
		/// OpenGL Callback to recieve errors events
		/// </summary>
		typedef std::function<void(OpenGlErrorType, OpenGlErrorSource, OpenGlErrorSeverity, std::string)> OpenGlErrorCallback;

		#pragma endregion	

		/// <summary>
		/// Debug configuration.
		/// </summary>
		struct DebugConfiguration
		{
			/// <summary>
			/// Determines if GLFW will notify erros via callback
			/// </summary>
			bool enableGlfwDebugging = true;

			/// <summary>
			/// Determines if OpenGL will notify erros via callback
			/// </summary>
			bool enableOpenGLDebugging = true;

			/// <summary>
			/// If errors from GLFW should be automatically logged.
			/// </summary>
			bool autoLogGLFWErrors = true;

			/// <summary>
			/// If errors from OpenGL should be automatically logged.
			/// </summary>
			bool autoLogOpenGLErrors = true;

			/// <summary>
			/// The severities that should be considered.
			/// </summary>
			std::set<OpenGlErrorSeverity> severities = {
				OpenGlErrorSeverity::SEVERITY_LOW,
				OpenGlErrorSeverity::SEVERITY_MEDIUM,
				OpenGlErrorSeverity::SEVERITY_HIGH,
			};
		};

		/// <summary>
		/// Logging Configuration
		/// </summary>
		struct LoggingConfiguration
		{
			/// <summary>
			/// If logs will be showed in console.
			/// </summary>
			bool logConsole = true;

			/// <summary>
			/// If logs will be saved in log file.
			/// </summary>
			bool logFile = true;
		};
	}
}
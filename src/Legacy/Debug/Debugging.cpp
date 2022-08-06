#include <PrimitiveEngine.hpp>
#include "Debugging.hpp"

namespace PrimitiveEngine
{
	namespace Debug
	{
		GLFWError Debugging::GetGLFWError(std::string& errorMsg)
		{
			const char* description;

			GLFWError error = (GLFWError)glfwGetError(&description);

			if (description)
				errorMsg = description;

			return error;
		}

		OpenGlError Debugging::GetOpenGlError()
		{
			return (OpenGlError)glGetError();
		}

		void Debugging::RegisterCallbacks(ErrorCallback callback, GLFWErrorCallback glfwCallback, OpenGlErrorCallback openGlCallback)
		{
			auto& instance = Instance();

			instance.callback = callback;
			instance.glfwCallback = glfwCallback;
			instance.openGlCallback = openGlCallback;
		}

		std::string Debugging::ErrorToString(const OpenGlError value)
		{
			switch(value)
			{
				case OpenGlError::NO_ERROR:
					return "NO_ERROR";
				case OpenGlError::INVALID_ENUM:
					return "INVALID_ENUM";
				case OpenGlError::INVALID_VALUE:
					return "INVALID_VALUE";
				case OpenGlError::INVALID_OPERATION:
					return "INVALID_OPERATION";
				case OpenGlError::STACK_OVERFLOW:
					return "STACK_OVERFLOW";
				case OpenGlError::STACK_UNDERFLOW:
					return "STACK_UNDERFLOW";
				case OpenGlError::OUT_OF_MEMORY:
					return "OUT_OF_MEMORY";
				case OpenGlError::INVALID_FRAMEBUFFER_OPERATION:
					return "INVALID_FRAMEBUFFER_OPERATION";
				default:
					return "?";
			}
		}

		std::string Debugging::ErrorToString(const GLFWError value)
		{
			switch(value)
			{
				case GLFWError::NO_ERROR:
					return "NO_ERROR";
				case GLFWError::API_UNAVAILABLE:
					return "API_UNAVAILABLE";
				case GLFWError::FORMAT_UNAVAILABLE:
					return "FORMAT_UNAVAILABLE";
				case GLFWError::INVALID_ENUM:
					return "INVALID_ENUM";
				case GLFWError::INVALID_VALUE:
					return "INVALID_VALUE";
				case GLFWError::NO_CURRENT_CONTEXT:
					return "NO_CURRENT_CONTEXT";
				case GLFWError::NOT_INITIALIZED:
					return "NOT_INITIALIZED";
				case GLFWError::OUT_OF_MEMORY:
					return "OUT_OF_MEMORY";
				case GLFWError::PLATFORM_ERROR:
					return "PLATFORM_ERROR";
				case GLFWError::VERSION_UNAVAILABLE:
					return "VERSION_UNAVAILABLE";
				default:
					return "?";
			}
		}

		std::string Debugging::ErrorToString(const OpenGlErrorSource value)
		{
			switch(value)
			{
				case OpenGlErrorSource::SOURCE_API:
					return "SOURCE_API";
				case OpenGlErrorSource::SOURCE_WINDOW_SYSTEM:
					return "SOURCE_WINDOW_SYSTEM";
				case OpenGlErrorSource::SOURCE_SHADER_COMPILER:
					return "SOURCE_SHADER_COMPILER";
				case OpenGlErrorSource::SOURCE_THIRD_PARTY:
					return "SOURCE_THIRD_PARTY";
				case OpenGlErrorSource::SOURCE_APPLICATION:
					return "SOURCE_APPLICATION";
				case OpenGlErrorSource::SOURCE_OTHER:
					return "SOURCE_OTHER";
				default:
					return "?";
			}
		}

		std::string Debugging::ErrorToString(const OpenGlErrorType value)
		{
			switch(value)
			{
				case OpenGlErrorType::TYPE_ERROR:
					return "TYPE_ERROR";
				case OpenGlErrorType::TYPE_DEPRECATED_BEHAVIOR:
					return "TYPE_DEPRECATED_BEHAVIOR";
				case OpenGlErrorType::TYPE_UNDEFINED_BEHAVIOR:
					return "TYPE_UNDEFINED_BEHAVIOR";
				case OpenGlErrorType::TYPE_PORTABILITY:
					return "TYPE_PORTABILITY";
				case OpenGlErrorType::TYPE_PERFORMANCE:
					return "TYPE_PERFORMANCE";
				case OpenGlErrorType::TYPE_MARKER:
					return "TYPE_MARKER";
				case OpenGlErrorType::TYPE_PUSH_GROUP:
					return "TYPE_PUSH_GROUP";
				case OpenGlErrorType::TYPE_POP_GROUP:
					return "TYPE_POP_GROUP";
				case OpenGlErrorType::TYPE_OTHER:
					return "TYPE_OTHER";
				default:
					return "?";
			}
		}

		std::string Debugging::ErrorToString(const OpenGlErrorSeverity value)
		{
			switch(value)
			{
				case OpenGlErrorSeverity::SEVERITY_HIGH:
					return "SEVERITY_HIGH";
				case OpenGlErrorSeverity::SEVERITY_MEDIUM:
					return "SEVERITY_MEDIUM";
				case OpenGlErrorSeverity::SEVERITY_LOW:
					return "SEVERITY_LOW";
				case OpenGlErrorSeverity::SEVERITY_NOTIFICATION:
					return "SEVERITY_NOTIFICATION";
				default:
					return "?";
			}
		}

		Debugging& Debugging::Instance()
		{
			static Debugging* instance = new Debugging();

			return *instance;
		}

		void Debugging::Init(const DebugConfiguration& config)
		{
			this->callback = nullptr;
			this->glfwCallback = nullptr;
			this->openGlCallback = nullptr;
			this->config = config;

			Logging::Log("Debugging", "Initialized");
		}

		void Debugging::Release()
		{
			this->callback = nullptr;
			this->glfwCallback = nullptr;
			this->openGlCallback = nullptr;

			Logging::Log("Debugging", "Released");
		}

		void Debugging::GLFW_ERROR_CALLBACK(int code, const char* description)
		{
			auto& instance = Instance();

			if (instance.glfwCallback != nullptr)
				instance.glfwCallback((GLFWError)code, description);

			if (instance.config.autoLogGLFWErrors)
			{
				std::ostringstream stream;

				stream << '[' << Utils::Time::GetDateTime().ToStringDateTime() << ']'
					<< "[GLFW]: Error of type "
					<< ErrorToString((GLFWError)code)
					<< " - Message: "
					<< description;

				Logging::Log("Debugging", stream.str());
			}
		}

		void GLAPIENTRY Debugging::OPENGL_ERROR_CALLBACK(
			GLenum source,
			GLenum type,
			GLuint id,
			GLenum severity,
			GLsizei length,
			const GLchar* message,
			const void* userParam)
		{
			auto& instance = Instance();

			if (instance.openGlCallback)
				instance.openGlCallback((OpenGlErrorType)type, (OpenGlErrorSource)source, (OpenGlErrorSeverity)severity, message);

			if (instance.config.autoLogOpenGLErrors)
			{
				OpenGlErrorSeverity severityEnum = (OpenGlErrorSeverity)severity;

				if (instance.config.severities.find(severityEnum) != instance.config.severities.end())
				{
					std::ostringstream stream;

					stream << '[' << Utils::Time::GetDateTime().ToStringDateTime() << ']'
						   << "[OpenGL]: Error of Type: " << ErrorToString((OpenGlErrorType)type) << '\n'
						   << "from Source: " << ErrorToString((OpenGlErrorSource)source) << '\n'
						   << "with Severity: " << ErrorToString((OpenGlErrorSeverity)severity) << '\n'
						   << "Message: " << message;

					Logging::Log("Debugging", stream.str());
				}
			}
		}
	}
}
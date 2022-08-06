#pragma once
#include <PrimitiveEngine.hpp>

namespace PrimitiveEngine
{
	/// <summary>
	/// Allows to get errors from GLFW and OpenGL.
	/// Also allows to convert errors enums to string.
	/// This class is a singleton.
	/// </summary>
	namespace Debug
	{
		class Debugging
		{
			friend class PrimitiveEngine::Window::Window;
		private:
			/// <summary>
			/// Callback for user recieve errors.
			/// </summary>
			ErrorCallback callback;

			/// <summary>
			/// Callback for user recieve errors of GLFW.
			/// </summary>
			GLFWErrorCallback glfwCallback;

			/// <summary>
			/// Callback for user recieve errors of GLFW.
			/// </summary>
			OpenGlErrorCallback openGlCallback;

			/// <summary>
			/// The current debugging configuration;
			/// </summary>
			DebugConfiguration config;
		public:
			/// <summary>
			/// Get if there is an GLFW error at runtime.
			/// </summary>
			static GLFWError GetGLFWError(std::string& errorMsg);

			/// <summary>
			/// Get if there is an OpenGL error at runtime.
			/// </summary>
			static OpenGlError GetOpenGlError();

			/// <summary>
			/// Register callbacks to recieve errors or warnings from GLFW or openGL
			/// </summary>
			static void RegisterCallbacks(ErrorCallback callback, GLFWErrorCallback glfwCallback, OpenGlErrorCallback openGlCallback);

			static std::string ErrorToString(const OpenGlError value);

			static std::string ErrorToString(const GLFWError value);

			static std::string ErrorToString(const OpenGlErrorSource value);

			static std::string ErrorToString(const OpenGlErrorType value);

			static std::string ErrorToString(const OpenGlErrorSeverity value);
		private:
			Debugging() {};
			Debugging(Debugging const&);
			void operator=(Debugging const&);

			/// <summary>
			/// Returns current instance.
			/// </summary>
			static Debugging& Instance();

			void Init(const DebugConfiguration& config);
			void Release();

			/// <summary>
			/// Callbacks to recieve errors of GLFW.
			/// </summary>
			static void GLFW_ERROR_CALLBACK(int code, const char* description);

			/// <summary>
			/// Callbacks to recieve errors of OpenGL.
			/// Internal usage.
			/// </summary>
			static void GLAPIENTRY OPENGL_ERROR_CALLBACK(
				GLenum source,
				GLenum type,
				GLuint id,
				GLenum severity,
				GLsizei length,
				const GLchar* message,
				const void* userParam
			);
		};
	}
}
#pragma once
#include <PrimitiveEngine.hpp>

namespace PrimitiveEngine {
namespace Debug {

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
}}
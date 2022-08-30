#pragma once
#include <PrimitiveEngine.hpp>

namespace PrimitiveEngine
{
	namespace Editor
	{
		class LogTab : public Layout
		{
		private:
			int currentItem = 1;

			bool showWarnings = true;
			bool showErrors = true;
			bool showMessages = true;

			std::string filterMessage = "";

			glm::vec4 notificationColor = { 0.0f, 0.0f, 0.0f, 0.0f };
			glm::vec4 errorColor = { 1.0f, 0.0f, 0.0f, 0.5f };
			glm::vec4 warningColor = { 1.0f, 0.8f, 0.0f, 0.5f };

			std::vector<Window::GUIListBoxItem> savedMessages;
			std::vector<Window::GUIListBoxItem> filteredMessages;

			GPU::TexturePtr errorTexture = nullptr;
			GPU::TexturePtr notifyTexture = nullptr;
			GPU::TexturePtr warningTexture = nullptr;
		public:
			LogTab() = default;
			~LogTab() = default;

			void Awake();
			void Start();
			void DrawTop();
			void Update();
			void Destroy();

			void PopulateLog();
			void LogCallback(
				const Utils::DateTime& datetime,
				const std::string& message,
				const Debug::LogSeverity severity,
				const Debug::LogOrigin origin,
				const std::string& function,
				const std::string& file
			);
		};
	}
}
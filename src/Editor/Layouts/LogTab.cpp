#include <PrimitiveEngine.hpp>
#include "LogTab.hpp"

namespace PrimitiveEngine
{
	namespace Editor
	{
		void LogTab::Awake()
		{
			using namespace std::placeholders;

			Debug::Logging::RegisterLogCallback(
				"PrimitiveEngine.Editor.LogTab",
				std::bind(&LogTab::LogCallback, this, _1, _2, _3, _4, _5, _6)
			);
		}

		void LogTab::Start()
		{
			auto textureConfig = GPU::TextureDataConfiguration();

			textureConfig.pixelFormat = GPU::TexturePixelFormat::UNSIGNED_BYTE;
			textureConfig.internalFormat = GPU::TextureInternalFormat::RGBA;

			auto errorIcon = Utils::ImagePtr(new Utils::Image(Utils::Path::GetCurrentPath() + "/../../../res/error.png"));
			auto warningIcon = Utils::ImagePtr(new Utils::Image(Utils::Path::GetCurrentPath() + "/../../../res/warning.png"));
			auto notifyIcon = Utils::ImagePtr(new Utils::Image(Utils::Path::GetCurrentPath() + "/../../../res/notification.png"));

			this->errorTexture = GPU::TexturePtr(new GPU::Texture(textureConfig, errorIcon));
			this->warningTexture = GPU::TexturePtr(new GPU::Texture(textureConfig, warningIcon));
			this->notifyTexture = GPU::TexturePtr(new GPU::Texture(textureConfig, notifyIcon));
		}

		void LogTab::DrawTop()
		{
			using namespace PrimitiveEngine::Window;

			if (GUI::ImageButton(this->errorTexture, { 15, 15 }))
			{
				this->showErrors = !this->showErrors;
				this->PopulateLog();
			}

			if (GUI::IsCurrentItemHovered())
			{
				GUI::BeginHintWindow();
				GUI::Text(this->showErrors ? "Hide errors" : "Show errors");
				GUI::EndHintWindow();
			}

			GUI::ContinueSameLine();

			if (GUI::ImageButton(this->warningTexture, { 15, 15 }))
			{
				this->showWarnings = !this->showWarnings;
				this->PopulateLog();
			}

			if (GUI::IsCurrentItemHovered())
			{
				GUI::BeginHintWindow();
				GUI::Text(this->showWarnings ? "Hide warnings" : "Show warnings");
				GUI::EndHintWindow();
			}

			GUI::ContinueSameLine();

			if (GUI::ImageButton(this->notifyTexture, { 15, 15 }))
			{
				this->showMessages = !this->showMessages;
				this->PopulateLog();
			}

			if (GUI::IsCurrentItemHovered())
			{
				GUI::BeginHintWindow();
				GUI::Text(this->showMessages ? "Hide notifications" : "Show notifications");
				GUI::EndHintWindow();
			}

			GUI::ContinueSameLine(10);

			if (GUI::Input("Text", this->filterMessage))
				this->PopulateLog();

			GUI::ContinueSameLine();

			if (GUI::Button("Clear"))
			{
				this->savedMessages.clear();
				this->filteredMessages.clear();
			}
		}

		void LogTab::Update()
		{
			using namespace PrimitiveEngine::Window;

			GUI::ListBox("LogsList", this->filteredMessages);
		}

		void LogTab::Destroy()
		{
			Debug::Logging::RemoveLogCallback("PrimitiveEngine.Editor.LogTab");
		}

		void LogTab::PopulateLog()
		{
			this->filteredMessages.clear();

			for (auto& message : this->savedMessages)
			{
				if (this->filterMessage != "" && message.value.find(this->filterMessage) == -1)
					continue;

				if (!this->showErrors && message.color == this->errorColor)
					continue;
				if (!this->showWarnings && message.color == this->warningColor)
					continue;
				if (!this->showMessages && message.color == this->notificationColor)
					continue;

				this->filteredMessages.push_back(message);
			}
		}

		void LogTab::LogCallback(
			const Utils::DateTime& datetime,
			const std::string& message, 
			const Debug::LogSeverity severity, 
			const Debug::LogOrigin origin, 
			const std::string& function, 
			const std::string& file
		)
		{
			using namespace PrimitiveEngine::Window;
			using namespace PrimitiveEngine::Debug;

			glm::vec4 color = this->notificationColor;

			if(severity == LogSeverity::Error)
				color = this->errorColor;

			if (severity == LogSeverity::Warning)
				color = this->warningColor;
			
			GUIListBoxItem row = GUIListBoxItem(message, color);

			this->savedMessages.push_back(row);

			if (!this->showErrors && severity != LogSeverity::Error)
				return;
			if (!this->showWarnings && severity != LogSeverity::Warning)
				return;
			if (!this->showMessages && severity != LogSeverity::Notify)
				return;
			if (this->filterMessage != "" && message.find(this->filterMessage) == -1)
				return;
			
			this->filteredMessages.push_back(row);
		}
	}
}


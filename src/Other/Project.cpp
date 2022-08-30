#include <PrimitiveEngine.hpp>
#include "Project.hpp"

namespace PrimitiveEngine
{
    namespace Engine
    {
        void Project::Save(const std::string& path)
        {
            using json = nlohmann::json;
            using namespace PrimitiveEngine::Utils;

            json jsonFile = {
              {"project_name", this->name},
            };

            File::CreateFile(path, jsonFile.dump(4));

            this->isLoaded = true;
        }

        void Project::Load(const std::string& path)
        {
            using json = nlohmann::json;
            using namespace PrimitiveEngine::Utils;

            std::string rawJson = File::ReadFile(path);

            json data = json::parse(rawJson);

            if (data.contains("project_name"))
                this->name = data["project_name"];
            else
                throw new std::runtime_error("Failed to load project name");

            this->isLoaded = true;
        }

        bool Project::IsLoaded() const
        {
            return this->isLoaded;
        }
    }
}

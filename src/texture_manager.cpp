#include "texture_manager.h"
#include "debug.h"

std::map<std::string, std::pair<sf::Texture, int>> TextureManager::textures{};

void TextureManager::Init()
{

}

sf::Texture& TextureManager::GetTexture(std::string identifier)
{
    auto iterator = TextureManager::textures.find(identifier);

    if (iterator == TextureManager::textures.end())
    {
        TextureManager::textures[identifier] = std::pair<sf::Texture, int>(sf::Texture{}, 0);
        iterator = TextureManager::textures.find(identifier);

        if (!iterator->second.first.loadFromFile("assets/" + identifier + ".png"))
        {
            Debug::WriteError("Could not load texture: " + identifier);
        }
    }

    // Not confusing at all
    iterator->second.second += 1;
    return iterator->second.first;
}

void TextureManager::ReleaseTexture(std::string identifier)
{
    auto iterator = TextureManager::textures.find(identifier);

    if (iterator != TextureManager::textures.end())
    {
        iterator->second.second -= 1;
        if (iterator->second.second <= 0)
        {
            TextureManager::textures.erase(iterator);
        }
    }
}

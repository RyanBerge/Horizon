#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SFML/Graphics/Texture.hpp>
#include <map>

class TextureManager
{
public:
    static void Init();
    static sf::Texture& GetTexture(std::string identifier);
    static void ReleaseTexture(std::string identifier);

    static std::map<std::string, std::pair<sf::Texture, int>> textures;

};

#endif // TEXTURE_MANAGER_H

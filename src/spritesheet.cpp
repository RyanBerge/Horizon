#include "spritesheet.h"
#include "texture_manager.h"

#include <iostream>

Spritesheet::Spritesheet(std::string texture = "") : texture{texture}
{
    if (texture != "")
    {
        sprite.setTexture(TextureManager::GetTexture(texture));
    }
}

Spritesheet::~Spritesheet()
{
    TextureManager::ReleaseTexture(texture);
}

void Spritesheet::Update(sf::Time elapsed, sf::RenderWindow& window)
{
    // Advance animation
}

void Spritesheet::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

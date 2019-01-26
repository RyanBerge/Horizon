/**************************************************************************************************
 *  File:       spritesheet.h
 *  Class:      Spritesheet
 *
 *  Purpose:    Spritesheet is a wrapper for an sf::Sprite
 *
 *  Author:     Ryan Berge
 *
 *************************************************************************************************/
#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>


class Spritesheet
{
public:
    Spritesheet(std::string texture);
    ~Spritesheet();

    void Update(sf::Time elapsed, sf::RenderWindow& window);
    void Draw(sf::RenderWindow& window);

private:
    std::string texture;
    sf::Sprite sprite{};
};

#endif // SPRITESHEET_H

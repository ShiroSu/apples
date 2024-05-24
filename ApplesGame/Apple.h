#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"
#include "GameSettings.h"

namespace ApplesGame
{
	struct Apple
	{
		Position position;
		sf::Sprite sprite;
		AppleType type;
	};

	void InitApple(Apple& apple, AppleType type, const sf::Texture& texture);
	void InitApple(Apple& apple, AppleType type, const sf::Texture& texture, bool isHidden);
	void DrawApple(Apple& apple, sf::RenderWindow& window);
}

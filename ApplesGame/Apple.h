#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"

namespace ApplesGame
{
	struct Apple
	{
		Position position;
		sf::Sprite sprite;
		int type;

	};

	void InitApple(Apple& apple, const sf::Texture& texture, int type);
	void DrawApple(Apple& apple, sf::RenderWindow& window);
}

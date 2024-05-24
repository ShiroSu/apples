#include "Apple.h"
#include "GameSettings.h"

#include <cstdlib>

namespace ApplesGame
{
	void InitApple(Apple& apple, AppleType type, const sf::Texture& texture)
	{
		// init apple state
		apple.position.x = (float)(rand() % (SCREEN_WIDTH + 1));
		apple.position.y = (float)(rand() % (SCREEN_HEGHT + 1));
		apple.type = type;

		// Init sprite
		apple.sprite.setTexture(texture);
		apple.sprite.setOrigin(GetSpriteOrigin(apple.sprite, { 0.5f, 0.5f })); // We need to use texture as origin ignores scale
		// Initiate victorious Gold apple
		if (type == goldApple) apple.sprite.setScale(GetSpriteScale(apple.sprite, { APPLE_SIZE + 5, APPLE_SIZE + 5 }));
		// Initiate regular apple
		else apple.sprite.setScale(GetSpriteScale(apple.sprite, { APPLE_SIZE, APPLE_SIZE }));
	}
	void InitApple(Apple& apple, AppleType type, const sf::Texture& texture, bool isHidden)
	{
		// init apple state
		apple.type = type;
		if (isHidden) {
			apple.position.x = (float)(SCREEN_WIDTH + 100);
			apple.position.y = (float)(SCREEN_HEGHT + 100);
		}
		else {
			apple.position.x = (float)(rand() % (SCREEN_WIDTH + 1));
			apple.position.y = (float)(rand() % (SCREEN_HEGHT + 1));
		}

		// Init sprite
		apple.sprite.setTexture(texture);
		apple.sprite.setOrigin(GetSpriteOrigin(apple.sprite, { 0.5f, 0.5f })); // We need to use texture as origin ignores scale
		// Initiate victorious Gold apple
		if (type == goldApple) apple.sprite.setScale(GetSpriteScale(apple.sprite, { APPLE_SIZE + 5, APPLE_SIZE + 5 }));
		// Initiate regular apple
		else apple.sprite.setScale(GetSpriteScale(apple.sprite, { APPLE_SIZE, APPLE_SIZE }));
	}

	void DrawApple(Apple& apple, sf::RenderWindow& window)
	{
		apple.sprite.setPosition(OurVectorToSf(apple.position));
		window.draw(apple.sprite);
	}

}

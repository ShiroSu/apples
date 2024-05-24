#include "Game.h"
#include <assert.h>


namespace ApplesGame
{
	void InitGame(GameState& gameState)
	{
		// Init game resources (terminate if error)
		assert(gameState.playerTexture.loadFromFile(RESOURCES_PATH + "Pacman.png"));
		assert(gameState.redAppleTexture.loadFromFile(RESOURCES_PATH + "Red-apple.png"));
		assert(gameState.goldAppleTexture.loadFromFile(RESOURCES_PATH + "Gold-apple.png"));
		assert(gameState.greenAppleTexture.loadFromFile(RESOURCES_PATH + "Green-apple.png"));
		assert(gameState.yellowAppleTexture.loadFromFile(RESOURCES_PATH + "Yellow-apple.png"));
		assert(gameState.font.loadFromFile(RESOURCES_PATH + "Fonts/Roboto-Regular.ttf"));

		//gameState.apples = new Apple[gameState.totalApplesCount];
		InitUI(gameState.uiState, gameState.font);
		RestartGame(gameState);
	}

	void RestartGame(GameState& gameState)
	{
		// Init player
		InitPlayer(gameState.player, gameState.playerTexture);
		// Init apples
		for (int i = 0; i < NUM_APPLES; i++)
		{
			//enum AppleType appleType = AppleType(rand() % 3);
				InitApple(gameState.apples[i], redApple, gameState.redAppleTexture);
			//if (appleType == redApple) 
			//else if (appleType == greenApple) InitApple(gameState.apples[i], appleType, gameState.greenAppleTexture);
			//else InitApple(gameState.apples[i], appleType, gameState.goldAppleTexture);
		}

		// Init game state
		gameState.numEatenApples = 0;
		gameState.isGameOver = false;
		gameState.timeSinceGameOver = 0.f;
	}

	void HandleInput(GameState& gameState)
	{
		if (gameState.isGameOver)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				RestartGame(gameState);
			}

			// We don't handle input in game over state
			return;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			gameState.player.direction = PlayerDirection::Up;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			gameState.player.direction = PlayerDirection::Right;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			gameState.player.direction = PlayerDirection::Down;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			gameState.player.direction = PlayerDirection::Left;
		}
	}

	void UpdateGame(GameState& gameState, float timeDelta)
	{
		if (!gameState.isGameOver && !gameState.isGameWon)
		{
			// Update player
			UpdatePlayer(gameState.player, timeDelta);

			for (int i = 0; i < gameState.totalApplesCount; i++)
			{
				// Check collision with apple
				if (HasPlayerCollisionWithApple(gameState.player, gameState.apples[i]))
				{
					// Increase eaten apples counter
					gameState.numEatenApples++;
					// Increase player speed
					if (gameState.apples[i].type == redApple) gameState.player.speed += ACCELERATION;
					else {
						gameState.isGameWon = true;
						gameState.timeSinceGameOver = 0.f;
					}

					//if (gameState.numEatenApples <= NUM_APPLES_FOR_WIN - NUM_APPLES) {
						// Move apple to a new random position
						enum AppleType appleType = redApple;
						if (gameState.numEatenApples == NUM_APPLES_FOR_WIN - 1) appleType = goldApple;

						if (appleType == redApple) InitApple(gameState.apples[i], appleType, gameState.redAppleTexture);
						/*else if (appleType == greenApple) InitApple(gameState.apples[i], appleType, gameState.greenAppleTexture);*/
						else
						{
							for (int k = 0; k < gameState.totalApplesCount; k++) {
								if (k != i) InitApple(gameState.apples[k], appleType, gameState.goldAppleTexture, true);
								InitApple(gameState.apples[i], appleType, gameState.goldAppleTexture, false);
							}
						}
					//}
				}
			}

			// Check collision with screen border
			if (HasPlayerCollisionWithScreenBorder(gameState.player))
			{
				gameState.isGameOver = true;
				gameState.timeSinceGameOver = 0.f;
			}
		}
		else
		{
			gameState.timeSinceGameOver += timeDelta;
		}

		UpdateUI(gameState.uiState, gameState, timeDelta);
	}

	void DrawGame(GameState& gameState, sf::RenderWindow& window)
	{
		// Draw player
		DrawPlayer(gameState.player, window);
		// Draw apples
		for (int i = 0; i < gameState.totalApplesCount; i++)
		{
			DrawApple(gameState.apples[i], window);
		}

		DrawUI(gameState.uiState, window);
	}
}

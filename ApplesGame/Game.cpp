#include "Game.h"
#include <assert.h>


namespace ApplesGame
{
	void InitGame(GameState& gameState)
	{
		// Init game resources (terminate if error)
		assert(gameState.playerTexture.loadFromFile(RESOURCES_PATH + "Pacman.png"));
		assert(gameState.redAppleTexture.loadFromFile(RESOURCES_PATH + "Red-apple.png"));
		assert(gameState.greenAppleTexture.loadFromFile(RESOURCES_PATH + "Green-apple.png"));
		assert(gameState.yellowAppleTexture.loadFromFile(RESOURCES_PATH + "Yellow-apple.png"));
		assert(gameState.font.loadFromFile(RESOURCES_PATH + "Fonts/Roboto-Regular.ttf"));

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
			int randNum = rand();
			if (randNum % 3 == 0) {
				InitApple(gameState.apples[i], gameState.redAppleTexture, randNum);
			}
			else if (randNum % 3 == 1) {
				InitApple(gameState.apples[i], gameState.greenAppleTexture, randNum);
			}
			else if (randNum % 3 == 2) {
				InitApple(gameState.apples[i], gameState.yellowAppleTexture, randNum);
			}
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
		if (!gameState.isGameOver)
		{
			// Update player
			UpdatePlayer(gameState.player, timeDelta);

			for (int i = 0; i < NUM_APPLES; i++)
			{
				// Check collision with apple
				if (HasPlayerCollisionWithApple(gameState.player, gameState.apples[i]))
				{
					// Move apple to a new random position
					int randNum = rand();
					if (randNum % 3 == 0) {
						InitApple(gameState.apples[i], gameState.redAppleTexture, randNum);
					}
					else if (randNum % 3 == 1) {
						InitApple(gameState.apples[i], gameState.greenAppleTexture, randNum);
					}
					else if (randNum % 3 == 2) {
						InitApple(gameState.apples[i], gameState.yellowAppleTexture, randNum);
					}
					// Increase eaten apples counter
					gameState.numEatenApples++;
					// Increase player speed
					if (gameState.apples[i].type == 0) {
					gameState.player.speed += ACCELERATION;
					}
					else if (gameState.apples[i].type == 1) {
						gameState.
					}
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
		for (int i = 0; i < NUM_APPLES; i++)
		{
			DrawApple(gameState.apples[i], window);
		}

		DrawUI(gameState.uiState, window);
	}
}

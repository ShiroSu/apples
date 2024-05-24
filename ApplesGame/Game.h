#pragma once
#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Apple.h"
#include "UI.h"
#include "GameSettings.h"

namespace ApplesGame
{
	struct GameState
	{
		Player player;
		int totalApplesCount = NUM_APPLES;
		Apple apples[NUM_APPLES];
		int numEatenApples = 0;
		UIState uiState;
		bool isGameOver = false;
		bool isGameWon = false;
		float timeSinceGameOver = 0.f;

		// Game resources
		sf::Font font;
		sf::Texture playerTexture;
		sf::Texture redAppleTexture;
		sf::Texture goldAppleTexture;
		sf::Texture greenAppleTexture;
		sf::Texture yellowAppleTexture;
	};

	void InitGame(GameState& gameState);
	void RestartGame(GameState& gameState);
	void HandleInput(GameState& gameState);
	void UpdateGame(GameState& gameState, float timeDelta);
	void DrawGame(GameState& gameState, sf::RenderWindow& window);
}

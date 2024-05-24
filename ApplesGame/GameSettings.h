#pragma once
#include <string>

namespace ApplesGame
{
	// Apple textures
	enum AppleType {
		redApple = 0,
		goldApple,
		//greenApple,
		//yellowApple,
	};

	// Resources path
	const std::string RESOURCES_PATH = "Resources/";

	// Game settings constants
	const float PLAYER_SIZE = 20.f;
	const float APPLE_SIZE = 20.f;
	const float INITIAL_SPEED = 100.f;
	const float ACCELERATION = 10.f; // For each eaten apple player speed will be increased by this value
	const int NUM_APPLES = 50;
	const int NUM_APPLES_FOR_WIN = 100;
	const unsigned int SCREEN_WIDTH = 800;
	const unsigned int SCREEN_HEGHT = 600;
	const int redAppleType = 0;
	const int greenAppleType = 1;
	const int yellowAppleType = 2;
}

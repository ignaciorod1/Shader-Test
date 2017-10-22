#pragma once
#include "GLSL_Program.h"
#include <SDL\SDL.h>
#include <GL\glew.h>

enum class GameState {PLAY, EXIT};

class Game
{
private:
	void initSystem();
//	void initShaders();
	void gameLoop();
	void processInput();

	SDL_Window* _window;
	int _screenWidth;
	int _screenHeight;
	GameState _gameState;

//	GLSL_Program _colorProgram;

public:
	Game();
	~Game();

	void run();
};


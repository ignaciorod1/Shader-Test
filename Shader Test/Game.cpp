#include "Game.h"
#include <iostream>
#include <string>
#include "Errors.h"
using namespace std;

Game::Game()
{
	_window = nullptr;
	_screenWidth = 1024;
	_screenHeight = 768;
	_gameState = GameState::PLAY;	
}


Game::~Game()
{
}


void Game::run() {

	initSystem();
	gameLoop();
}

void Game::gameLoop(){
	while (_gameState != GameState::EXIT)
	processInput();
}

void Game::processInput() {		// control de interrupciones 
	SDL_Event evnt;

	while (SDL_PollEvent(&evnt)) {
		switch (evnt.type) {
			case SDL_QUIT:		// cerrar la ventana
				_gameState = GameState::EXIT;
				break;
			case SDL_MOUSEMOTION:		//coordenandas del raton en la ventana
				cout << evnt.motion.x << "		" << evnt.motion.y << endl;
				break;
		}
	}
}
void Game::initSystem() {

	SDL_Init(SDL_INIT_EVERYTHING);

	_window = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		_screenWidth, _screenHeight, SDL_WINDOW_OPENGL);
}
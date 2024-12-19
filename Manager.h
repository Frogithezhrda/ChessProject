#pragma once
#include "Player.h"
#include "Board.h"
enum ErrorCodes {}; // Error codes

class Manager
{
public:
	//need to be implemented
private:
	char _gameState; //d = draw, w = win, n = normal
	Player _blackPlayer;
	Player _whitePlayer;
	Board _board;
};
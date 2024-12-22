#pragma once
#include "Board.h"

class Console
{
public:
	Console(Board& board, Player players[]);
	int getErrorCode() const;
private:
	int _errorCode;
};
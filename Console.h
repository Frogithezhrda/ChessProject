#pragma once
#include "Board.h"

class Console
{
public:
	Console(Board& board);
	int getErrorCode() const;
private:
	int _errorCode;
};
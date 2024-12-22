#pragma once
#include "Board.h"

class Console
{
public:

	Console(Board& board);

	int getErrorCode() const;

private:
	/*
	name: printturn
	input: a book that represents if its whites turn
	output: none
	description: this functions prints whos turn it is
    */
	void printTurn(bool isWhiteTurn);

	void displayError(int errorCode);


	int _errorCode;
};
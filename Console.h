#pragma once
#include "Board.h"

class Console
{
public:

	/*
	name: CONSTRUCTOR
	input: a refrence to a board
	*/
	Console(Board& board);
	
	/*
	name: geterrorcode
	input: none
	output: the error code
	description: this functions returns the error code
	*/
	int getErrorCode() const;

private:
	/*
	name: printturn
	input: a book that represents if its whites turn
	output: none
	description: this functions prints whos turn it is
    */
	void printTurn(bool isWhiteTurn);

	/*
	name: displayErorr
	input: an error code
	output: none
	description: this functions prints the error by given error code :)
	*/
	void displayError(int errorCode);


	int _errorCode;//the current error code
};
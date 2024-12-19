#pragma once
#include <iostream>
#include "Place.h"

class Board
{
public:
	Board();
	~Board();

	void printBoard() const;
	Place** getBoard() const;

private:
	Place** board;
};
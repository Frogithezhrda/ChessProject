#pragma once
#include <iostream>
#include "Place.h"

class Board
{
public:
	Board();
	~Board();
	
	/*
	name:
	input:
	output:
	description:
	*/
	void printBoard() const;

	/*
	name:
	input:
	output:
	description:
	*/
	Place** getBoard() const;

private:
	Place** board;
};
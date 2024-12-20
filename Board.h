#pragma once
#include <iostream>
#include "Place.h"

class Board//represents the gameboard
{
public:
	/*
	name: CONSTRUCTOR
	input: none
	*/
	Board();

	/*
	name: DESTRUCTOR
	*/
	~Board();
	
	/*
	name: printBoard
	input: none
	output: none
	description: this function print the gameboard :)
	*/
	void printBoard() const;

	/*
	name: getBoard
	input: none
	output: the board
	description: this function returns the board (?)
	*/
	Place** getBoard() const;

private:
	Place** board; //the board(?)
};
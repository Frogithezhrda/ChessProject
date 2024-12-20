#pragma once
#include <iostream>
#include "Place.h"

#define BOARD_SIZE 8
#define A_ASCII_VALUE 97

class Place;

class Board//represents the gameboard
{
public:
	/*
	name: CONSTRUCTOR
	input: none
	*/
	Board(const std::string& initBoard);

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
	Place** _board; //the board(?)
};
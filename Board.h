#pragma once
#include <iostream>
#include "Place.h"
#include "Piece.h"
#include <string>
#include "Rook.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"


#define BLACK 'b'
#define WHITE 'w'
#define BOARD_SIZE 8
#define A_ASCII_VALUE 97


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


	void setBoard(const std::string& src, const Place& dest);

	Piece* getPiece(const std::string& pieceLocation) const;
	/*
	name: getBoard
	input: none
	output: the board
	description: this function returns the board (?)
	*/
	Place* getBoard() const;

	bool isValidPosition(const std::string& position) const;

private:
	Place* _board[BOARD_SIZE]; //the board(?)
};
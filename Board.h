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

#define LAST_ROW_INDEX '8'
#define FIRST_ROW_INDEX '1'
#define LAST_COLUM_INDEX 'h'
#define FIRST_COLUM_INDEX 'a'

#define ROW_INDEX 1
#define COLUM_INDEX 0

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

	void setPieceAtBoard(const std::string& dest, Piece* piece);

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
#pragma once
#include <iostream>
#include "Place.h"

class Piece//represents a piece on the board
{
public:
	/*
	name: CONSTRUCTOR
	input: pieceColor - the color of the piece(B/W). type
	*/
	Piece(const char pieceColor, const std::string& type, const Place& firstPlace);

	/*
	name: CONSTRUCTOR
	input: a refrense to a string that represents the location on the board
	*/
	~Piece();

	/*
	name: move
	input: a refrence to a place 
	output: none
	description: this function moves the piece to the given dest
	*/
	virtual void move(const Place& dest) = 0;

	/*
	name: isValidMove
	input: a refrence to a place
	output: a num that represents the validility
	description: this function tells if the move is valid or not and why
	*/
	virtual int isValidMove(const Place& dest) const = 0;

	/*
	name: getPieceColor
	input: none
	output:a char that represents the clor of the piece (B/W)
	description: this function returns the color of the piece
	*/
	char getPieceColor() const;

	/*
	name: getType
	input: none
	output: a string that represents a type
	description: this fyunction returns the type of the piece
	*/
	std::string getType() const;

private:
	char _pieceColor;//the color of the piece
	std::string _type;//the type of piece
	Place _currentPlace;//the current location of the piece
};
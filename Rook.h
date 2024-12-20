#pragma once
#include "Piece.h"

class Rook : Piece
{
public:

private:
	/*
	name: move
	input: a refrence to a place
	output: none
	description: this function moves the piece to the given dest
	*/
	virtual void move(const Place& dest) override;

	/*
	name: isValidMove
	input: a refrence to a place
	output: a num that represents the validility
	description: this function tells if the move is valid or not and why
	*/
	virtual int isValidMove(const Place& dest) const override;

};

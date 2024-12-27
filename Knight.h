#pragma once
#include "Piece.h"
#include "Board.h"
#include "Player.h"

class Knight : public Piece
{
public:
	Knight(const char pieceColor, const Place& firstPlace);
	/*
	name: isValidMove
	input: a refrence to a place
	output: a num that represents the validility
	description: this function tells if the move is valid or not and why
	*/
	virtual int isValidMove(const Place& dest, Board* board, Player* player, Player* opponentPlayer) const override;

private:
	/*
	name: move
	input: a refrence to a place
	output: none
	description: this function moves the piece to the given dest
	*/

};

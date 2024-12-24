#pragma once
#include "Piece.h"

class Rook : public Piece
{
public:
	Rook(const char pieceColor, const Place& firstPlace);
		/*
	name: move
	input: a refrence to a place
	output: none
	description: this function moves the piece to the given dest
	*/

	bool isClearPath(const Place& dest, const Place& src, const Board* board) const;
	/*
	name: isValidMove
	input: a refrence to a place
	output: a num that represents the validility
	description: this function tells if the move is valid or not and why
	*/
	virtual int isValidMove(const Place& dest, Board* board, Player* player, Player* opponentPlayer) const override;
private:

};

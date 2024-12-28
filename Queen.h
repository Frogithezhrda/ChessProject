#ifndef QUEEN_H
#define QUEEN_H
#pragma once
#include "Piece.h"
#include "Board.h"
#include "Player.h"

class Queen : public Piece
{
public:
	Queen(const char pieceColor, const Place& firstPlace);
	/*
	name: isValidMove
	input: a refrence to a place(dest), a pointer to the board, a pointer to a player, and a pointer to the opp player.
	output: a num that represents the validility
	description: this function tells if the move is valid or not and why
	*/
	virtual int isValidMove(const Place& dest, Board* board, Player* player, Player* opponentPlayer) const override;

	virtual ~Queen();
private:

};
#endif
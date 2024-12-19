#pragma once
#include "Piece.h"

class Pawn : Piece
{
public:

private:
	virtual void move(const Place& dest) override;
	virtual int isValidMove(const Place& dest) const override;

};

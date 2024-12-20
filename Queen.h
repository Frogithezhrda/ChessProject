#pragma once
#include "Piece.h"

class Queen : Piece
{
public:

private:
	/*
	name:
	input:
	output:
	description:
	*/
	virtual void move(const Place& dest) override;

	/*
	name:
	input:
	output:
	description:
	*/
	virtual int isValidMove(const Place& dest) const override;

};

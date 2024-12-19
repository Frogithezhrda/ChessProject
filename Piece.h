#pragma once
#include <iostream>
#include "Place.h"

class Piece
{
public:
	Piece(const char pieceColor, const std::string& type, const Place& firstPlace);
	~Piece();
	virtual void move(const Place& dest) = 0;
	virtual int isValidMove(const Place& dest) const = 0;

	char getPieceColor() const;
	std::string getType() const;

private:
	char _pieceColor;
	std::string _type;
	Place _currentPlace;
};
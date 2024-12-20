#pragma once
#include <iostream>
#include "Place.h"

class Piece
{
public:
	/*
	name:
	input:
	output:
	description:
	*/
	Piece(const char pieceColor, const std::string& type, const Place& firstPlace);

	/*
	name:
	input:
	output:
	description:
	*/
	~Piece();

	/*
	name:
	input:
	output:
	description:
	*/
	virtual void move(const Place& dest) = 0;

	/*
	name:
	input:
	output:
	description:
	*/
	virtual int isValidMove(const Place& dest) const = 0;

	/*
	name:
	input:
	output:
	description:
	*/
	char getPieceColor() const;

	/*
	name:
	input:
	output:
	description:
	*/
	std::string getType() const;

private:
	char _pieceColor;
	std::string _type;
	Place _currentPlace;
};
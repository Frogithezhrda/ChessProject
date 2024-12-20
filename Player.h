#pragma once
#include <vector>
#include "Piece.h"
#include "King.h"
/*
	name:
	input:
	output:
	description:
	*/

class Player//represents the player
{
public:
	
	/*
	name: constructor
	input: a char that represents the players color (W/B)
	*/
	Player(const char playerColor);
	~Player();

	/*
	name:
	input:
	output:
	description:
	*/
	char getPlayerColor() const;

	/*
	name:
	input:
	output:
	description:
	*/
	bool isChecked() const;

	/*
	name:
	input:
	output:
	description:
	*/
	std::vector<Piece*>& getPieces() const;

private:
	char _playerColor;
	bool _isChecked;
	std::vector<Piece*> _pieces;
	King* _king;

};

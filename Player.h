#pragma once
#include <vector>
#include "Piece.h"
#include "King.h"

class Player
{
public:

	Player(const char playerColor);
	~Player();

	char getPlayerColor() const;
	bool isChecked() const;
	std::vector<Piece*>& getPieces() const;

private:
	char _playerColor;
	bool _isChecked;
	std::vector<Piece*> _pieces;
	King* _king;

};

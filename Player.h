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
	Player();
	/*
	name: CONSTRUCTOR
	input: a char that represents the players color (W/B)
	*/
	Player(const char playerColor, const Board* board);

	/*
	name: DESTRUCTOR
	*/
	~Player();

	/*
	name: getPlayerColor
	input: none
	output: a char that represenyts the players color (W/B)
	description: this functions returns the players color (W/B)
	*/
	char getPlayerColor() const;

	/*
	name: isChecked
	input: a refrence to the src, a refrence to the dest, a pointer to the board, and a pointer to the opp
	output: true is the player is checked, and false otherwise
	description: this functions tells if the player is checked, or not.
	*/

	bool isChecked() const;

	bool isMate() const;

	void activateCheck();

	void deactivateCheck();

	/*
	name: getPieces
	input: none
	output: retuns a refrence to a vector that has the players pieces
	description: this functions returns a reference to the players pieces
	*/
	King* getKing() const;
private:
	char _playerColor;//the players color (W/B)
	bool _isChecked;//is he checked or not (true == checked)
	King* _king;//a pointer to DA king (tomking ofc)
};

#include "King.h"


King::King(const char pieceColor, const Place& firstPlace) : Piece(pieceColor, "King", firstPlace)
{
}
/*
	name: move
	input: a refrence to a place
	output: none
	description: this function moves the piece to the given dest
*/
void King::move(const Place& dest) 
{
	this->setCurrentPlace(dest);
}

/*
name: isValidMove
input: a refrence to a place
output: a num that represents the validility
description: this function tells if the move is valid or not and why
*/
int King::isValidMove(const Place& dest) const
{

}
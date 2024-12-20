#include "Rook.h"

Rook::Rook(const char pieceColor, const Place& firstPlace) : Piece(pieceColor, "Rook", firstPlace)
{

}

int Rook::isValidMove(const Place& dest) const
{
	char currentRow = this->getCurrentPlace().getLocation()[0];
	char currentLine = this->getCurrentPlace().getLocation()[1];
	// still didnt fix the after the piece problem will fix be smart(i know how i dont have the power)
	if (!dest.hasPiece() && (currentRow == dest.getLocation()[0] || currentLine == dest.getLocation()[1]) && dest.getLocation() != this->getCurrentPlace().getLocation())
	{
		return 0;
	}
	else
	{
		return 2;
	}
}

void Rook::move(const Place& dest)
{
	this->setCurrentPlace(dest);
}
#include "Rook.h"

Rook::Rook(const char pieceColor, const Place& firstPlace) : Piece(pieceColor, (pieceColor == 'w' ? RookName : std::toupper(RookName)), firstPlace)
{

}

int Rook::isValidMove(const Place& dest) const
{
    // Get current position
    char currentRow = this->getCurrentPlace().getLocation()[0];
    char currentLine = this->getCurrentPlace().getLocation()[1];
    char pieceColor = islower(dest.getCurrentPiece()) ? 'w' : 'b';

    if (this->getCurrentPlace().getCurrentPiece() == '#')
    {
        return 2; 
    }
    if ((!dest.hasPiece() || pieceColor != this->getPieceColor()) &&
        (currentRow == dest.getLocation()[0] || currentLine == dest.getLocation()[1]) && 
        dest.getLocation() != this->getCurrentPlace().getLocation()) 
    {
        return 0; // Valid move
    }

    return 6; 
}
void Rook::move(const Place& dest)
{
	if (!isValidMove(dest))
	{
		this->setCurrentPlace(dest);
	}
}
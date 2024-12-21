#include "King.h"
#include "Board.h"
#include "Manager.h"

King::King(const char pieceColor, const Place& firstPlace) : Piece(pieceColor, "King", firstPlace)
{
}

void King::move(const Place& dest) 
{
	this->setCurrentPlace(dest);
}

int King::isValidMove(const Place& dest) const
{
	std::string currentLocation = this->getCurrentPlace().getLocation();
	std::string destinationLocation = dest.getLocation();

	if (currentLocation == destinationLocation) 
	{
		return 7; //src and dst are the same
	}

	int currentRow = currentLocation[0] - '1'; // '1' -> 0, '2' -> 1, etc.
	int currentCol = currentLocation[1] - 'A'; // 'A' -> 0, 'B' -> 1, etc.

	int destRow = destinationLocation[0] - '1';// '1' -> 0, '2' -> 1, etc.
	int destCol = destinationLocation[1] - 'A';// '1' -> 0, '2' -> 1, etc.

	if (destRow < 0 || destRow >= BOARD_SIZE || destCol < 0 || destCol >= BOARD_SIZE) 
	{
		return 6; //invalid move for the King
	}

	int rowDiff = (destRow > currentRow) ? (destRow - currentRow) : (currentRow - destRow);
	int colDiff = (destCol > currentCol) ? (destCol - currentCol) : (currentCol - destCol);

	if (rowDiff > 1 || colDiff > 1) 
	{
		return 6; //invalid move for the King
	}
	
	if (dest.hasPiece() && dest.getCurrentPiece() == this->getPieceColor()) 
	{
		return 3; //cant eat its own piece
	}

	//NEED TO IMPLANT ERROR 1 OPTION !! (MAKING A CHECK ON THE OPPONANT)

	return 0;

}
#include "King.h"
#include "Board.h"
#include "Manager.h"

King::King(const char pieceColor, const Place& firstPlace) : Piece(pieceColor, (pieceColor == 'w' ? KingName : std::toupper(KingName)), firstPlace)
{
}

void King::move(const Place& dest, const Board* board)
{
	if (isValidMove(dest, board))
	{
		this->setCurrentPlace(dest);
	}
}

int King::isValidMove(const Place& dest, const Board* board) const
{
	char currentRow = this->getCurrentPlace().getLocation()[0];
	int currentLine = int(this->getCurrentPlace().getLocation()[1]);
	char pieceColor = islower(dest.getCurrentPiece()) ? 'w' : 'b';
	int differenceVertical = currentLine - int(dest.getLocation()[1]);
	int differenceHorizontal = int(currentRow) - int(dest.getLocation()[0]);
	if (dest.getLocation() == this->getCurrentPlace().getLocation())
	{
		return 7; //src and dst are the same
	}
	
	if (differenceVertical > 1 || differenceVertical < -1 || differenceHorizontal > 1 || differenceHorizontal < -1)
	{
		return 6;
	}
	
	if (dest.hasPiece() && pieceColor == this->getPieceColor())
	{
		return 3; //cant eat its own piece
	}

	//NEED TO IMPLANT ERROR 1 OPTION !! (MAKING A CHECK ON THE OPPONANT)

	return 0;

}
#include "Pawn.h"
#include "Board.h"
#include "Player.h"

Pawn::Pawn(const char pieceColor, const Place& firstPlace) : Piece(pieceColor, (pieceColor == 'w' ? PawnName : std::toupper(PawnName)), firstPlace)
{
}

int Pawn::isValidMove(const Place& dest, Board* board, Player* player, Player* opponentPlayer) const
{
	char currentRow = this->getCurrentPlace().getRow();
	char currentLine = this->getCurrentPlace().getLine();
	int differenceVertical = currentLine - int(dest.getLine()); 
	int differenceHorizontal = int(currentRow) - int(dest.getRow());
	int code = isBasicValid(dest, board, player);
	std::string middlePosition = "";
	char middleRow = ' ';

	if (code)
	{
		return code;
	}
	if (differenceHorizontal == 1 || differenceHorizontal == -1)
	{
		return 1;
	}
	if ((this->getPieceColor() == 'w' && differenceVertical == -1) ||
		(this->getPieceColor() == 'b' && differenceVertical == 1))
	{
		if (dest.getCurrentPiece() == 'k' && differenceHorizontal == 1 || differenceHorizontal == -1)
		{
			return CheckMove;
		}
		if (!dest.hasPiece() && differenceHorizontal == 1 || differenceHorizontal == -1)
		{
			return NotValidMove;
		}
		return GoodMove;
	}
	if (dest.hasPiece())
	{
		return GoodMove;
	}
	return NotValidMove;
}

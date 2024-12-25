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
		if (!dest.hasPiece() && differenceHorizontal == 1 || differenceHorizontal == -1)
		{
			return 6;
		}
		return 0;
	}
	if (dest.hasPiece())
	{
		return 0;
	}
	if ((this->getPieceColor() == 'w' && this->getCurrentPlace().getLine() == '2') || (this->getPieceColor() == 'b' && this->getCurrentPlace().getLine() == '7'))
	{
		if (((this->getPieceColor() == 'w' && differenceVertical == -2) ||
			(this->getPieceColor() == 'b' && differenceVertical == 2)) && differenceHorizontal == 0)
		{
			middleRow = currentLine + (differenceVertical / 2);
			middlePosition = std::string(1, currentRow) + std::to_string(middleRow);
			if (board->getPiece(middlePosition) != nullptr)
			{
				return 6; 
			}
			return 0;
		}
	}
	return 6;
}

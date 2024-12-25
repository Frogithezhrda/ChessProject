#include "Pawn.h"
#include "Board.h"
#include "Player.h"
enum GameCodes { GoodMove = 0, CheckMove, NotPlayerPiece, AlreadyHasPiece, WillBeCheck, NotValidIndex, NotValidMove, SameDestSrc, CheckMate };

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
	if ((this->getPieceColor() == 'w' && this->getCurrentPlace().getLine() == '2') || (this->getPieceColor() == 'b' && this->getCurrentPlace().getLine() == '7'))
	{
		if (((this->getPieceColor() == 'w' && differenceVertical == -2) ||
			(this->getPieceColor() == 'b' && differenceVertical == 2)) && differenceHorizontal == 0)
		{
			middleRow = currentLine + (differenceVertical / 2);
			middlePosition = std::string(1, currentRow) + std::to_string(middleRow);
			if (board->getPiece(middlePosition) != nullptr)
			{
				return NotValidMove;
			}
			return GoodMove;
		}
	}
	return NotValidMove;
}

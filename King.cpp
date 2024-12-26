#include "King.h"
#include "Player.h"
#include "Board.h"


King::King(const char pieceColor, const Place& firstPlace) : Piece(pieceColor, (pieceColor == 'w' ? KingName : std::toupper(KingName)), firstPlace)
{

}


int King::isValidMove(const Place& dest, Board* board, Player* player, Player* opponentPlayer) const
{
	char currentRow = this->getCurrentPlace().getRow();
	int currentLine = int(this->getCurrentPlace().getLine());
	char pieceColor = islower(dest.getCurrentPiece()) ? WHITE : BLACK;
	int differenceVertical = currentLine - int(dest.getLine());
	int differenceHorizontal = int(currentRow) - int(dest.getRow());
	Place opponentKingPlace = opponentPlayer->getKing()->getCurrentPlace();
	int opponentKingRow = opponentKingPlace.getRow();
	int opponentKingLine = opponentKingPlace.getLine();
	int i = 0;
	int code = isBasicValid(dest, board, player);
	if (code)
	{
		return code;
	}
	
	if (differenceVertical > 1 || differenceVertical < -1 || differenceHorizontal > 1 || differenceHorizontal < -1)
	{
		return NotValidMove;
	}
	if (abs(dest.getRow() - opponentKingRow) <= 1 && abs(dest.getLine() - opponentKingLine) <= 1)
	{
		return NotValidMove;
	}
	return GoodMove;
}
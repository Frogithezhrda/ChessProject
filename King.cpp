#include "King.h"
#include "Board.h"
#include "Player.h"

King::King(const char pieceColor, const Place& firstPlace) : Piece(pieceColor, (pieceColor == 'w' ? KingName : std::toupper(KingName)), firstPlace)
{

}


int King::isValidMove(const Place& dest, const Board* board, Player* player, Player* opponentPlayer) const
{
	char currentRow = this->getCurrentPlace().getLocation()[0];
	int currentLine = int(this->getCurrentPlace().getLocation()[1]);
	char pieceColor = islower(dest.getCurrentPiece()) ? 'w' : 'b';
	int differenceVertical = currentLine - int(dest.getLocation()[1]);
	int differenceHorizontal = int(currentRow) - int(dest.getLocation()[0]);
	int i = 0;

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

	//Place kingPlace = player->getKing()->getCurrentPlace();

	//for (i; i < opponentPlayer->getPieces().size(); i++)
	//{
	//	if (opponentPlayer->getPieces()[i]->isValidMove(kingPlace, board, player, opponentPlayer))
	//	{
	//		return true;
	//	}
	//}

	return 0;

}
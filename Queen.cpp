#include "Queen.h"
#include "Board.h"
#include "Player.h"

Queen::Queen(const char pieceColor, const Place& firstPlace) : Piece(pieceColor, (pieceColor == 'w' ? QueenName : std::toupper(QueenName)), firstPlace)
{

}

int Queen::isValidMove(const Place& dest, Board* board, Player* player, Player* opponentPlayer) const
{
	Rook rook = Rook(this->getPieceColor(), this->getCurrentPlace());
	Bishop bishop = Bishop(this->getPieceColor(), this->getCurrentPlace());
	int rookCode = rook.isValidMove(dest, board, player, opponentPlayer);
	int bishopCode = bishop.isValidMove(dest, board, player, opponentPlayer);
	if (rookCode == GoodMove && bishopCode == CheckMove || rookCode == GoodMove && bishopCode == CheckMove)
	{
		return CheckMove;
	}
	if (rookCode == GoodMove && bishopCode == NotValidMove || rookCode == NotValidMove && bishopCode == GoodMove)
	{
		return GoodMove;
	}
	return rookCode;
}

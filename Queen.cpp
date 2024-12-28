#include "Queen.h"

Queen::Queen(const char pieceColor, const Place& firstPlace) : Piece(pieceColor, (pieceColor == WHITE ? QueenName : std::toupper(QueenName)), firstPlace)
{

}

Queen::~Queen() {}

int Queen::isValidMove(const Place& dest, Board* board, Player* player, Player* opponentPlayer) const
{
	Rook rook = Rook(this->getPieceColor(), this->getCurrentPlace());
	Bishop bishop = Bishop(this->getPieceColor(), this->getCurrentPlace());
	int rookCode = rook.isValidMove(dest, board, player, opponentPlayer);
	int bishopCode = bishop.isValidMove(dest, board, player, opponentPlayer);
	Place opponentKingPlace = opponentPlayer->getKing()->getCurrentPlace();
	Rook rookCheck = Rook(this->getPieceColor(), dest);
	Bishop bishopCheck = Bishop(this->getPieceColor(), dest);
	if (bishopCode == CheckMove || rookCode == CheckMove)
	{
		return CheckMove;
	}
	if (rookCode == GoodMove || bishopCode == GoodMove)
	{

		if (rookCheck.isValidMove(opponentKingPlace, board, player, opponentPlayer) == CheckMove ||
			bishopCheck.isValidMove(opponentKingPlace, board, player, opponentPlayer) == CheckMove)
		{
			return CheckMove;
		}
		return GoodMove;
	}
	return rookCode;
}

#include "Piece.h"

Piece::Piece(const char pieceColor, const char type, const Place& firstPlace)
{
	this->_pieceColor = pieceColor;
	this->_type = type;
	this->_currentPlace = firstPlace;
}

Piece::~Piece()
{
}

Place Piece::getCurrentPlace() const
{
	return this->_currentPlace;
}

char Piece::getPieceColor() const
{
	return this->_pieceColor;
}

char Piece::getType() const
{
	return this->_type;
}
void Piece::setCurrentPlace(const Place& dest)
{
	this->_currentPlace = dest;
}

int Piece::move(const Place& dest, const Board* board, Player* player, Player* opponentPlayer)
{
	int moveCode = isValidMove(dest, board, player, opponentPlayer);
	if (moveCode == 1 || moveCode == 0)
	{
		this->setCurrentPlace(dest);
	}
	return moveCode;
}
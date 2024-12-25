#include "Piece.h"
#include "Player.h"
#include "Board.h"

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
	this->_currentPlace.setLocation(dest.getLocation());
	this->_currentPlace.activePiece();
}

int Piece::move(const Place& dest, Board* board, Player* player, Player* opponentPlayer)
{
	int moveCode = isValidMove(dest, board, player, opponentPlayer);
	if (moveCode == 1 || moveCode == 0)
	{
		std::cout << "Current Place before move: " << this->getCurrentPlace().getLocation() << std::endl;
		this->setCurrentPlace(dest);
		std::cout << "Current Place after move: " << this->getCurrentPlace().getLocation() << std::endl;

		if (std::tolower(this->_type) == 'k' && this->getPieceColor() == player->getPlayerColor())
		{
			player->getKing()->setCurrentPlace(dest);
			std::cout << "Player's King Position Updated to: " << player->getKing()->getCurrentPlace().getLocation() << std::endl;
		}
	}
	return moveCode;
}

int Piece::isBasicValid(const Place& dest, Board* board, Player* player) const
{
	char destPieceColor = islower(dest.getCurrentPiece()) ? 'w' : 'b';
	if (dest.getLocation() == this->getCurrentPlace().getLocation())
	{
		return 7; 
	}
	if (!board->isValidPosition(dest.getLocation()))
	{
		return 5;
	}
	if (this->getCurrentPlace().getCurrentPiece() == '#')
	{
		return 2;
	}
	if (dest.hasPiece() && destPieceColor == this->getPieceColor())
	{
		return 3;
	}
	return 0;
}
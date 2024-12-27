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
	if (moveCode == CheckMove || moveCode == GoodMove)
	{
		//cant eat the king
		if (std::tolower(dest.getCurrentPiece()) != KING)
		{
			this->setCurrentPlace(dest);

			if (std::tolower(this->_type) == KING && this->getPieceColor() == player->getPlayerColor())
			{
				player->getKing()->setCurrentPlace(dest);
			}
		}
		else
		{
			moveCode = NotValidMove;
		}
	}
	return moveCode;
}

int Piece::isBasicValid(const Place& dest, Board* board, Player* player) const
{
	char destPieceColor = islower(dest.getCurrentPiece()) ? WHITE : BLACK;
	if (dest.getLocation() == this->getCurrentPlace().getLocation())
	{
		return SameDestSrc; 
	}
	if (!board->isValidPosition(dest.getLocation()))
	{
		return NotValidIndex;
	}
	if (this->getCurrentPlace().getCurrentPiece() == EMPTY_PLACE)
	{
		return NotPlayerPiece;
	}
	if (dest.hasPiece() && destPieceColor == this->getPieceColor())
	{
		return AlreadyHasPiece;
	}
	return GoodMove;
}
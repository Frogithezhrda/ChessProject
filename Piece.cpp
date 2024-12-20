#include "Piece.h"

Piece::Piece(const char pieceColor, const std::string& type, const Place& firstPlace)
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

std::string Piece::getType() const
{
	return this->_type;
}
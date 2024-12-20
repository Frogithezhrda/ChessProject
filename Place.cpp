#include "Place.h"


Place::Place()
{
	//defualt values
	this->_hasPiece = false;
	this->_location = "";
	this->_pieceName = '#';
}

Place::Place(const std::string& location, const char pieceName)
{
	//defualt start as false and loc and piecename
	this->_hasPiece = false;
	this->_location = location;
	this->_pieceName = pieceName;
}

Place::~Place()
{
	
}


char Place::getCurrentPiece() const
{
	return this->_pieceName;
}

std::string Place::getLocation() const
{
	return this->_location;
}

void Place::setPiece(const char pieceName)
{
	this->_pieceName = pieceName;
}
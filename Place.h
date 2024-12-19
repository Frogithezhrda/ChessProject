#pragma once
#include <iostream>

class Place
{
public:
	Place(const std::string& location);
	~Place();

	bool hasPiece() const;
	std::string& getLocation() const;
	char getCurrentPiece() const;

private:
	bool _hasPiece;
	std::string _location;
	char _pieceName;

};
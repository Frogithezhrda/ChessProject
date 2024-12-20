#pragma once
#include <iostream>

class Place
{
public:
	Place(const std::string& location);
	~Place();

	/*
	name:
	input:
	output:
	description:
	*/
	bool hasPiece() const;

	/*
	name:
	input:
	output:
	description:
	*/
	std::string& getLocation() const;

	/*
	name:
	input:
	output:
	description:
	*/
	char getCurrentPiece() const;

private:
	bool _hasPiece;
	std::string _location;
	char _pieceName;

};
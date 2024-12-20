#pragma once
#include <iostream>

class Place
{
public:
	/*
	name: CONSTRUCTOR
	input: a refrense to a string that represents the location on the board
	*/
	Place(const std::string& location);

	/*
	name: DESTRUCTOR
	*/
	~Place();

	/*
	name: hasPiece
	input: none
	output: true if there is a piece in that place, false otherwise
	description: this functions tell if there is a piece in the current place
	*/
	bool hasPiece() const;

	/*
	name: getLocation 
	input: none
	output: a refrence to a string that represents a location on the board
	description: this functions returns the location of the current place
	*/
	std::string& getLocation() const;

	/*
	name: getCurrentPiece
	input: none
	output: a char that represents a piece. (# if there isnt)
	description: this functions returns what piece is in the current place. 
	*/
	char getCurrentPiece() const;

private:
	bool _hasPiece;//is there a piece in the place or not
	std::string _location;//the location of the place 
	char _pieceName;//the name of the piece on the board . (# if there isnt)

};
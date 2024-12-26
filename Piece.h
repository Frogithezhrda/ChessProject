#pragma once
#include <iostream>
#include "Place.h"

enum GameCodes { GoodMove = 0, CheckMove, NotPlayerPiece, AlreadyHasPiece, WillBeCheck, NotValidIndex, NotValidMove, SameDestSrc, CheckMate };
enum Pieces {PawnName = 'p', RookName = 'r', QueenName = 'q', KingName = 'k', KnightName = 'n', BishopName = 'b' };
#define EMPTY_PLACE '#'
#define BLACK 'b'
#define WHITE 'w'

class Board;
class Player;

class Piece//represents a piece on the board
{
public:
	/*
	name: CONSTRUCTOR
	input: pieceColor - the color of the piece(B/W). type
	*/
	Piece(const char pieceColor, const char type, const Place& firstPlace);

	/*
	name: CONSTRUCTOR
	input: a refrense to a string that represents the location on the board
	*/
	~Piece();

	/*
	name: move
	input: a refrence to a place 
	output: none
	description: this function moves the piece to the given dest
	*/
	int move(const Place& dest, Board* board, Player* player, Player* opponentPlayer);
	/*
	name: isValidMove
	input: a refrence to a place
	output: a num that represents the validility
	description: this function tells if the move is valid or not and why
	*/
	virtual int isValidMove(const Place& dest, Board* board, Player* player, Player* opponentPlayer) const = 0;

	int isBasicValid(const Place& dest, Board* board, Player* player) const;

	/*
	name: getPieceColor
	input: none
	output:a char that represents the clor of the piece (B/W)
	description: this function returns the color of the piece
	*/
	char getPieceColor() const;

	Place getCurrentPlace() const;

	/*
	name: getType
	input: none
	output: a string that represents a type
	description: this fyunction returns the type of the piece
	*/
	char getType() const;

	/*
	name: setCurrentPlace
	input: the new location
	output: none
	description: this fyunction returns the type of the piece
	*/
	void setCurrentPlace(const Place& dest);

private:
	char _pieceColor;//the color of the piece
	char _type;//the type of piece
	Place _currentPlace;//the current location of the piece
};
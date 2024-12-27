#pragma once
#include "Player.h"
#include "Board.h"

#define WHITE_PLAYER 0
#define BLACK_PLAYER 1
#define PLAYER_COUNT 2

#define ROW_INDEX 1
#define COLUM_INDEX 0
#define EMPTY_PLACE '#'

#define DEST_INDEX 0
#define SRC_INDEX 2

#define NUM_OF_CHARS_IN_LOCATION 2

#define SRC_ROW_INDEX 0
#define DEST_ROW 2
#define SRC_LINE 3
#define DEST_LINE 1

#define BASE_LETTER_ASCII_VALUE 'a'

enum GameState {Normal='n', StaleMate='s', Mate='w' };
//enum PieceTypes {Pawn='p', Rook='r', Knight='n', Bishop='b', King='k', Queen='q'};


class Manager
{
public:
	//need to be implemented
	void handleConsole();


	void printTurn(bool isWhiteTurn) const;
	/*
	name: CONSTRUCTOR
	input: none
	*/
	Manager(const std::string& initBoard);
	/*
	name: getBoard
	input: none
	output: the current board
	description: returns the current board
	*/
	Board& getBoard() const;

	Player getBlackPlayer() const;

	Player* getCurrentPlayer(const bool isWhiteTurn);

	Player* getOpponentPlayer(const bool isWhiteTurn);

	Player getWhitePlayer() const;

	bool isStillChecked(const bool isWhiteMove);

	int manageMove(const std::string& src, const std::string& dest, const bool isWhiteTurn);
	bool isValidMoveInput(const std::string& move);

	bool isDiscoveredAttack(const std::string& src, const std::string& dest, bool isWhiteTurn);

	int getErrorCode() const;

	~Manager();
private:
	/*
	name: initPieces
	input: player to intialize pieces for
	output: none
	description: initializes pieces on the board for the players
	*/
	void displayError(int errorCode);


	GameState _gameState; //d = draw, w = win, n = normal
	Player _players[PLAYER_COUNT];
	Board* _board;
	int _errorCode;
};
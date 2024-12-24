#pragma once
#include "Player.h"
#include "Board.h"

#define WHITE_PLAYER 1
#define BLACK_PLAYER 0
#define PLAYER_COUNT 2

enum GameState {Normal='n', StaleMate='s', Mate='w' };
enum GameCodes {GoodMove = 0, CheckMove, NotPlayerPiece, AlreadyHasPiece, WillBeCheck, NotValidIndex, NotValidMove, SameDestSrc, CheckMate}; // Error codes
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
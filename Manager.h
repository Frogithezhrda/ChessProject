#pragma once
#include "Player.h"
#include "Board.h"

#define BLACK 'b'
#define WHITE 'w'
#define WHITE_PLAYER 1
#define BLACK_PLAYER 0

enum GameCodes {GoodMove = 0, CheckMove, NotPlayerPiece, AlreadyHasPiece, WillBeCheck, NotValidIndex, NotValidMove, SameDestSrc, CheckMate}; // Error codes
enum PieceTypes {Pawn='p', Rook='r', Knight='n', Bishop='b', King='k', Queen='q'};


class Manager
{
public:
	//need to be implemented
	Manager();
	Board getBoard() const;
private:
	void initPieces(const Player& currentPlayer);

	char _gameState; //d = draw, w = win, n = normal
	Player _players[2];
	Board _board;
};
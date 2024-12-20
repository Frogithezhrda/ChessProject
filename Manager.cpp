#include "Manager.h"

Manager::Manager()
{
	this->_board;
	this->_gameState = 'n';
	this->_players[BLACK_PLAYER] = Player(BLACK);
	this->_players[WHITE_PLAYER] = Player(WHITE);
	initPieces(this->_players[BLACK_PLAYER]);
	initPieces(this->_players[WHITE_PLAYER]);
}


void Manager::initPieces(const Player& player)
{
	int i = 0;
	int rowPawn = (player.getPlayerColor() == BLACK) ? 1 : 6;
	int rowPiece = (player.getPlayerColor() == BLACK) ? 0 : 7;
	char currentPiece = Pawn;
	char pieces[] = { Rook, Knight, Bishop, King, Queen, Bishop, Knight, Rook };
	for (i; i < BOARD_SIZE; i++)
	{
		(player.getPlayerColor() == BLACK) ? currentPiece = std::toupper(currentPiece) : currentPiece;
		this->_board.getBoard()[rowPawn][i].setPiece(currentPiece);
	}
	for (i = 0; i < BOARD_SIZE; i++)
	{
		(player.getPlayerColor() == BLACK) ? currentPiece = std::toupper(pieces[i]) : currentPiece = pieces[i];
		this->_board.getBoard()[rowPiece][i].setPiece(currentPiece);
	}
}

Board Manager::getBoard() const
{
	return this->_board;
}
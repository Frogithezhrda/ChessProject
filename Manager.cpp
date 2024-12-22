#include "Manager.h"


Manager::Manager(const std::string& initBoard)
{
	//initalizing board and players
	this->_board = new Board(initBoard);
	this->_gameState = Normal;
	this->_players[BLACK_PLAYER] = Player(BLACK);
	this->_players[WHITE_PLAYER] = Player(WHITE);
	this->_console = new Console(*this->_board, this->_players);
	//maybe Used Later
}

Manager::~Manager()
{
}

Console* Manager::getConsole() const
{
	return _console;
}
Player Manager::getBlackPlayer() const
{
	return this->_players[BLACK_PLAYER];
}

Player Manager::getWhitePlayer() const
{
	return this->_players[WHITE_PLAYER];
}
Board& Manager::getBoard() const
{
	return *(this->_board);
}
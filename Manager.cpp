#include "Manager.h"

Manager::Manager(const std::string& initBoard)
{
	//initalizing board and players
	this->_board = new Board(initBoard);
	this->_gameState = Normal;
	this->_players[BLACK_PLAYER] = Player(BLACK);
	this->_players[WHITE_PLAYER] = Player(WHITE);
	this->_console = new Console(*this->_board);
	//maybe Used Later
	//initPieces(this->_players[BLACK_PLAYER]);
	//initPieces(this->_players[WHITE_PLAYER]);
}

Manager::~Manager()
{
}

//void Manager::initPieces(const Player& player)
//{
//	int i = 0;
//	int rowPawn = (player.getPlayerColor() == BLACK) ? 6 : 1;
//	int rowPiece = (player.getPlayerColor() == BLACK) ? 7 : 0;
//	char currentPiece = Pawn;
//	char pieces[] = { Rook, Knight, Bishop, King, Queen, Bishop, Knight, Rook };
//	for (i; i < BOARD_SIZE; i++)
//	{
//		(player.getPlayerColor() == BLACK) ? currentPiece = std::toupper(currentPiece) : currentPiece;
//		this->_board.getBoard()[rowPawn][i].setPiece(currentPiece);
//		//add piece addition
//	}
//	for (i = 0; i < BOARD_SIZE; i++)
//	{
//		(player.getPlayerColor() == BLACK) ? currentPiece = std::toupper(pieces[i]) : currentPiece = pieces[i];
//		this->_board.getBoard()[rowPiece][i].setPiece(currentPiece);
//	}
//}
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
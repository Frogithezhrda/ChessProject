#include "Board.h"
#include <string>


Board::Board()
{
	int i = BOARD_SIZE - 1;
	int j = 0;
	this->_board = new Place*[BOARD_SIZE];
	for (i; i >= 0; i--)
	{
		this->_board[i] = new Place[BOARD_SIZE];
		for(j = 0; j < BOARD_SIZE; j++)
		{
			this->_board[i][j] = Place(char(i + A_ASCII_VALUE) + std::to_string(j + 1), '#');
		}
	}
}

Board::~Board()
{
	int i = 0;
	for (i; i < BOARD_SIZE; i++)
	{
		delete[] _board[i];
	}
	delete[] _board;
}

void Board::printBoard() const
{
	int i = 0;
	int j = 0;
	for (i; i < BOARD_SIZE; i++)
	{
		for (j = 0; j < BOARD_SIZE; j++)
		{
			std::cout << this->_board[i][j].getCurrentPiece() << ' ';
		}
		std::cout << std::endl;
	}
}

Place** Board::getBoard() const
{
	return this->_board;
}
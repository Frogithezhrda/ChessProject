#include "Board.h"
#include <string>


Board::Board(const std::string& initBoard)
{
	// getting the last value of the board to go from a8 down
	int i = BOARD_SIZE - 1;
	int j = 0;
	//initialzing Places with correct locations
	for (i; i >= 0; i--)
	{
		this->_board[i] = new Place[BOARD_SIZE];
		for(j = 0; j < BOARD_SIZE; j++)
		{
			this->_board[i][j] = Place(char(i + A_ASCII_VALUE) + std::to_string(j + 1), initBoard[i * BOARD_SIZE + j]);
		}
	}
}

Board::~Board()
{
	int i = 0;
	//cleaning the board values of each part of the array
	for (i; i < BOARD_SIZE; i++)
	{
		delete[] _board[i];
	}
}
Piece* Board::getPiece(const std::string& pieceLocation) const
{
	int row = 0;
	int line = 0;
	int i = BOARD_SIZE - 1;
	int j = 0;
	Piece* piece = nullptr;
	Place* place = NULL;

	for (i; i >= 0; i--)
	{
		for (j = 0; j < BOARD_SIZE; j++)
		{
			if (this->_board[i][j].getLocation() == pieceLocation)
			{
				place = new Place();
				row = j;
				line = i;
				break;
			}
		}
	}

}
void Board::printBoard() const
{
	int i = BOARD_SIZE - 1;
	int j = 0;
	//going through each place in the board and printing it
	for (i; i >= 0; i--)
	{
		for (j = 0; j < BOARD_SIZE; j++)
		{
			std::cout << this->_board[i][j].getCurrentPiece() << ' ';
		}
		std::cout << std::endl;
	}
}

Place* Board::getBoard() const
{
	return *(this->_board);
}
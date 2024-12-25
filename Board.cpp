#include "Board.h"

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
			this->_board[i][j] = Place(char(j + A_ASCII_VALUE) + std::to_string(i + 1), initBoard[i * BOARD_SIZE + j]);
			if (initBoard[i * BOARD_SIZE + j] != '#')
			{
				this->_board[i][j].activePiece();
			}
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
	int i = 0;
	int j = 0;
	char pieceLetter = ' ';
	Piece* piece = nullptr;
	for(i; i < BOARD_SIZE; i++)
	{
		for (j = 0; j < BOARD_SIZE; j++)
		{
			if (this->_board[i][j].getLocation() == pieceLocation)
			{
				pieceLetter = this->_board[i][j].getCurrentPiece();
				switch (std::tolower(pieceLetter))
				{
					case PawnName:
						piece = new Pawn(std::islower(pieceLetter) ? WHITE : BLACK, this->_board[i][j]);
						break;
					case KnightName:

						break;
					case RookName:
						piece = new Rook(std::islower(pieceLetter) ? WHITE : BLACK, this->_board[i][j]);
						break;
					case KingName:
						piece = new King(std::islower(pieceLetter) ? WHITE : BLACK, this->_board[i][j]);
						break;
					case QueenName:

						break;
					case BishopName:

						break;
				}
				return piece;
			}
		}
	}
	return nullptr;
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

void Board::setBoard(const std::string& src, const Place& dest)
{
	int i = 0;
	int j = 0;

	char movingPieceChar = ' '; 
	bool srcFound = false;

	for (i = 0; i < BOARD_SIZE; i++)
	{
		for (j = 0; j < BOARD_SIZE; j++)
		{
			if (src == this->_board[i][j].getLocation())
			{
				movingPieceChar = this->_board[i][j].getCurrentPiece();

				this->_board[i][j].setPiece('#'); 
				this->_board[i][j].deactivePiece();

				srcFound = true;
				break;
			}
		}
		if (srcFound) break;
	}

	for (i = 0; i < BOARD_SIZE; i++)
	{
		for (j = 0; j < BOARD_SIZE; j++)
		{
			if (dest.getLocation() == this->_board[i][j].getLocation())
			{
				this->_board[i][j] = dest;
				this->_board[i][j].setPiece(movingPieceChar);
				this->_board[i][j].activePiece();
				return;
			}
		}
	}
}
Place* Board::getBoard() const
{
	return *(this->_board);
}

bool Board::isValidPosition(const std::string& position) const
{
	char row = position[0];
	char column = position[1];



	if ((row >= 'a' && row <= 'h') && (column >= '1' && column <= '8'))
	{
		return true; 
	}

	return false; 
}

void Board::setPieceAtBoard(const std::string& dest, Piece* piece)
{
	if (!isValidPosition(dest))
	{
		return;
	}

	// Locate the destination position on the board
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		for (int j = 0; j < BOARD_SIZE; ++j)
		{
			if (this->_board[i][j].getLocation() == dest)
			{
				// Set the piece's character representation at the destination
				this->_board[i][j].setPiece(piece->getType()); // Assuming getType() returns the piece character

				// Activate the destination place (indicating it's occupied)
				this->_board[i][j].activePiece();

				return;
			}
		}
	}
}
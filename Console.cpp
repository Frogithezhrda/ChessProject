//all of the files >:(
#include "Console.h"
/*
	name: hasPiece
	input: none
	output: true if there is a piece in that place, false otherwise
	description: this functions tell if there is a piece in the current place
*/
void displayError(int errorCode);

/*
	name: printturn
	input: a book that represents if its whites turn
	output: none
	description: this functions prints whos turn it is
*/
void printTurn(bool isWhiteTurn);

Console::Console(Board& board)
{
	bool isWhiteTurn = true;
	int errorCode = 0;
	std::string move;
	std::string src = " ";
	std::string dest = " ";
	Piece* pieceAtDest = NULL;
	char pieceChar = ' ';
	Place destPlace;
	Piece* pieceAtSrc = NULL;

	while (true)
	{
		board.printBoard();
		printTurn(isWhiteTurn);

		std::cin >> move;//players input

		if (move.length() != 4) //suppose to be only 4 char length
		{
			std::cout << "invalid input format." << std::endl;
			continue;
		}
		//errorCode = 2;
		//splitting input into src and dest
		src = move.substr(0, 2);
		dest = move.substr(2, 2);

		pieceAtDest = board.getPiece(dest);
		pieceChar = (pieceAtDest != nullptr) ? pieceAtDest->getType() : '#'; //if there is a piece at dest, piecechar will hold oit type. other wise it will hole # cuz its empty
		destPlace = Place(dest, pieceChar);

		pieceAtSrc = board.getPiece(src);
		if (pieceAtSrc != nullptr)
		{
			errorCode = pieceAtSrc->isValidMove(destPlace, &board);//gettiong the error code
		}
		else
		{
			errorCode = 2;
		}
		if (errorCode == 0)
		{
			board.setBoard(src, destPlace);
			pieceAtSrc->move(destPlace, &board);
			isWhiteTurn = !isWhiteTurn;
		}
		displayError(errorCode);

		if (!(errorCode == 0 || errorCode == 1 || errorCode == 8))
		{
			std::cout << "pls do a diffrent move instead!" << std::endl;
			continue;
		}
	}	
}

int Console::getErrorCode() const
{
	return _errorCode;
}

void displayError(int errorCode)
{
	switch (errorCode)
	{
	case 0:
	{
		std::cout << "valud  move !" << std::endl;
		break;
	}

	case 1:
	{
		std::cout << " valid move! opp is checked!" << std::endl;
		break;
	}

	case 2:
	{
		std::cout << "invalid move ! there is no players piece in src block!" << std::endl;
		break;
	}

	case 3:
	{
		std::cout << "invalid move ! there is players piece in dst block!" << std::endl;
		break;
	}

	case 4:
	{
		std::cout << "invalid move! will make check on current player!" << std::endl;
		break;
	}

	case 5:
	{
		std::cout << "invalid move ! invalid index!" << std::endl;
		break;
	}

	case 6:
	{
		std::cout << "invalid move ! this piece DOES NOT! move like this!" << std::endl;
		break;
	}

	case 7:
	{
		std::cout << "invalid move! dst and serc are the same!" << std::endl;
		break;
	}

	case 8:
	{
		std::cout << "valid move! CHECKMATEEE!" << std::endl;
		break;
	}

	default:
	{
		std::cout << "unknown error :(" << std::endl;
		break;
	}
	}
}

void printTurn(bool isWhiteTurn)
{
	if (isWhiteTurn)
	{
		std::cout << "whites turn! " << std::endl;
	}
	else
	{
		std::cout << "balcks turn! " << std::endl;
	}
}

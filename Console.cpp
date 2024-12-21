//all of the files >:(
#include "Bishop.h"
#include "Board.h"
#include "King.h"
#include "Knight.h"
#include "Manager.h"
#include "Pawn.h"
#include "Piece.h"
#include "Place.h"
#include "Player.h"
#include "Queen.h"
#include "Rook.h"

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

void main()
{
	bool isWhiteTurn = true;
	int errorCode = 0;
	std::string startBoard = "RNBKQBNRPPPPPPPP################################pppppppprnbkqbnr";
	std::string move;
	std::string src = " ";
	std::string dest = " ";
	Piece* pieceAtDest = NULL;
	char pieceChar = ' ';
	Place destPlace;
	Piece* pieceAtSrc = NULL;



	//initializing board
	Manager game(startBoard);

	while (true)
	{
		game.getBoard().printBoard();
		printTurn(isWhiteTurn);

		std::cin >> move;//players input

		if (move.length() != 4) //suppose to be only 4 char length
		{
			std::cout << "invalid input format." << std::endl;
			continue;
		}

		//splitting input into src and dest
		src = move.substr(0, 2);
		dest = move.substr(2, 2);

		pieceAtDest = game.getBoard().getPiece(dest);
		pieceChar = (pieceAtDest != NULL) ? pieceAtDest->getType()[0] : '#'; //if there is a piece at dest, piecechar will hold oit type. other wise it will hole # cuz its empty
		destPlace = Place(dest, pieceChar);

		pieceAtSrc = game.getBoard().getPiece(src);
		errorCode = pieceAtSrc->isValidMove(destPlace);//gettiong the error code

		displayError(errorCode);

		if (!(errorCode == 0 || errorCode == 1 || errorCode == 8))
		{
			std::cout << "pls do a diffrent move instead!" << std::endl;
			continue;
		}

		pieceAtSrc->move(destPlace);
		isWhiteTurn = !isWhiteTurn;
	}


		
		

		

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

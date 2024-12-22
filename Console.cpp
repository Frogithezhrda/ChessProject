//all of the files >:(
#include "Console.h"
#include "Player.h"


Console::Console(Board& board, Player players[])
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
		pieceAtSrc != nullptr ? ((isWhiteTurn && pieceAtSrc->getPieceColor() == 'b') || (!isWhiteTurn && pieceAtSrc->getPieceColor() == 'w')) ? errorCode = 2 : (errorCode = pieceAtSrc->isValidMove(destPlace, &board)) : (errorCode = 2);
		
		

		if (errorCode == 0)
		{
			board.setBoard(src, destPlace);
			pieceAtSrc->move(destPlace, &board);
			//isWhiteTurn = !isWhiteTurn;
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

void Console::displayError(int errorCode)
{
	switch (errorCode)
	{
	case ErrorCode::VALID_MOVE:
		std::cout << "Valid move!" << std::endl;
		break;

	case ErrorCode::VALID_MOVE_OPPONENT_CHECKED:
		std::cout << "Valid move! opponent is checked!" << std::endl;
		break;

	case ErrorCode::NO_PLAYER_PIECE_AT_SRC:
		std::cout << "Invalid move! there is no player's piece in src block!" << std::endl;
		break;

	case ErrorCode::PLAYER_PIECE_AT_DEST:
		std::cout << "Invalid move! there is a player's piece in dst block!" << std::endl;
		break;

	case ErrorCode::MOVE_CAUSES_CHECK:
		std::cout << "Invalid move! will make check on current player!" << std::endl;
		break;

	case ErrorCode::INVALID_INDEX:
		std::cout << "Invalid move! invalid index!" << std::endl;
		break;

	case ErrorCode::INVALID_PIECE_MOVE:
		std::cout << "Invalid move! this piece DOES NOT move like this!" << std::endl;
		break;

	case ErrorCode::SAME_SRC_AND_DEST:
		std::cout << "Invalid move! dst and src are the same!" << std::endl;
		break;

	case ErrorCode::CHECKMATE:
		std::cout << "Valid move! CHECKMATE!" << std::endl;
		break;

	default:
		std::cout << "Unknown error :(" << std::endl;
		break;
	}
}



void Console::printTurn(bool isWhiteTurn) const
{
	if (isWhiteTurn)
	{
		std::cout << "Whites turn! " << std::endl;
	}
	else
	{
		std::cout << "Blacks turn! " << std::endl;
	}
}
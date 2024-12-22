#include "Manager.h"


void Manager::handleConsole()
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
		(*this->_board).printBoard();
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

		pieceAtDest = (*this->_board).getPiece(dest);
		pieceChar = (pieceAtDest != nullptr) ? pieceAtDest->getType() : '#'; //if there is a piece at dest, piecechar will hold oit type. other wise it will hole # cuz its empty
		destPlace = Place(dest, pieceChar);

		pieceAtSrc = (*this->_board).getPiece(src);
		pieceAtSrc != nullptr ? ((isWhiteTurn && pieceAtSrc->getPieceColor() == 'b') || (!isWhiteTurn && pieceAtSrc->getPieceColor() == 'w')) ? (errorCode = 2) : (errorCode = pieceAtSrc->move(destPlace, this->_board, getCurrentPlayer(isWhiteTurn), getOpponentPlayer(isWhiteTurn))) : (errorCode = 2);
		if (this->getCurrentPlayer(isWhiteTurn)->isChecked())
		{
			errorCode = 4;
		}
		else if (errorCode == GoodMove || errorCode == CheckMove || errorCode == CheckMate)
		{
			this->_board->setBoard(src, destPlace);
			isWhiteTurn = !isWhiteTurn;
		}
		displayError(errorCode);
	}
}

bool Manager::isStillChecked(bool isWhiteMove)
{
	int i = 0;
	Place kingPlace = this->getCurrentPlayer(isWhiteMove)->getKing()->getCurrentPlace();

	for (i; i < this->getOpponentPlayer(isWhiteMove)->getPieces().size(); i++)
	{
		if (this->getOpponentPlayer(isWhiteMove)->getPieces()[i]->isValidMove(kingPlace, &this->getBoard(), getCurrentPlayer(isWhiteMove), getOpponentPlayer(isWhiteMove)))
		{
			return true; 
		}
	}

	return false; 
}
int Manager::getErrorCode() const
{
	return this->_errorCode;
}
void Manager::printTurn(bool isWhiteTurn) const
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
Player* Manager::getCurrentPlayer(bool isWhiteTurn)
{
	return isWhiteTurn ? &this->_players[WHITE_PLAYER] : &this->_players[BLACK_PLAYER];
}

Player* Manager::getOpponentPlayer(bool isWhiteTurn)
{
	return this->getCurrentPlayer(!isWhiteTurn);
}
Manager::Manager(const std::string& initBoard)
{
	//initalizing board and players
	this->_board = new Board(initBoard);
	this->_gameState = Normal;
	this->_players[BLACK_PLAYER] = Player(BLACK, this->_board);
	this->_players[WHITE_PLAYER] = Player(WHITE, this->_board);
	//maybe Used Later
}

Manager::~Manager()
{
}

void Manager::displayError(int errorCode)
{
	switch (errorCode)
	{
	case GoodMove:
		std::cout << "Valid move!" << std::endl;
		break;

	case CheckMove:
		std::cout << "Valid move! opponent is checked!" << std::endl;
		break;

	case NotPlayerPiece:
		std::cout << "Invalid move! there is no player's piece in src block!" << std::endl;
		break;

	case AlreadyHasPiece:
		std::cout << "Invalid move! there is a player's piece in dst block!" << std::endl;
		break;

	case WillBeCheck:
		std::cout << "Invalid move! will make check on current player!" << std::endl;
		break;

	case NotValidIndex:
		std::cout << "Invalid move! invalid index!" << std::endl;
		break;

	case NotValidMove:
		std::cout << "Invalid move! this piece DOES NOT move like this!" << std::endl;
		break;

	case SameDestSrc:
		std::cout << "Invalid move! dst and src are the same!" << std::endl;
		break;

	case CheckMate:
		std::cout << "Valid move! CHECKMATE!" << std::endl;
		break;

	default:
		std::cout << "Unknown error :(" << std::endl;
		break;
	}
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
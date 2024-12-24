#include "Manager.h"


void Manager::handleConsole()
{
	bool isWhiteTurn = true;
	int errorCode = 0;
	std::string move;
	std::string src = " ";
	std::string dest = " ";



	while (true)
	{
		(*this->_board).printBoard();
		printTurn(isWhiteTurn);

		std::cin >> move;//players input

		if (isValidMoveInput(move))
		{
			//errorCode = 2;
			//splitting input into src and dest
			src = move.substr(0, 2);
			dest = move.substr(2, 2);

			errorCode = manageMove(src, dest, isWhiteTurn);
			if (errorCode == GoodMove || errorCode == CheckMove)
			{
				isWhiteTurn = !isWhiteTurn;
			}
			else if (errorCode == CheckMate)
			{
				std::cout << getCurrentPlayer(isWhiteTurn)->getPlayerColor() << " Won!";
			}
			displayError(errorCode);
		}
		else
		{
			std::cerr << "Invalid Move!" << std::endl;
		}
	}
}

bool Manager::isStillChecked(bool isWhiteMove)
{
	int i = 0;
	int j = 0;
	Place kingPlace = this->getCurrentPlayer(isWhiteMove)->getKing()->getCurrentPlace();
	std::string position = "";
	Piece* piece = nullptr;
	for (i; i < BOARD_SIZE; i++)
	{
		for (j = 0; j < BOARD_SIZE; j++)
		{
			position = std::string(1, 'a' + j) + std::to_string(i + 1);
			piece = this->_board->getPiece(position);

			if (piece && piece->getPieceColor() != (isWhiteMove ? 'w' : 'b'))
			{
				if (piece->isValidMove(kingPlace, this->_board, getCurrentPlayer(isWhiteMove), getOpponentPlayer(isWhiteMove)) == CheckMove)
				{
					return true;
				}
			}
		}
	}

	return false;
}
int Manager::getErrorCode() const
{
	return this->_errorCode;
}
void Manager::printTurn(const bool isWhiteTurn) const
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
Player* Manager::getCurrentPlayer(const bool isWhiteTurn)
{
	return isWhiteTurn ? &this->_players[WHITE_PLAYER] : &this->_players[BLACK_PLAYER];
}

Player* Manager::getOpponentPlayer(const bool isWhiteTurn)
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

int Manager::manageMove(const std::string& src, const std::string& dest, const bool isWhiteTurn)
{
	Piece* pieceAtDest = (*this->_board).getPiece(dest);
	Piece* pieceAtSrc = _board->getPiece(src);
	char pieceChar = (pieceAtDest != nullptr) ? pieceAtDest->getType() : '#'; //if there is a piece at dest, piecechar will hold oit type. other wise it will hole # cuz its empty
	Place destPlace = Place(dest, pieceChar);
	Place srcPlace = (pieceAtSrc != nullptr) ? pieceAtSrc->getCurrentPlace() : Place();
	int code = 0;


	if (!pieceAtSrc || pieceAtSrc->getPieceColor() != (isWhiteTurn ? 'w' : 'b'))
	{
		return NotPlayerPiece;
	}

	code = pieceAtSrc->move(destPlace, this->_board, getCurrentPlayer(isWhiteTurn), getOpponentPlayer(isWhiteTurn));
	if (code == GoodMove || code == CheckMove)
	{
		this->_board->setBoard(src, destPlace);
	}
	if (isStillChecked(isWhiteTurn))
	{
		pieceAtSrc->move(srcPlace, this->_board, getCurrentPlayer(isWhiteTurn), getOpponentPlayer(isWhiteTurn));
		this->_board->setBoard(dest, srcPlace);
		return WillBeCheck;
	}
	else
	{
		getCurrentPlayer(isWhiteTurn)->deactivateCheck();
	}
	if (getCurrentPlayer(isWhiteTurn)->isChecked())
	{
		return CheckMove;
	}

	return code;

}

bool Manager::isValidMoveInput(const std::string& move)
{
	char srcRow = move[0];
	char destRow = move[2];
	char srcLine = move[3];
	char destLine = move[1];

	if (move.length() != 4)
	{
		return false;
	}
	return isalpha(srcRow) && isalpha(destRow) && isdigit(srcLine) && isdigit(destLine);
}

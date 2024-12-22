#include "Player.h"
#include "Board.h"

Player::Player()
{
	//default Player
	this->_playerColor = ' ';
	this->_king = NULL;
	this->_isChecked = false;
	this->_pieces;
}

Player::Player(const char color)
{
	//currently Player
	this->_playerColor = color;
	this->_king = NULL;
	this->_isChecked = false;
	this->_pieces;
}

Player::~Player()
{

}

char Player::getPlayerColor() const
{
	return this->_playerColor;
}



bool Player::isCheckAfterMove(const std::string& src, const std::string& dest, Board* board) 
{
    Piece* movingPiece = NULL;
    Piece* originalDestPiece = NULL;
    Place kingPlace;
    bool isInCheck;
    int i = 0;
    int j = 0;
    std::string location = " ";
    Piece* piece = NULL;


    //get the piece to move
    movingPiece = board->getPiece(src);
    if (!movingPiece) 
    {
        return false; // No piece to move
    }

    //backup the destination state
    originalDestPiece = board->getPiece(dest);

    //simulate the move
    board->setBoard(src, Place(dest, movingPiece->getType()), this);
    movingPiece->setCurrentPlace(Place(dest, movingPiece->getType()));

    //get the kings position
    kingPlace = this->_king->getCurrentPlace();

    //check if the king is under attack
    isInCheck = false;
    for (i = 0; i < BOARD_SIZE; ++i) 
    {
        for (j = 0; j < BOARD_SIZE; ++j) 
        {
            // create location string (e.g., "a1")
            location = std::string(1, 'a' + i) + std::to_string(j + 1);
            piece = board->getPiece(location);

            //if its an opponent piece, check if it can attack the king
            if (piece && piece->getPieceColor() != this->_playerColor) 
            {
                if (piece->isValidMove(kingPlace, board) == 0) 
                {
                    isInCheck = true;
                    break;
                }
            }
        }
        if (isInCheck) break;
    }

    //restore the board to its original state
    board->setBoard(src, Place(src, movingPiece->getType()), this);
    if (originalDestPiece) 
    {
        board->setBoard(dest, Place(dest, originalDestPiece->getType()), this);
    }
    else 
    {
        board->setBoard(dest, Place(dest, '#')); //empty place
    }
    movingPiece->setCurrentPlace(Place(src, movingPiece->getType()));

    return isInCheck;
}


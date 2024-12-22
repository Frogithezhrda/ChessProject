#include "Player.h"
#include "Board.h"

Player::Player()
{
	//default Player
	this->_playerColor = ' ';
	this->_king = nullptr;
	this->_isChecked = false;
}

Player::Player(const char color, const Board* board)
{
	//currently Player
    char row = (this->_playerColor == 'w') ? '1' : '8';
    int pawnRow = (this->_playerColor == 'w') ? 2 : 7; 
    Piece* piece = this->_playerColor == 'w' ? board->getPiece("d1") : board->getPiece("d8");
	this->_playerColor = color;
    this->_king = (King*)(piece);
	this->_isChecked = false;
    this->_pieces.push_back(board->getPiece(std::string(1, 'a') + row));
    this->_pieces.push_back(board->getPiece(std::string(1, 'h') + row));

    this->_pieces.push_back(board->getPiece(std::string(1, 'b') + row)); 
    this->_pieces.push_back(board->getPiece(std::string(1, 'g') + row));

    this->_pieces.push_back(board->getPiece(std::string(1, 'c') + row)); 
    this->_pieces.push_back(board->getPiece(std::string(1, 'f') + row)); 

    this->_pieces.push_back(board->getPiece(std::string(1, 'd') + row)); 

    this->_pieces.push_back(board->getPiece(std::string(1, 'e') + row));

    for (char col = 'a'; col <= 'h'; col++) 
    {
        this->_pieces.push_back(board->getPiece(std::string(1, col) + std::to_string(pawnRow)));
    }
}

Player::~Player()
{

}

void Player::activateCheck()
{
    this->_isChecked = true;
}
bool Player::isChecked() const
{
    return this->_isChecked;
}

std::vector<Piece*> Player::getPieces() const
{
    return this->_pieces;
}

void Player::deactivateCheck()
{
    this->_isChecked = false;
}
King* Player::getKing() const
{
    return this->_king;
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
        return false; // no piece to move
    }

    //backup the destination state
    originalDestPiece = board->getPiece(dest);

    //simulate the move
    //board->setBoard(src, Place(dest, movingPiece->getType()));
    //movingPiece->move(Place(dest, movingPiece->getType()), board);
    //movingPiece->setCurrentPlace(Place(dest, movingPiece->getType()));

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
                //if (piece->isValidMove(kingPlace, boardm ) == 0) 
                //{
                //    return isInCheck;
                //}
            }
        }
    }

    ////restore the board to its original state
    //board->setBoard(src, Place(src, movingPiece->getType()));
    //movingPiece->move(Place(dest, movingPiece->getType()), board);

    //if (originalDestPiece) 
    //{
    //    board->setBoard(dest, Place(dest, originalDestPiece->getType()));
    //}
    //else 
    //{
    //    board->setBoard(dest, Place(dest, '#')); //empty place
    //}
    //movingPiece->setCurrentPlace(Place(src, movingPiece->getType()));

    return isInCheck;
}


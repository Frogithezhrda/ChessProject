#include "Player.h"
#include "Board.h"
#define LAST_ROW_INDEX '8'
#define FIRST_ROW_INDEX '1'

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
    this->_playerColor = color;
    char row = (this->_playerColor == 'w') ? FIRST_ROW_INDEX : LAST_ROW_INDEX;
    int pawnRow = (this->_playerColor == 'w') ? 2 : 7; 
    Piece* piece = this->_playerColor == 'w' ? board->getPiece("d1") : board->getPiece("d8");
    this->_king = (King*)(piece);
	this->_isChecked = false;

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



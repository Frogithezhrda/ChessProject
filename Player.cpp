#include "Player.h"

Player::Player()
{
	this->_playerColor = ' ';
	this->_king = NULL;
	this->_isChecked = false;
	this->_pieces;
}

Player::Player(const char color)
{
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
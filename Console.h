#pragma once
#include "Board.h"

// define an enum for error codes to make the code more readable
enum ErrorCode 
{
    VALID_MOVE = 0,
    VALID_MOVE_OPPONENT_CHECKED = 1,
    NO_PLAYER_PIECE_AT_SRC = 2,
    PLAYER_PIECE_AT_DEST = 3,
    MOVE_CAUSES_CHECK = 4,
    INVALID_INDEX = 5,
    INVALID_PIECE_MOVE = 6,
    SAME_SRC_AND_DEST = 7,
    CHECKMATE = 8,
    UNKNOWN_ERROR = -1
};

class Console
{
public:

    /*
    name: CONSTRUCTOR
    input: a reference to a board
    */
    Console(Board& board);

    /*
    name: geterrorcode
    input: none
    output: the error code
    description: this functions returns the error code
    */
    int getErrorCode() const;

private:
    /*
    name: printturn
    input: a bool that represents if its white's turn
    output: none
    description: this functions prints whose turn it is
    */
    void printTurn(bool isWhiteTurn);

    /*
    name: displayError
    input: an error code
    output: none
    description: this functions prints the error by the given error code :)
    */
    void displayError(int errorCode);

    int _errorCode; // the current error code
};

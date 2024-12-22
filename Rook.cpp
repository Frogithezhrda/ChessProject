#include "Rook.h"
#include "Board.h"
#include "Player.h"

Rook::Rook(const char pieceColor, const Place& firstPlace) : Piece(pieceColor, (pieceColor == 'w' ? RookName : std::toupper(RookName)), firstPlace)
{

}


int Rook::isValidMove(const Place& dest, const Board* board, Player* currentPlayer, Player* opponentPlayer) const
{
    char currentRow = this->getCurrentPlace().getLocation()[0];
    char currentLine = this->getCurrentPlace().getLocation()[1];
    char pieceColor = islower(dest.getCurrentPiece()) ? 'w' : 'b';


    if (dest.getLocation() == this->getCurrentPlace().getLocation())
    {
        return 7; //src and dst are the same
    }

    if (this->getCurrentPlace().getCurrentPiece() == '#')
    {
        return 2; 
    }
    
    if ((!dest.hasPiece() || pieceColor != this->getPieceColor()) &&
        (currentRow == dest.getLocation()[0] || currentLine == dest.getLocation()[1]) && 
        dest.getLocation() != this->getCurrentPlace().getLocation() && isClearPath(dest, board))
    {
        if(dest.getLocation()[0] == currentPlayer->getKing()->getCurrentPlace().getLocation()[0] || dest.getLocation()[1] == currentPlayer->getKing()->getCurrentPlace().getLocation()[1])
        {
            return 1;
            opponentPlayer->activateCheck();
        }

        return 0; 
    }

    return 6; 
}

bool Rook::isClearPath(const Place& dest, const Board* board) const
{
    //code not nice
    int i = 0;
    int startRow = std::min(this->getCurrentPlace().getLocation()[1] - '1', dest.getLocation()[1] - '1');
    int endRow = std::max(this->getCurrentPlace().getLocation()[1] - '1', dest.getLocation()[1] - '1');
    char startLine = std::min(this->getCurrentPlace().getLocation()[0], dest.getLocation()[0]);
    char endLine = std::max(this->getCurrentPlace().getLocation()[0], dest.getLocation()[0]);
    char currentRow = this->getCurrentPlace().getLocation()[0];
    std::string currentPos = "";
    
    if (currentRow == dest.getLocation()[0])  // vertical movement
    {
        for (i = startRow + 1; i < endRow; i++)
        {
            currentPos = std::string(currentRow + std::to_string(i + 1));
            if (board->getPiece(currentPos) != nullptr)  // check if the square is occupied
            {
                return false;
            }
        }
    }
    else if (this->getCurrentPlace().getLocation()[1] == dest.getLocation()[1])  // horizontal movement
    {
        for (i = startLine + 1; i < endLine; i++)
        {
            currentPos = std::string(std::string(1, (char)i) + this->getCurrentPlace().getLocation()[1]);  // hell
            if (board->getPiece(currentPos) != nullptr)
            {
                return false;
            }
        }
    }
    return true; 
}

#include "Knight.h"


Knight::Knight(const char pieceColor, const Place& firstPlace) : Piece(pieceColor, (pieceColor == WHITE ? KnightName : std::toupper(KnightName)), firstPlace)
{

}


int Knight::isValidMove(const Place& dest, Board* board, Player* player, Player* opponentPlayer) const
{
    char currentRow = this->getCurrentPlace().getRow();
    int currentLine = int(this->getCurrentPlace().getLine());
    char destRow = dest.getRow();
    int destLine = int(dest.getLine());
    int code = isBasicValid(dest, board, player);
    int rowDiff = 0;
    int lineDiff = 0;
    

    if (code)
    {
        return code;
    }

    rowDiff = abs(currentRow - destRow);
    lineDiff = abs(currentLine - destLine);

    if (!((rowDiff == 2 && lineDiff == 1) || (rowDiff == 1 && lineDiff == 2)))
    {
        return NotValidMove;
    }


    return GoodMove;
}
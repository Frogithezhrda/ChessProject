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
    int rowKingDiff = 0;
    int lineKingDiff = 0;
    int rowKingCheckDiff = 0;
    int lineKingCheckDiff = 0;

    if (code)
    {
        return code;
    }

    rowKingDiff = abs(destRow - opponentPlayer->getKing()->getCurrentPlace().getRow());
    lineKingDiff = abs(destLine - opponentPlayer->getKing()->getCurrentPlace().getLine());
    rowDiff = abs(currentRow - destRow);
    lineDiff = abs(currentLine - destLine);
    rowKingCheckDiff = abs(currentRow - opponentPlayer->getKing()->getCurrentPlace().getRow());
    lineKingCheckDiff = abs(currentLine - opponentPlayer->getKing()->getCurrentPlace().getLine());
    
    if (!((rowDiff == 2 && lineDiff == 1) || (rowDiff == 1 && lineDiff == 2)))
    {
        return NotValidMove;
    }
    if ((rowKingDiff == 2 && lineKingDiff == 1) || (rowKingDiff == 1 && lineKingDiff == 2))
    {
        return CheckMove;
    }
    if (std::tolower(dest.getCurrentPiece()) == 'k')
    {
        if ((rowKingCheckDiff == 2 && lineKingCheckDiff == 1) || (rowKingCheckDiff == 1 && lineKingCheckDiff == 2))
        {
            opponentPlayer->activateCheck();
            return CheckMove;
        }
    }

    return GoodMove;
}
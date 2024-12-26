#include "Bishop.h"

Bishop::Bishop(const char pieceColor, const Place& firstPlace) : Piece(pieceColor, (pieceColor == 'w' ? BishopName : std::toupper(BishopName)), firstPlace)
{

}


int Bishop::isValidMove(const Place& dest, Board* board, Player* currentPlayer, Player* opponentPlayer) const
{
    int currentRow = this->getCurrentPlace().getRow() - 'a';  
    int currentColumn = this->getCurrentPlace().getLine() - '1'; 
    int destRow = dest.getRow() - 'a';
    int destColumn = dest.getLine() - '1';
    int kingRow = opponentPlayer->getKing()->getCurrentPlace().getRow() - 'a';
    int kingColumn = opponentPlayer->getKing()->getCurrentPlace().getLine() - '1';
    char pieceColor = islower(dest.getCurrentPiece()) ? 'w' : BLACK;
    int code = isBasicValid(dest, board, currentPlayer);

    if (dest.getCurrentPiece() == EMPTY_PLACE)
    {
        pieceColor = EMPTY_PLACE;
    }

    if (abs(currentRow - destRow) != abs(currentColumn - destColumn))
    {
        return NotValidMove;
    }
    if (!code && (!dest.hasPiece() || pieceColor != this->getPieceColor()) && isClearPath(dest, this->getCurrentPlace(), board))
    {
        if (pieceColor != EMPTY_PLACE && std::tolower(dest.getCurrentPiece()) != 'k')
        {
            board->setBoard(dest.getLocation(), Place(dest.getLocation(), EMPTY_PLACE));
        }
        if (abs(destRow - kingRow) == abs(destColumn - kingColumn))
        {
            if (isClearPath(opponentPlayer->getKing()->getCurrentPlace(), dest, board))
            {
                opponentPlayer->activateCheck();
                return CheckMove;
            }
        }
        return GoodMove;
    }
    else if (!code)
    {
        code = NotValidMove;
    }

    return code;
}

bool Bishop::isClearPath(const Place& dest, const Place& src, const Board* board) const
{
    //getting rows and colums
    int srcRow = src.getRow() - 'a';    
    int srcCol = src.getLine() - '1';  
    int destRow = dest.getRow() - 'a';
    int destCol = dest.getLine() - '1';
    int rowStep = (destRow > srcRow) ? 1 : -1;
    int colStep = (destCol > srcCol) ? 1 : -1;
    std::string currentPos = "";
    int currentRow = srcRow + rowStep;
    int currentCol = srcCol + colStep;

    if (abs(srcRow - destRow) != abs(srcCol - destCol)) {
        return false;  
    }
    while (currentRow != destRow && currentCol != destCol) 
    {
        currentPos = std::string(1, currentRow + 'a') + std::to_string(currentCol + 1);
        if (board->getPiece(currentPos) != nullptr) 
        {  
            return false;
        }
        currentRow += rowStep;
        currentCol += colStep;
    }

    return true;  
}

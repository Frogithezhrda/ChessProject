#include "Bishop.h"

Bishop::Bishop(const char pieceColor, const Place& firstPlace) : Piece(pieceColor, (pieceColor == 'w' ? BishopName : std::toupper(BishopName)), firstPlace)
{

}

Bishop::~Bishop() {}
int Bishop::isValidMove(const Place& dest, Board* board, Player* currentPlayer, Player* opponentPlayer) const
{
    int currentRow = this->getCurrentPlace().getRow() - BASE_LETTER_ASCII_VALUE;
    int currentColumn = this->getCurrentPlace().getLine() - BASE_NUM_ASCII_VALUE;
    int destRow = dest.getRow() - BASE_LETTER_ASCII_VALUE;
    int destColumn = dest.getLine() - BASE_NUM_ASCII_VALUE;
    int kingRow = opponentPlayer->getKing()->getCurrentPlace().getRow() - BASE_LETTER_ASCII_VALUE;
    int kingColumn = opponentPlayer->getKing()->getCurrentPlace().getLine() - BASE_NUM_ASCII_VALUE;
    char pieceColor = islower(dest.getCurrentPiece()) ? WHITE : BLACK;
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

        if (pieceColor != EMPTY_PLACE && std::tolower(dest.getCurrentPiece()) != KING)
        {
            board->setBoard(dest.getLocation(), Place(dest.getLocation(), EMPTY_PLACE));
        }
        if (abs(destRow - kingRow) == abs(destColumn - kingColumn))
        {
            if (std::tolower(dest.getCurrentPiece()) == KING)
            {
                if (isClearPath(opponentPlayer->getKing()->getCurrentPlace(),  this->getCurrentPlace(), board))
                {
                    opponentPlayer->activateCheck();
                    return CheckMove;
                }
            }
            else if (isClearPath(opponentPlayer->getKing()->getCurrentPlace(), dest, board))
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
    int srcRow = src.getRow() - BASE_LETTER_ASCII_VALUE;
    int srcCol = src.getLine() - BASE_NUM_ASCII_VALUE;
    int destRow = dest.getRow() - BASE_LETTER_ASCII_VALUE;
    int destCol = dest.getLine() - BASE_NUM_ASCII_VALUE;
    int rowStep = (destRow > srcRow) ? 1 : -1;
    int colStep = (destCol > srcCol) ? 1 : -1;
    std::string currentPos = "";
    int currentRow = srcRow + rowStep;
    int currentCol = srcCol + colStep;
    Piece* piece = nullptr;
    if (abs(srcRow - destRow) != abs(srcCol - destCol)) 
    {
        return false;  
    }
    while (currentRow != destRow && currentCol != destCol) 
    {
        currentPos = std::string(1, currentRow + BASE_LETTER_ASCII_VALUE) + std::to_string(currentCol + 1);
        piece = board->getPiece(currentPos);
        if (piece != nullptr) 
        {  
            return false;
        }
        delete piece;
        currentRow += rowStep;
        currentCol += colStep;
    }

    return true;  
}

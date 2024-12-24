#include "Rook.h"
#include "Board.h"
#include "Player.h"

Rook::Rook(const char pieceColor, const Place& firstPlace) : Piece(pieceColor, (pieceColor == 'w' ? RookName : std::toupper(RookName)), firstPlace)
{

}


int Rook::isValidMove(const Place& dest, Board* board, Player* currentPlayer, Player* opponentPlayer) const
{
    char currentRow = this->getCurrentPlace().getLocation()[0];
    char currentLine = this->getCurrentPlace().getLocation()[1];
    char pieceColor = islower(dest.getCurrentPiece()) ? 'w' : 'b';
    int code = isBasicValid(dest, board, currentPlayer);
    if (dest.getCurrentPiece() == '#')
    {
        pieceColor = '#';
    }
    
    if (!code && (!dest.hasPiece() || pieceColor != this->getPieceColor()) &&
        (currentRow == dest.getRow() || currentLine == dest.getLine()) && isClearPath(dest, this->getCurrentPlace(), board))
    {
        if (pieceColor != '#' && std::tolower(dest.getCurrentPiece()) != 'k')
        {
            board->setBoard(dest.getLocation(), Place(dest.getLocation(), '#'));
        }
        if (dest.getRow() == currentPlayer->getKing()->getCurrentPlace().getRow() || dest.getLine() == currentPlayer->getKing()->getCurrentPlace().getLine())
        {
            if (isClearPath(currentPlayer->getKing()->getCurrentPlace(), dest, board))
            {
                opponentPlayer->activateCheck();
                return 1;
            }
        }
        return 0; 
    }
    else if(!code)
    {
        code = 6;
    }

    return code;
}

bool Rook::isClearPath(const Place& dest, const Place& src, const Board* board) const
{
    //code not nice
    int i = 0;
    int startRow = std::min(src.getLine() - '1', dest.getLine() - '1');
    int endRow = std::max(src.getLine() - '1', dest.getLine() - '1');
    char startLine = std::min(src.getRow(), dest.getRow());
    char endLine = std::max(src.getRow(), dest.getRow());
    char currentRow = src.getRow();
    std::string currentPos = "";
    Piece* currentPiece = nullptr;

    if (currentRow == dest.getRow())  // vertical movement
    {
        for (i = startRow + 1; i < endRow; i++)
        {
            currentPos = std::string(currentRow + std::to_string(i + 1));
            currentPiece = board->getPiece(currentPos);
            if (currentPiece != nullptr && std::tolower(currentPiece->getType()) != 'k')  // check if the square is occupied
            {
                return false;
            }
        }
    }
    else if (src.getLine() == dest.getLine())  // horizontal movement
    {
        for (i = startLine + 1; i < endLine; i++)
        {
            currentPos = std::string(std::string(1, (char)i) + src.getLine());  // hell
            if (board->getPiece(currentPos) != nullptr)
            {
                return false;
            }
        }
    }
    return true; 
}

#include "Pawn.h"

Pawn::Pawn(const char pieceColor, const Place& firstPlace) : Piece(pieceColor, (pieceColor == 'w' ? PawnName : std::toupper(PawnName)), firstPlace)
{
}

int Pawn::isValidMove(const Place& dest, Board* board, Player* player, Player* opponentPlayer) const
{
    char currentRow = this->getCurrentPlace().getRow();
    char currentLine = this->getCurrentPlace().getLine();
    int differenceVertical = currentLine - int(dest.getLine());
    int differenceHorizontal = int(currentRow) - int(dest.getRow());
    char kingRow = opponentPlayer->getKing()->getCurrentPlace().getRow();
    char kingLine = opponentPlayer->getKing()->getCurrentPlace().getLine();
    int code = isBasicValid(dest, board, player);
    std::string middlePosition = "";
    char middleRow = ' ';

    if (code)
    {
        return code;
    }
    int first = std::abs(int(dest.getRow()) - int(kingRow));
    int second = std::abs(int(dest.getLine()) - int(kingLine));
    if ((std::abs(int(dest.getRow()) - int(kingRow)) == 1) && (std::abs(int(dest.getLine()) - int(kingLine)) == 1))
    {
        return CheckMove;
    }
    else if ((std::abs(int(this->getCurrentPlace().getRow()) - int(kingRow)) == 1) && (std::abs(int(this->getCurrentPlace().getLine()) - int(kingLine)) == 1))
    {
        return CheckMove;
    }
    if (differenceHorizontal == 1 || differenceHorizontal == -1)
    {
        if ((this->getPieceColor() == 'w' && differenceVertical == -1) ||
            (this->getPieceColor() == 'b' && differenceVertical == 1))
        {
            if (dest.hasPiece())
            {
                return GoodMove; 
            }
        }
        return NotValidMove; 
    }

    if ((this->getPieceColor() == 'w' && differenceVertical == -1) ||
        (this->getPieceColor() == 'b' && differenceVertical == 1))
    {
        if (!dest.hasPiece()) 
        {
            return GoodMove;
        }
    }
    if (dest.hasPiece())
    {
        return NotValidMove;
    }
    if ((this->getPieceColor() == 'w' && this->getCurrentPlace().getLine() == '2') ||
        (this->getPieceColor() == 'b' && this->getCurrentPlace().getLine() == '7'))
    {
        if (((this->getPieceColor() == 'w' && differenceVertical == -2) ||
            (this->getPieceColor() == 'b' && differenceVertical == 2)) && differenceHorizontal == 0)
        {
            middleRow = currentLine + (differenceVertical / 2) * -1;
            middlePosition = std::string(1, currentRow) + middleRow;

            if (board->getPiece(middlePosition) != nullptr)
            {
                return NotValidMove;
            }

            return GoodMove; 
        }
    }

    return NotValidMove; 
}
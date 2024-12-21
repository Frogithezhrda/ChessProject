#include "Rook.h"
#include "Board.h"

Rook::Rook(const char pieceColor, const Place& firstPlace) : Piece(pieceColor, (pieceColor == 'w' ? RookName : std::toupper(RookName)), firstPlace)
{

}


int Rook::isValidMove(const Place& dest, const Board* board) const
{
    char currentRow = this->getCurrentPlace().getLocation()[0];
    char currentLine = this->getCurrentPlace().getLocation()[1];
    char pieceColor = islower(dest.getCurrentPiece()) ? 'w' : 'b';

    if (this->getCurrentPlace().getCurrentPiece() == '#')
    {
        return 2; 
    }


    if ((!dest.hasPiece() || pieceColor != this->getPieceColor()) &&
        (currentRow == dest.getLocation()[0] || currentLine == dest.getLocation()[1]) && 
        dest.getLocation() != this->getCurrentPlace().getLocation() && isClearPath(dest, board))
    {
        return 0; 
    }

    return 6; 
}
void Rook::move(const Place& dest, const Board* board)
{
	if (!isValidMove(dest, board))
	{
		this->setCurrentPlace(dest);
	}
}

bool Rook::isClearPath(const Place& dest, const Board* board) const
{
    int i = 0;
    int startRow = std::min(this->getCurrentPlace().getLocation()[1] - '1', dest.getLocation()[1] - '1');
    int endRow = std::max(this->getCurrentPlace().getLocation()[1] - '1', dest.getLocation()[1] - '1');
    char currentRow = this->getCurrentPlace().getLocation()[0];
    std::string currentPos = "";
    if (currentRow == dest.getLocation()[0])  // Vertical movement
    {
        for (i = startRow + 1; i < endRow; i++)
        {
            currentPos = std::string(currentRow + std::to_string(i + 1));
            if (board->getPiece(currentPos) != nullptr)  // Check if the square is occupied
            {
                return false;
            }
        }
    }
    else if (this->getCurrentPlace().getLocation()[0] == dest.getLocation()[0])  // Horizontal movement
    {
        for (i = startRow + 1; i < endRow; i++)
        {
            currentPos = std::string(std::to_string(i + 1) + currentRow);
            if (board->getPiece(currentPos) != nullptr) 
            {
                return false;
            }
        }
    }

    return true; 
}

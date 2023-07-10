#include "Bishop.h"

/**
 * Checks if the bishop can move diagonally from the current position to the new position.
 *
 * @param currPos The current position of the bishop.
 * @param newPos The new position to which the bishop wants to move.
 * @return True if the bishop can move diagonally, false otherwise.
 */
bool Bishop::validMove(const Pos currPos, const Pos newPos) {
    int rowDifference = abs(currPos.row - newPos.row);
    int colDifference = abs(currPos.col - newPos.col);

    return rowDifference == colDifference;
}

/**
 * Registers the creation of a white bishop piece using the Factory pattern.
 * Returns a new unique_ptr to a PieceEntity object representing the white bishop.
 *
 * @return A unique_ptr to the new PieceEntity object.
 */
bool Bishop::m_createWhite = Factory<PieceEntity>::reg('B', []() -> std::unique_ptr<PieceEntity> {
    return std::make_unique<Bishop>(WHITE);
});

/**
 * Registers the creation of a black bishop piece using the Factory pattern.
 * Returns a new unique_ptr to a PieceEntity object representing the black bishop.
 *
 * @return A unique_ptr to the new PieceEntity object.
 */
bool Bishop::m_createBlack = Factory<PieceEntity>::reg('b', []() -> std::unique_ptr<PieceEntity> {
    return std::make_unique<Bishop>(BLACK);
});

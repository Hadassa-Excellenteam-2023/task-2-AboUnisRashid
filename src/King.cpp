#pragma once

#include "King.h"

/**
 * Checks if the king can move to the new position.
 *
 * @param currPos The current position of the king.
 * @param newPos The new position to move the king.
 * @return True if the move is valid, false otherwise.
 */
bool King::validMove(const Pos currPos, const Pos newPos) {
    // The king can move at most one block in any direction
    int rowDiff = abs(currPos.row - newPos.row);
    int colDiff = abs(currPos.col - newPos.col);

    return rowDiff <= 1 && colDiff <= 1;
}

// Initiate white king piece
bool King::m_createWhite = Factory<PieceEntity>::reg('K', []() -> std::unique_ptr<PieceEntity> {
    return std::make_unique<King>(WHITE);
});

// Initiate black king piece
bool King::m_createBlack = Factory<PieceEntity>::reg('k', []() -> std::unique_ptr<PieceEntity> {
    return std::make_unique<King>(BLACK);
});

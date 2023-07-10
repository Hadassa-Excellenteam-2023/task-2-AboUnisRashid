#pragma once

#include "Queen.h"

/**
 * Determines if the queen can move in any direction: straight or diagonally.
 *
 * @param currPos The current position of the queen.
 * @param newPos The new position to which the queen wants to move.
 * @return True if the move is valid, False otherwise.
 */
bool Queen::validMove(const Pos currPos, const Pos newPos) {
    // Check if the move is diagonal (same absolute difference in row and column)
    bool isDiagonal = (abs(currPos.row - newPos.row) == abs(currPos.col - newPos.col));

    // Check if the move is straight (same row or same column)
    bool isStraight = (currPos.row == newPos.row) || (currPos.col == newPos.col);

    // Return true if the move is either diagonal or straight
    return isDiagonal || isStraight;
}

// Initialize white pieces
bool Queen::m_createWhite = Factory<PieceEntity>::reg('Q', []() -> std::unique_ptr<PieceEntity> {
    return std::make_unique<Queen>(WHITE);
});

// Initialize black pieces
bool Queen::m_createBlack = Factory<PieceEntity>::reg('q', []() -> std::unique_ptr<PieceEntity> {
    return std::make_unique<Queen>(BLACK);
});

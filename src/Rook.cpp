#pragma once

#include "Rook.h"

/**
 * Checks if the rook can move straight (horizontally or vertically).
 *
 * @param currPos The current position of the rook.
 * @param newPos The new position to which the rook wants to move.
 * @return True if the rook can move straight, false otherwise.
 */
bool Rook::validMove(const Pos currPos, const Pos newPos) {
    bool sameRow = (currPos.row == newPos.row);
    bool sameCol = (currPos.col == newPos.col);
    return sameRow || sameCol;
}

// Initiate white pieces
bool Rook::m_registerWhite = Factory<PieceEntity>::reg('R', []() -> std::unique_ptr<PieceEntity> {
    return std::make_unique<Rook>(WHITE);
});

// Initiate black pieces
bool Rook::m_registerBlack = Factory<PieceEntity>::reg('r', []() -> std::unique_ptr<PieceEntity> {
    return std::make_unique<Rook>(BLACK);
});

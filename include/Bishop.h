#pragma once

#include <iostream>
#include "PieceEntity.h"

/**
 * @brief The Bishop class represents a bishop chess piece.
 *
 * This class inherits from the PieceEntity class and provides specific functionality
 * for a bishop piece. It overrides the validMove function to implement bishop-specific
 * move validation logic.
 */
class Bishop : public PieceEntity {
public:
    using PieceEntity::PieceEntity;

    /**
     * @brief Checks if a move from the current position to the new position is valid for a bishop.
     *
     * This function overrides the base class's validMove function to implement the bishop's move
     * validation logic. It checks if the bishop can move diagonally from the current position to
     * the new position.
     *
     * @param currPos The current position of the bishop.
     * @param newPos The new position to which the bishop wants to move.
     * @return True if the move is valid for a bishop, false otherwise.
     */
    bool validMove(const Pos currPos, const Pos newPos) override;

private:
    static bool m_createWhite; /**< Static member variable for initiating white bishops. */
    static bool m_createBlack; /**< Static member variable for initiating black bishops. */
};

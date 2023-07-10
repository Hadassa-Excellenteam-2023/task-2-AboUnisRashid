#pragma once

#include <iostream>
#include "PieceEntity.h"

/**
 * @class King
 * @brief Represents a King chess piece.
 *
 * The King class inherits from the PieceEntity class and extends its functionality
 * to represent a King chess piece. It provides a constructor inherited from PieceEntity
 * and implements a validMove function specific to the King piece.
 */
class King : public PieceEntity {
public:
    /**
     * @brief Constructs a King object.
     *
     * This constructor is inherited from the PieceEntity class and is used to create
     * a King chess piece with the specified color and position.
     *
     * @param color The color of the King piece ("white" or "black").
     * @param position The initial position of the King piece on the chessboard.
     */
    using PieceEntity::PieceEntity;

    /**
     * @brief Checks if a move is valid for the King piece.
     *
     * This function overrides the validMove function defined in the PieceEntity class
     * to provide the specific move validation logic for the King piece.
     *
     * @param currPos The current position of the King piece.
     * @param newPos The new position the King piece wants to move to.
     * @return True if the move is valid for the King piece, false otherwise.
     */
    bool validMove(const Pos currPos, const Pos newPos) override;

private:
    static bool m_createWhite; /**< Flag indicating if a white King piece should be created. */
    static bool m_createBlack; /**< Flag indicating if a black King piece should be created. */

};

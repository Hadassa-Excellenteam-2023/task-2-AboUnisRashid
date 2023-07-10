#pragma once

#include <iostream>
#include "PieceEntity.h"

/**
 * @class Rook
 * @brief Represents a Rook chess piece.
 *
 * The Rook class inherits from the PieceEntity class and extends its functionality
 * to represent a Rook chess piece. It provides a constructor inherited from PieceEntity
 * and implements a validMove function specific to the Rook piece.
 */
class Rook : public PieceEntity {
public:
    /**
     * @brief Constructs a Rook object.
     *
     * This constructor is inherited from the PieceEntity class and is used to create
     * a Rook chess piece with the specified color and position.
     *
     * @param color The color of the Rook piece ("white" or "black").
     * @param position The initial position of the Rook piece on the chessboard.
     */
    using PieceEntity::PieceEntity;

    /**
     * @brief Checks if a move is valid for the Rook piece.
     *
     * This function overrides the validMove function defined in the PieceEntity class
     * to provide the specific move validation logic for the Rook piece.
     *
     * @param currPos The current position of the Rook piece.
     * @param newPos The new position the Rook piece wants to move to.
     * @return True if the move is valid for the Rook piece, false otherwise.
     */
    bool validMove(const Pos currPos, const Pos newPos) override;

private:
    static bool m_registerWhite; /**< Flag indicating if a white Rook piece should be registered. */
    static bool m_registerBlack; /**< Flag indicating if a black Rook piece should be registered. */

};

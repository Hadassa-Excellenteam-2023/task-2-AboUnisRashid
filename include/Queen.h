#pragma once

#include <iostream>
#include "PieceEntity.h"

/**
 * @class Queen
 * @brief Represents a Queen chess piece.
 *
 * The Queen class inherits from the PieceEntity class and extends its functionality
 * to represent a Queen chess piece. It provides a constructor inherited from PieceEntity
 * and implements a validMove function specific to the Queen piece.
 */
class Queen : public PieceEntity {
public:
    /**
     * @brief Constructs a Queen object.
     *
     * This constructor is inherited from the PieceEntity class and is used to create
     * a Queen chess piece with the specified color and position.
     *
     * @param color The color of the Queen piece ("white" or "black").
     * @param position The initial position of the Queen piece on the chessboard.
     */
    using PieceEntity::PieceEntity;

    /**
     * @brief Checks if a move is valid for the Queen piece.
     *
     * This function overrides the validMove function defined in the PieceEntity class
     * to provide the specific move validation logic for the Queen piece.
     *
     * @param currPos The current position of the Queen piece.
     * @param newPos The new position the Queen piece wants to move to.
     * @return True if the move is valid for the Queen piece, false otherwise.
     */
    bool validMove(const Pos currPos, const Pos newPos) override;

private:
    static bool m_createWhite; /**< Flag indicating if a white Queen piece should be created. */
    static bool m_createBlack; /**< Flag indicating if a black Queen piece should be created. */

};

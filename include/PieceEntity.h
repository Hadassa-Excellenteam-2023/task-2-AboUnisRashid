#pragma once

#include <iostream>
#include <string>
#include "macros.h"
#include "Factory.h"

/**
 * @brief The base class for all chess pieces.
 *
 * This class is abstract and serves as the base class for all chess pieces.
 * It defines common behavior and properties shared by all pieces.
 */
class PieceEntity {
public:
    /**
     * @brief Constructs a PieceEntity object with the specified color.
     *
     * @param color The color of the piece (true for white, false for black).
     */
    PieceEntity(bool color) : m_color(color) {};

    /**
     * @brief Virtual destructor for the PieceEntity class.
     *
     * This virtual destructor ensures that derived classes can be properly destroyed through
     * a pointer to the base class.
     */
    virtual ~PieceEntity() = default;

    /**
     * @brief Checks if a move from the current position to the new position is valid.
     *
     * This pure virtual function is overridden by derived classes to implement specific
     * move validation logic for each type of chess piece.
     *
     * @param currPos The current position of the piece.
     * @param newPos The new position to which the piece wants to move.
     * @return True if the move is valid, false otherwise.
     */
    virtual bool validMove(const Pos currPos, const Pos newPos) = 0;

    /**
     * @brief Retrieves the color of the piece.
     *
     * @return The color of the piece (true for white, false for black).
     */
    bool getColor() const { return m_color; }

private:
    bool m_color = false; /**< The color of the piece (true for white, false for black). */
};

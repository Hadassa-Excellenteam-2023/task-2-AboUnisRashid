#pragma once

const bool WHITE = true; /**< Constant representing the color white. */
const bool BLACK = false; /**< Constant representing the color black. */

/**
 * @struct Pos
 * @brief Represents a position on a chessboard.
 *
 * The Pos struct is used to represent a position on a chessboard using
 * the row and column coordinates. It provides a convenient way to store
 * and access the position of a chess piece.
 */
struct Pos {
    int row; /**< The row coordinate of the position. */
    int col; /**< The column coordinate of the position. */
};
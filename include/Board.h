#pragma once

#include <iostream>
#include <vector>
#include "PieceEntity.h"
#include "Factory.h"

using std::string;

/**
 * @brief Represents the chess board and handles movements and responses.
 *
 * The Board class manages the chess board and handles the movements and responses
 * for each move made on the board.
 */
class Board {
public:
    /**
     * @brief Constructs a Board object with the initial board configuration.
     *
     * @param board The initial board configuration as a string.
     */
    Board(const std::string board) { appendPieces(board); }

    /**
     * @brief Gets the response code for a move on the board.
     *
     * This function receives the input from the user, checks the validity of the move,
     * and returns the corresponding response code.
     *
     * @param res The move input from the user as a string.
     * @return The response code indicating the result of the move.
     */
    int getResponse(const std::string& res);

private:
    /**
     * @brief Appends the chess pieces to the board based on the given configuration.
     *
     * This function initializes the board member by resizing it to the board size and
     * fills it with the correct pieces based on the provided board configuration.
     *
     * @param board The board configuration as a string.
     */
    void appendPieces(std::string board);

    /**
     * @brief Checks if the specified color is in check.
     *
     * This function receives the color of the player and checks if the player's king
     * is in check. It iterates through the board to find the position of the king and
     * checks if any opponent's pieces threaten the king.
     *
     * @param color The color of the player (true for white, false for black).
     * @return True if the player's king is in check, false otherwise.
     */
    bool checkForCheck(const bool color);

    /**
     * @brief Checks if the path from the current position to the new position is clear.
     *
     * This function receives the current position and the new position and checks if the
     * path between the two positions is clear, meaning there are no other pieces blocking
     * the way. It checks each step gradually to ensure a clear path.
     *
     * @param curPos The current position of the piece.
     * @param newPos The new position to which the piece wants to move.
     * @return True if the path is clear, false if there is a piece blocking the path.
     */
    bool nextStep(const Pos& curPos, const Pos& newPos);

    bool m_whitesTurn = true; /**< Indicates whether it is currently white's turn to move. */
    Pos m_kingPos; /**< The position of the king on the board. */
    std::vector<std::vector<std::unique_ptr<PieceEntity>>> m_board; /**< The chess board represented as a 2D vector of piece pointers. */
};

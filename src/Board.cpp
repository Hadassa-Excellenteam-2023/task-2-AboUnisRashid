#include "Board.h"
#include "King.h"

/**
 * Initializes the board by creating and positioning the pieces based on the provided board string.
 *
 * @param board The string representing the initial board configuration.
 */
void Board::appendPieces(std::string board) {
    m_board.resize(8);
    for (auto& row : m_board) {
        row.resize(8);
    }

    for (int i = 0; i < board.size(); ++i) {
        int row = i / 8;
        int col = i % 8;
        m_board[row][col] = Factory<PieceEntity>::createPiece(board[i]);
    }
}


/**
 * Retrieves the response code for a given move.
 *
 * @param res The string representing the move made by the player.
 * @return The response code indicating the result of the move.
 */
int Board::getResponse(const std::string& res) {
    Pos currPos = { res[0] - 'a', res[1] - '1' };
    Pos newPos = { res[2] - 'a', res[3] - '1' };

    // Check if the current position does not have a piece
    if (m_board[currPos.row][currPos.col] == nullptr) {
        return 11;
    }

    // Check if the current position is occupied by the opponent
    if (m_board[currPos.row][currPos.col]->getColor() != m_whitesTurn) {
        return 12;
    }

    // Check if the new position has the same color as the current player
    if (m_board[newPos.row][newPos.col] && m_board[currPos.row][currPos.col]->getColor() == m_board[newPos.row][newPos.col]->getColor()) {
        return 13;
    }

    // Check if the move of the piece is valid or not
    if (!m_board[currPos.row][currPos.col]->validMove(currPos, newPos) || !nextStep(currPos, newPos)) {
        return 21;
    }

    // Move the piece to the new position
    std::unique_ptr<PieceEntity> movedPiece = std::move(m_board[currPos.row][currPos.col]);
    m_board[newPos.row][newPos.col] = std::move(movedPiece);

    // Check if the new position causes a check on the player's king
    if (checkForCheck(m_whitesTurn)) {
        std::unique_ptr<PieceEntity> revertedPiece = std::move(m_board[newPos.row][newPos.col]);
        m_board[currPos.row][currPos.col] = std::move(revertedPiece);
        return 31;
    }

    // Change turns
    m_whitesTurn = !m_whitesTurn;

    // Check if a check is caused to the opponent's king
    if (checkForCheck(!m_whitesTurn)) {
        return 41;
    }

    // A valid move
    return 42;
}


/**
 * Checks if the specified color's king is in check.
 *
 * @param color The color of the player.
 * @return True if the king is in check, false otherwise.
 */
bool Board::checkForCheck(const bool color) {
    // Find the position of the king
    Pos kingPos;
    PieceEntity* king = nullptr;

    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            if (m_board[row][col] != nullptr) {
                if (m_board[row][col]->getColor() == WHITE && typeid(*m_board[row][col]) == typeid(King)) {
                    kingPos = { row, col };
                    king = m_board[row][col].get();
                    break;
                }
            }
        }
    }

    if (!king) {
        return false; // King not found, not in check
    }

    // Check for pieces threatening the king
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            if (m_board[row][col] != nullptr && m_board[row][col]->getColor() != WHITE) {
                Pos piecePos = { row, col };
                if (m_board[row][col]->validMove(piecePos, kingPos) && nextStep(piecePos, kingPos)) {
                    return true; // King is in check
                }
            }
        }
    }

    return false; // King is not in check
}


/**
 * Checks if the path from the current position to the new position is clear, without any obstacles.
 *
 * @param curPos The current position.
 * @param newPos The new position.
 * @return True if the path is clear, false if the path is blocked by another piece.
 */
bool Board::nextStep(const Pos& curPos, const Pos& newPos) {
    int deltaRow = newPos.row - curPos.row;
    int deltaCol = newPos.col - curPos.col;

    int rowDir = (deltaRow > 0) - (deltaRow < 0);
    int colDir = (deltaCol > 0) - (deltaCol < 0);

    int checkRow = curPos.row + rowDir;
    int checkCol = curPos.col + colDir;

    while (checkRow != newPos.row || checkCol != newPos.col) {
        if (m_board[checkRow][checkCol] != nullptr) {
            return false; // Path is blocked by another piece
        }
        checkRow += rowDir;
        checkCol += colDir;
    }

    return true; // Path is clear
}

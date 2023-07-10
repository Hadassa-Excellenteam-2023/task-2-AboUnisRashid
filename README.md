# task-2-AboUnisRashid
Here's an alternative description of the Chess Game:

The Chess Game is a C++ console application that lets two players play against each other following all the standard rules of chess. It is built using CMake as the build system.

Gameplay:

1. Upon starting the game, the console displays the chessboard, representing the current state of the game.
2. Players take turns moving their pieces by providing the coordinates of the piece they want to move and the coordinates of the destination square. For example, a player can enter "A2A4" to move a pawn from square A2 to A4.
3. The game validates the legality of moves, ensuring that players adhere to the rules of chess. If an illegal move is attempted, the game notifies the player and prompts them to make a valid move.
4. If a player's move results in the opponent's king being in check, the game alerts the player accordingly.
5. If a player's move leads to checkmate, where the opponent's king is unable to escape capture, the game ends, and the player responsible for checkmate is declared the winner.
6. In the event of a stalemate, where a player has no legal moves but their king is not in check, the game ends in a draw.

Features:

1. The game fully implements standard chess rules, including advanced moves like castling and en passant.
2. It accurately tracks the state of the board, ensuring that only legal moves can be made.
3. The game provides immediate feedback to players, notifying them of illegal moves and important events such as checks and checkmates. This is done through response codes or messages displayed on the console.

Overall, this Chess Game provides an interactive and challenging environment for players to enjoy a game of chess, enforcing the rules and offering real-time feedback on the game's progression.
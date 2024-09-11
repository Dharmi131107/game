#include <iostream>
#include <vector> // This line is needed for std::vector

const char EMPTY = ' ';
const char PLAYER_X = 'X';
const char PLAYER_O = 'O';
const int SIZE = 3;

void printBoard(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cout << board[i][j];
            if (j < SIZE - 1) std::cout << " | ";
        }
        std::cout << std::endl;
        if (i < SIZE - 1) {
            std::cout << "--|---|--" << std::endl;
        }
    }
}

bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

bool checkDraw(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == EMPTY) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::vector<std::vector<char>> board(SIZE, std::vector<char>(SIZE, EMPTY));
    char currentPlayer = PLAYER_X;
    bool gameWon = false;

    std::cout << "Tic-Tac-Toe Game" << std::endl;
    printBoard(board);

    while (!gameWon && !checkDraw(board)) {
        int row, col;
        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        std::cin >> row >> col;

        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != EMPTY) {
            std::cout << "Invalid move. Try again." << std::endl;
            continue;
        }

        board[row][col] = currentPlayer;
        printBoard(board);

        if (checkWin(board, currentPlayer)) {
            gameWon = true;
            std::cout << "Player " << currentPlayer << " wins!" << std::endl;
        } else {
            currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
        }
    }

    if (!gameWon) {
        std::cout << "It's a draw!" << std::endl;
    }

    return 0;
}

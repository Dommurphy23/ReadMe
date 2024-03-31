#include <iostream>
using namespace std;

// Base class for the Tic-Tac-Toe game
class TicTacToe {
protected:
    char board[3][3];

public:
    TicTacToe() {
        // Initialize the board with empty spaces
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = ' ';
            }
        }
    }

    // Display the Tic-Tac-Toe board
    void displayBoard() {
        cout << "  1 2 3" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << i + 1 << " ";
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Check if a move is valid
    bool isValidMove(int row, int col) {
        return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ';
    }

    // Make a move
    void makeMove(int row, int col, char symbol) {
        if (isValidMove(row, col)) {
            board[row][col] = symbol;
        } else {
            cout << "Invalid move!" << endl;
        }
    }

    // Check if the game is over
    virtual bool isGameOver() {
        // Check rows
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
                return true;
            }
        }
        // Check columns
        for (int j = 0; j < 3; ++j) {
            if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[0][j] == board[2][j]) {
                return true;
            }
        }
        // Check diagonals
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
            return true;
        }
        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
            return true;
        }
        // Check if the board is full
        bool full = true;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    full = false;
                    break;
                }
            }
            if (!full) {
                break;
            }
        }
        return full;
    }
};

// Class for a single game of Tic-Tac-Toe
class SingleGame : public TicTacToe {
private:
    char currentPlayer;

public:
    SingleGame() {
        currentPlayer = 'X'; // 'X' starts the game
    }

    // Start a new game
    void startGame() {
        cout << "Starting new game..." << endl;
        displayBoard();
        while (!isGameOver()) {
            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row col): ";
            cin >> row >> col;
            makeMove(row - 1, col - 1, currentPlayer);
            displayBoard();
            if (currentPlayer == 'X') {
                currentPlayer = 'O';
            } else {
                currentPlayer = 'X';
            }
        }
        if (isGameOver()) {
            cout << "Game Over!" << endl;
        }
    }
};

int main() {
    SingleGame game;
    game.startGame();
    return 0;
}

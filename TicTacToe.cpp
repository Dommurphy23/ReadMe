#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board;

public:
    TicTacToe() {
        // The board
        board = {{' ', ' ', ' '},
                 {' ', ' ', ' '},
                 {' ', ' ', ' '}};
    }

    void printBoard() {
        cout << "-------------" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "| ";
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j] << " | ";
            }
            cout << endl;
            cout << "-------------" << endl;
        }
    }

    bool placeMarker(int row, int col, char marker) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            return false;
        }
        board[row][col] = marker;
        return true;
    }

    bool checkWin(char marker) {
        // Rows and columns
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == marker && board[i][1] == marker && board[i][2] == marker) return true;
            if (board[0][i] == marker && board[1][i] == marker && board[2][i] == marker) return true;
        }

        // Diagonals
        if (board[0][0] == marker && board[1][1] == marker && board[2][2] == marker) return true;
        if (board[0][2] == marker && board[1][1] == marker && board[2][0] == marker) return true;

        return false;
    }
};

int main() {
    TicTacToe game;
    char currentPlayer = 'X';

    while (true) {
        int row, col;
        cout << "Player " << currentPlayer << ", enter row and column (0-2): ";
        cin >> row >> col;

        if (game.placeMarker(row, col, currentPlayer)) {
            game.printBoard();
            if (game.checkWin(currentPlayer)) {
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }
            if (currentPlayer == 'X') {
                currentPlayer = 'O';
            } else {
                currentPlayer = 'X';
            }
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }

    return 0;
}
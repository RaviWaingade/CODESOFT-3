#include <iostream>
#include <vector>
using namespace std;

// Function prototypes
void displayBoard(const vector<vector<char>>& board);
bool isWinner(const vector<vector<char>>& board, char player);
bool isDraw(const vector<vector<char>>& board);
void playGame();

int main() {
    char playAgain;
    do {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
    
    return 0;
}

void displayBoard(const vector<vector<char>>& board) {
    cout << "\n";
    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool isWinner(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
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

bool isDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            if (cell == '-') {
                return false;
            }
        }
    }
    return true;
}

void playGame() {
    vector<vector<char>> board(3, vector<char>(3, '-'));
    char currentPlayer = 'X';
    bool gameOver = false;

    cout << "Welcome to Tic-Tac-Toe!\n";

    while (!gameOver) {
        displayBoard(board);
        
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column: 0, 1, or 2): ";
        cin >> row >> col;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == '-') {
            board[row][col] = currentPlayer;

            if (isWinner(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!\n";
                gameOver = true;
            } else if (isDraw(board)) {
                displayBoard(board);
                cout << "It's a draw!\n";
                gameOver = true;
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        } else {
            cout << "Invalid move. Try again.\n";
        }
    }
}

#include <iostream>
using namespace std;

const int BOARD_SIZE = 3;

void initializeBoard(char board[][BOARD_SIZE]){
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE;++j){
            board[i][j] = '*';
        }
    }
}

void displayBoard(const char board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkWinner(const char board[][BOARD_SIZE], char player) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) { 
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||  
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool isBoardFull(const char board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == '*') {
                return false; 
            }
        }
    }
    return true; 
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    initializeBoard(board);

    bool gameOver = false;
    char currentPlayer = 'X';

    while (!gameOver) {
        cout << "Current board:\n";
        displayBoard(board);

        int row, col;
        cout << "Player " << currentPlayer << ", enter row and column (1-3) to place your symbol: ";
        cin >> row >> col;

        
        row--;
        col--;

        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != '*') {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWinner(board, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!\n";
            gameOver = true;
        }
       
        else if (isBoardFull(board)) {
            cout << "It's a tie!\n";
            gameOver = true;
        }
      currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    cout << "Final board:\n";
    displayBoard(board);

    return 0;
}

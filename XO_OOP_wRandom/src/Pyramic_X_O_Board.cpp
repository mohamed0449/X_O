#include"../include/BoardGame_Classes.hpp"
#include <bits/stdc++.h>

using namespace std;

Pyramic_X_O_Board::Pyramic_X_O_Board() {
    n_rows=6; n_cols=7;
    board = new char*[n_rows];
    for (int i = 0; i <  n_rows; ++i) {
        board [i] = new char[n_cols];
        for (int j = 0; j <  n_cols; ++j) {
            board[i][j] = ' ';
        }
    }
}

bool Pyramic_X_O_Board::update_board (int x, int y, char mark){
    // Only update if move is valid
    if (!(x < 0 || x > 6 || y < 0 || y > 7) && (board[x][y] == ' ')) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

void Pyramic_X_O_Board::display_board() {
    for (int i: {0,1,2,3,4,5}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4,5,6}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(6) << board [i][j] << " |";
        }
        cout << "\n-----------------------------------------------------------------------------------";
    }
    cout << endl;
}
bool Pyramic_X_O_Board::is_winner() {

    // Check for horizontal win
    for (int i = 0; i <  n_rows; ++i) {
        for (int j = 0; j <=  n_cols - 4; ++j) {
            if (board[i][j] != ' ' &&
                board[i][j] == board[i][j + 1] &&
                board[i][j] == board[i][j + 2] &&
                board[i][j] == board[i][j + 3]) {
                return true;
            }
        }
    }

    // Check for vertical win
    for (int i = 0; i <=  n_rows - 4; ++i) {
        for (int j = 0; j <  n_cols; ++j) {
            if (board[i][j] != ' ' &&
                board[i][j] == board[i + 1][j] &&
                board[i][j] == board[i + 2][j] &&
                board[i][j] == board[i + 3][j]) {
                return true;
            }
        }
    }

    // Check for diagonal win (from bottom left to top right)
    for (int i = 3; i <  n_rows; ++i) {
        for (int j = 0; j <=  n_cols - 4; ++j) {
            if (board[i][j] != ' ' &&
                board[i][j] == board[i - 1][j + 1] &&
                board[i][j] == board[i - 2][j + 2] &&
                board[i][j] == board[i - 3][j + 3]) {
                return true;
            }
        }
    }

    // Check for diagonal win (from top left to bottom right)
    for (int i = 0; i <=  n_rows - 4; ++i) {
        for (int j = 0; j <=  n_cols - 4; ++j) {
            if (board[i][j] != ' ' &&
                board[i][j] == board[i + 1][j + 1] &&
                board[i][j] == board[i + 2][j + 2] &&
                board[i][j] == board[i + 3][j + 3]) {
                return true;
            }
        }
    }

    return false; // No winner yet
}

bool Pyramic_X_O_Board::is_draw() {
    return (n_moves == 42 && !is_winner());
}

bool Pyramic_X_O_Board::game_is_over () {
    return n_moves >= 42;
}
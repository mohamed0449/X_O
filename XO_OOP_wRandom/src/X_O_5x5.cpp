#include <bits/stdc++.h>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

// Set the board
X_O_5x5::X_O_5x5(){
    n_rows = n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}


bool X_O_5x5 :: update_board (int x, int y, char mark){
    // Only update if move is valid
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

// Display the board and the pieces on it
void X_O_5x5:: display_board(){
    for (int i: {0,1,2,3,4}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(4) << board [i][j] << " |";
        }
        cout << "\n-----------------------------------------------------";
    }
    cout << endl;
}
bool X_O_5x5::is_winner(){

    for (int c = 0; c < 5; c++) {
        for (int r = 0; r < 3; r++) {
            if (board[r][c] == board[r + 1][c] && board[r + 1][c] == board[r + 2][c] && board[r][c] == 'X') {
                counter_X++;
            } else if (board[r][c] == board[r + 1][c] && board[r + 1][c] == board[r + 2][c] && board[r][c] == 'O') {
                counter_O++;
            }
        }
    }

    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 3; c++) {
            if (board[r][c] == board[r][c + 1] && board[r][c + 1] == board[r][c + 2] && board[r][c] == 'X') {
                counter_X++;
            } else if (board[r][c] == board[r][c + 1] && board[r][c + 1] == board[r][c + 2] && board[r][c] == 'O') {
                counter_O++;
            }
        }
    }

    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (board[r][c] == board[r + 1][c + 1] && board[r + 1][c + 1] == board[r + 2][c + 2] &&
                board[r][c] == 'X') {
                counter_X++;
            } else if (board[r][c] == board[r + 1][c + 1] && board[r + 1][c + 1] == board[r + 2][c + 2] &&
                       board[r][c] == 'O') {
                counter_O++;
            }
        }
    }

    for (int r = 2; r < 5; r++) {
        for (int c = 2; c < 5; c++) {
            if (board[r][c] == board[r - 1][c - 1] && board[r - 1][c - 1] == board[r - 2][c - 2] &&
                board[r][c] == 'X') {
                counter_X++;
            } else if (board[r][c] == board[r - 1][c - 1] && board[r - 1][c - 1] == board[r - 2][c - 2] &&
                       board[r][c] == 'O') {
                counter_O++;
            }
        }
    }

    if(counter_O>counter_X && n_moves >23 ){
        cout<<"O player is win"<<endl;
        cout<<"the # of counter O is = "<<counter_O<<endl;
        cout<<"the # of counter X is = "<<counter_X<<endl;
    }
    else if( counter_O < counter_X && n_moves >23) {
        cout << "X player is win" << endl;
        cout<<"the # of counter O is = "<<counter_O<<endl;
        cout<<"the # of counter X is = "<<counter_X<<endl;
    }
    return false;
}
// Return true if 24 moves are done and no winner
bool X_O_5x5::is_draw(){
    return (n_moves == 24 &&counter_O==counter_X);
}
bool X_O_5x5::game_is_over(){
    return n_moves >= 24;
}
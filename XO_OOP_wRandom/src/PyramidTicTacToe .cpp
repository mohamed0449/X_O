#include <bits/stdc++.h>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

PyramidTicTacToe::PyramidTicTacToe(){
    n_rows = 3 ;
    n_cols = 5 ;
    board = new char *[n_rows] ;
    for(int i=0 ; i<n_rows ; i++){
        board[i] = new char[n_rows] ;
        for (int j=0 ; j<n_cols ; j++){
            board[i][j] = ' ' ;
        }
    }
}
bool PyramidTicTacToe::update_board(int x, int y, char mark) {
    // Check if the move is valid
    if (!(x < 0 || x > 2 || y < 0 || y >  4 )&& (board[x][y] == ' ')) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }

    // Update the board with the player's move
    else
        return false;
}

void PyramidTicTacToe::display_board() {
    // Display the current state of the board
    for (int i: {0,1,2}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4}) {
            if(i==0 && j==0 || i==0 && j==1 || i==0 && j==3 ||i==0 && j==4 ||i==1 && j==0 ||i==1 && j==4 ){// cases off Failures
                cout<<"        |";
                continue;
            }
            cout << "(" << i << "," << j << ")";
            cout << setw(4) << board [i][j] << " |";
        }
        cout << "\n-------------------------------------------------------";
    }
    cout << endl;
}

bool PyramidTicTacToe::is_winner() {



    if ((board[2][0] == board[2][1] && board[2][0] ==board[2][2] && board[2][0] != ' ') ||
    (board[2][1] == board[2][2]&&board[2][1] ==board[2][3]&& board[2][3]!=' ') ||
        (board[2][2] == board[2][3]&&board[2][2] ==board[2][4]&&board[2][4]!=' ') ||
        (board[1][1] == board[1][2]&&board[1][1] ==board[1][3]&&board[1][3]!= ' ') ||
        (board[0][2] == board[1][2]&&board[0][2] ==board[2][2]&&board[2][2]!=' ') ||
        (board[0][2] == board[1][3]&&board[0][2] ==board[2][4]&&board[2][4]!=' ') ||
        (board[0][2] == board[1][1]&&board[0][2] ==board[2][0] && board[2][0]!=' ')){
        return true;
    }

    else
        return false;

}

bool PyramidTicTacToe::is_draw() {
    // Check if the board is full and there is no winner
    return (n_moves == 15 && !is_winner());

}

bool PyramidTicTacToe::game_is_over() {
    return n_moves >= 15;
}

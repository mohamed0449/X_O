// Mohamed Gomaa Mohamed     20220449 mhmd2004221@gmail.com
// Mohab Mohammad Abdelwahed 20220472 mohab.fcai@gmail.com
// Ammar Mohsen Abdelaziz    20220214 ammarmohsan@gmail.com


#include <iostream>
#include"../include/BoardGame_Classes.hpp"
using namespace std;

int main() {
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        //Player pointer points to child
        players[1] = new RandomPlayer ('o', 3);

    int gameChoice;
    cout<<"Choose what game you want to play: "<<endl;
    cout<<"1: PyramidTicTacToe "<<endl;
    cout<<"2: Pyramic_X_O_Board"<<endl;
    cout<<"3: 5x5 Tic Tac Toe"<<endl;
    cout<<"4: X_O_Board 3x3"<<endl;
    cin>>gameChoice;
    if (gameChoice==1){
        GameManager x_o_game1 (new PyramidTicTacToe(), players);
        x_o_game1.run();
    }
    else if (gameChoice==2) {
        GameManager x_o_game2(new Pyramic_X_O_Board(), players);
        x_o_game2.run();
    }
    else if (gameChoice==3) {
        GameManager x_o_game3(new X_O_5x5(), players);
        x_o_game3.run();
    }
    else if (gameChoice==4) {
        GameManager x_o_game4 (new X_O_Board(), players);
        x_o_game4.run();
    }
    else{
        cout<<"Invalid choice!";
    }

    system ("pause");
}
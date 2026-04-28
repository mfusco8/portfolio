#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    vector<int> board(9);
    vector<int> goal = {1, 2, 3, 4, 5, 6, 7, 8, 0};

    int blankIndex = -1;

    for (int i =0; i < 9; i++){
        if (!(cin >> board [i])) break;
        if (board[i] == 0) blankIndex = i;
    }

    string command;
    while (cin >> command){
        int row = blankIndex / 3;
        int col = blankIndex % 3;
        int targetIndex = -1;

        if (command == "UP" || command == "U"){
            if (row >0) targetIndex = blankIndex -3;
        } 
        else if (command == "DOWN" || command == "D"){
            if (row < 2) targetIndex = blankIndex + 3;
        } 
        else if (command == "LEFT" || command == "L"){
            if (col > 0) targetIndex = blankIndex - 1;
        } 
        else if (command == "RIGHT" || command == "R"){
            if (col < 2) targetIndex = blankIndex + 1;
        }

        if (targetIndex != -1){
            int temp = board[blankIndex];
            board[blankIndex] = board[targetIndex];
            board[targetIndex] = temp;
            blankIndex = targetIndex;
        }
    }

    bool isSolved = true;
    for (int i = 0; i < 9; i++){
        if (board[i] != goal[i]){
            isSolved = false;
            break;
        }
    }

    if (isSolved){
        cout << "Solution is good!" << endl;
    }
    else{
        cout << "Wrong solution!" << endl;
    }

    return 0;
}

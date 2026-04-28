#include <iostream>

using namespace std;

int main(){
    int board [9][9];

    for (int r = 0; r < 9; r++){
        for (int c = 0; c < 9; c++){
            if (!(cin >> board[r][c])) return 0;
        }
    }

    for (int r = 0; r < 9; r++){
        bool seen[10] = {false};
        for (int c = 0; c < 9; c++){
            int num = board[r][c];
            if (num < 1 || num > 9 || seen[num]){
                cout << "Wrong solution!" << endl;
                return 0;
            }
            seen[num] = true;
        }
    }

    for (int c = 0; c < 9; c++){
        bool seen[10] = {false};
        for (int r = 0; r < 9; r++){
            int num = board[r][c];
            if (num < 1 || num > 9 || seen[num]){
                cout << "Wrong solution!" << endl;
                return 0;
            }
            seen[num] = true;
        }
    }

    for (int box = 0; box < 9; box += 3){
        for (int boxCol = 0; boxCol < 9; boxCol += 3){
            bool seen[10] = {false};
            for (int r = 0; r < 3; r++){
                for (int c = 0; c < 3; c++){
                    int num = board[box + r][boxCol + c];
                    if (num < 1 || num > 9 || seen[num]){
                        cout << "Wrong solution!" << endl;
                        return 0;
                    }
                    seen[num] = true;
                }
            }
        }
    }

    cout << "Solution is good!" << endl;
    return 0;
}


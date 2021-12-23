#include <iostream>
using namespace std;

bool canBePlaced(int board[256][256], int rowNum, int colNum, int size) {
    //checking in the row
    for(int i = 0;i<size;i++) {
        if(i == colNum) continue;
        if(board[rowNum][i] == 1) {
            return false;
        }
    }

    //checking the col
    for(int i=0;i<size;i++) {
        if(i == rowNum) continue;
        if(board[i][colNum] == 1){
            return false;
        } 
    }

    //checking the diagonals
    for(int i = 0 ; i < )



}

bool nqueen(int board[256][256], int rowNum, int size, int &soln){
    //base case
    if(rowNum == size) {
        for(int row = 0;row < size; row++) {
            for(int col = 0; col < size; col++) {
                cout << board[row][col] << " ";
            }
            cout << endl;
        }
        soln++;
    }


    for(int i = 0 ; i < size ; i++) {
        board[rowNum][i] = 1;

    } 
}

int main() {
    int n;
    cout << "Enter the size of the board: " << endl;
    cin >> n;



    return 0;
}
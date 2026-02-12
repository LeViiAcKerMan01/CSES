#include<bits/stdc++.h>
using namespace std;
# define ll long long

int main(){

    vector<string> chessBoard(8);
    for(int i = 0; i < 8; i++){
        cin >> chessBoard[i];
    }
    int count = 0;
    vector<int> columns(8);
    iota(columns.begin(), columns.end(), 0);

    do{
        bool valid = true;

        // to check if a queen is placed on the square that is already used
        for(int i = 0; i < 8; i++){
            if(chessBoard[i][columns[i]] != '.'){
                // the square is already reserved
                valid = false;
                break;
            }
        }
        // to check for diagonals weather the diagonal is already occupied or not
        // diagonals starting from right to left
        vector<bool> diagonalOccupied(15, false);

        for(int i = 0; i < 8; i++){
            if(diagonalOccupied[i + columns[i]]){
                valid = false;
            }
            diagonalOccupied[i + columns[i]] = true;
        }

        // to check for the main diagonals(other diagonals)
        // starting from left to right
        for(int i = 0; i < 15; i++){
            diagonalOccupied[i] = false;
        }

        for(int i = 0; i < 8; i++){
            
            if(diagonalOccupied[7 + columns[i] - i]){
                valid = false;
            }
            diagonalOccupied[ 7 + columns[i] - i] = true;
        }
        count += valid;
    }while(next_permutation(columns.begin(), columns.end()));

    cout<<count<<endl;
}
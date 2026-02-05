#include<bits/stdc++.h>
using namespace std;

int getVal(vector<vector<int>> grid, int i, int j, int R, int C){
    if(i < 0 || i >= R || j < 0 || j >= C){
        return 0;
    }else{
        return grid[i][j];
    }
}

void findMaxBlock(vector<vector<int>> grid, vector<vector<bool>> visited, int size, int &maxSize, int r, int c, int R, int C){
    // if(r >= R || c >= C){
    //     return;
    // }
    visited[r][c] = true;
    size++;
    if(size > maxSize){
        maxSize = size;
    }
    int direction[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, 1}, {-1, -1}, {1, 1}, {1, -1}};
    for(int i = 0; i < 8; i++){
        int newRow = r + direction[i][0];
        int newCol = c + direction[i][1];
        int val = getVal(grid, newRow, newCol, R, C);
        if(val > 0 && visited[newRow][newCol] == false){
            findMaxBlock(grid, visited, size, maxSize, newRow, newCol, R, C);
        }
    }
    visited[r][c] = false;
}
int getMaxOnes(vector<vector<int>> grid, int R, int C){
    int size = 0;
    int maxSize = 0;

    vector<vector<bool>> visited(R, vector<bool>(C, false));


    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(grid[i][j] == 1){
                findMaxBlock(grid, visited, 0, maxSize, i, j, R, C);
            }
        }
    }
    return maxSize;
}
int main(){
    int R, C;
    cin >> R >> C;
    vector<vector<int>> grid(R, vector<int>(C, 0));

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> grid[i][j];
        }
    }

    cout<<"Maximum number of 1's are :"<<getMaxOnes(grid, R, C);
}
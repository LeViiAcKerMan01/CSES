#include<bits/stdc++.h>
using namespace std;

bool isValid(int currRow, int currCol, int R, int C){
    if(currRow < 0 || currRow >= R || currCol < 0 || currCol >= C){
        return false;
    }
    return true;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);

    // taking a row of characters as the input
    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            set<char> not_allowed;

            not_allowed.insert(grid[i][j]);
            // To check for the left square
            if(isValid(i, j-1, n, m)){
                not_allowed.insert(grid[i][j-1]);
            }
            // To check for the upper square
            if(isValid(i-1, j, n, m)){
                not_allowed.insert(grid[i-1][j]);
            }

            bool filled = false;

            for(int k = 0; k < 4; k++){
                char ch = 'A' + k;
                if(not_allowed.find(ch) == not_allowed.end()){
                    grid[i][j] = ch;
                    filled = true;
                    break;
                }
            }
            if(!filled){
                cout<<"IMPOSSIBLE"<<"\n";
                return;
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout<<grid[i]<<"\n";
    }
}

int main(){
    solve();
}
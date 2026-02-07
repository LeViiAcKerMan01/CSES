#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> chessboard(n, "");
    for(int i = 0; i < n; i++){
        cin >> chessboard[i];
    }
    vector<pair<int, int>> moves = {{2, 1}, {2, -1}, {-2, -1}, {-2, 1}, {1, -2}, {1, 2}, {-1, -2}, {-1, 2}};
    vector<vector<int>> dist(n, vector<int>(n, -1));
    pair<int, int> start = {0, 0};

    queue<pair<int, int>> q;
    dist[start.first][start.second] = 0;
    q.push(start);
    
    while(!q.empty()){
        auto p = q.front();
        q.pop();

        for(int i = 0; i < 8; i++){
            int dx = p.first + moves[i].first;
            int dy = p.second + moves[i].second;
            if(dx >= 0 && dx < n && dy >= 0 && dy < n && dist[dx][dy] == -1){
                dist[dx][dy] = dist[p.first][p.second] + 1;
                q.push({dx, dy});
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
    }
}
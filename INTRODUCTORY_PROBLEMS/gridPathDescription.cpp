#include<bits/stdc++.h>
using namespace std;
#define ln '\n'
#define isValid(a, b, c) (a >= b && a < c)
typedef long long ll;

string str;
int vis[9][9];  // Use 9x9 to avoid boundary checks
int ans = 0;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void countPaths(int x, int y, int pos) {
    // Base cases
    if (x == 7 && y == 1) {  // Target is (7,1) if using 1-indexed
        if (pos == 48) ans++;
        return;
    }
    
    if (pos == 48) return;
    
    // Optimizations
    
    // Check if current cell is visited
    if (vis[x][y]) return;
    
    // Dead end detection - important optimization!
    // If we're not at the target and we can't move forward
    if (vis[x-1][y] && vis[x+1][y] && !vis[x][y-1] && !vis[x][y+1]) return;
    if (vis[x][y-1] && vis[x][y+1] && !vis[x-1][y] && !vis[x+1][y]) return;
    
    // Check if we've split the grid into two disconnected parts
    // if (vis[x-1][y] && vis[x+1][y] && !vis[x][y-1] && !vis[x][y+1]) return;
    // if (vis[x][y-1] && vis[x][y+1] && !vis[x-1][y] && !vis[x+1][y]) return;
    
    vis[x][y] = 1;
    
    if (str[pos] == '?') {
        // Try all four directions
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (!vis[nx][ny]) {
                countPaths(nx, ny, pos + 1);
            }
        }
    }
    else {
        // Move in specified direction
        int dir;
        if (str[pos] == 'R') dir = 0;
        else if (str[pos] == 'L') dir = 1;
        else if (str[pos] == 'D') dir = 2;
        else if (str[pos] == 'U') dir = 3;
        
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (!vis[nx][ny]) {
            countPaths(nx, ny, pos + 1);
        }
    }
    
    vis[x][y] = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> str;
    
    // Initialize borders as visited (1-indexed grid)
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i <= 8; i++) {
        vis[0][i] = vis[8][i] = vis[i][0] = vis[i][8] = 1;
    }
    
    countPaths(1, 1, 0);
    cout << ans << ln;
    
    return 0;
}
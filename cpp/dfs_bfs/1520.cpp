#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n,m;
int graph[501][501];
int dp[501][501];
bool check[501][501];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

int dfs(int x, int y){
    if(check[x][y]) return dp[x][y];
    if(x == n-1 && y == m-1) return 1;
    for(int i=0;i<4;i++){
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];
        if(dx > n-1 || dy > m-1 || dx < 0 || dy < 0){
            continue;
        }
        if(graph[dx][dy] < graph[x][y]){
            dp[x][y] += dfs(dx,dy);
        }
    }

    check[x][y] = true;
    return dp[x][y];
}


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> graph[i][j];
        }
    }

    cout << dfs(0,0) << '\n';

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
}
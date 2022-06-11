#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n,m,k;
int graph[1001][1001];
int check[11][1001][1001];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

struct Matrix {
    int zindex, x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        for(int j=0;j<m;j++){
            graph[i][j] = str[j] - '0';
        }
    }
    queue<Matrix> q;
    q.push({0,0,0});
    check[0][0][0] = 1;
    while(!q.empty()){
        Matrix cur = q.front();
        q.pop();
        int zindex =cur.zindex;
        int x =cur.x;
        int y =cur.y;
        if(x == n-1 && y == m-1){
            cout << check[zindex][n-1][m-1] << '\n';
            return 0;
        }
        for(int i=0;i<4;i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(dx<0 || dy<0 || dx>n-1 || dy>m-1)
                continue;
            if(check[zindex][dx][dy]){
                continue;
            }
            if(graph[dx][dy] == 0){
                check[zindex][dx][dy] = check[zindex][x][y] + 1;
                q.push({zindex, dx, dy}); 
            }else if(graph[dx][dy] == 1 && zindex + 1 <= k && !check[zindex+1][dx][dy]){
                check[zindex + 1][dx][dy] = check[zindex][x][y] + 1;
                q.push({zindex + 1, dx, dy}); 
            }
        }
    }
    cout << -1 << '\n';
}
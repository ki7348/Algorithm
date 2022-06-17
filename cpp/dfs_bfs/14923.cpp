#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Matrix {
    int z,x,y;
};

int n,m;
int Hx,Hy,Ex,Ey;
int graph[1001][1001];
int check[3][1001][1001];
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};

int main() {
    cin >> n >> m >> Hx >> Hy >> Ex >> Ey;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cin >> x;
            graph[i][j] = x;
        }
    }
    queue<Matrix> q;
    q.push({0,Hx-1,Hy-1});
    check[0][Hx-1][Hy-1] = 0;
    while(!q.empty()){
        Matrix cur = q.front();
        q.pop();
        int z = cur.z;
        int x = cur.x;
        int y = cur.y;
        if(x == Ex-1 && y == Ey-1){
            cout << check[z][x][y] << '\n';
            return 0;
        }
        for(int i=0;i<4;i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(dx > n-1 || dy > m-1 || dx < 0 || dy < 0){
                continue;
            }
            if(check[z][dx][dy]){
                continue;
            }
            if(graph[dx][dy] == 0){
                q.push({z,dx,dy});
                check[z][dx][dy] = check[z][x][y] + 1;
            }else{
                if(z + 1 > 1){
                    continue;
                }
                q.push({z+1,dx,dy});
                check[z+1][dx][dy] = check[z][x][y] + 1;
            }
        }
    }
    cout << -1 << '\n';
}
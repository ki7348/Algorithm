#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Matrix {
    int x,y,cnt, dist;
};

int n,m;
int graph[1001][1001];
bool check[1001][1001][2];
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
bool state = false;

int main() {
    cin >> n >> m;
    for(int i=0;i<n;i++){
        string temp;
        cin >> temp;
        for(int j=0;j<m;j++){
            graph[i][j] = temp[j] - '0';
        }
    }

    queue<Matrix> q;
    q.push({0,0,0,1});
    check[0][0][0] = 1;
    while(!q.empty()){
        Matrix cur = q.front();
        q.pop();
        int x = cur.x;
        int y = cur.y;
        int cnt = cur.cnt;
        int dist = cur.dist;

        if(x == n-1 && y == m-1){
            cout << dist << '\n';
            state = true;
            break;
        }

        for(int i=0;i<4;i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];

            if(dx > n-1 || dy > m-1 || dx < 0 || dy < 0){
                continue;
            }

            if(check[dx][dy][cnt]){
                continue;
            }

            if(graph[dx][dy] == 1){
                if(cnt < 1){
                    q.push({dx,dy,cnt+1,dist+1});
                    check[dx][dy][cnt+1] = 1;
                }
            }else{
                q.push({dx,dy,cnt,dist+1});
                check[dx][dy][cnt] = 1;
            }
        }
        
    }

    if(!state){
        cout << -1 << '\n';
    }
}
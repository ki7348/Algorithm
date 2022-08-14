#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

int n,m, cnt;
int graph[101][101];
bool zero[101][101];
bool visited[101][101];
int last_cnt = 0;
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};


void bfs(int x,int y){
    queue<pair<int,int>> q2;
    q2.push({x,y});
    visited[x][y] = true;

    while(!q2.empty()){
        int x = q2.front().first;
        int y = q2.front().second;
        q2.pop();

        for(int i=0;i<4;i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(dx > n-1 || dy > m-1 || x < 0 || y < 0){
                continue;
            }
            if(visited[dx][dy]) continue;
            if(graph[dx][dy] == 1){
                graph[dx][dy] = 0;
                cnt++;
                last_cnt++;
            }
        }
    }

}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> graph[i][j];
        }
    }
    int bfs_cnt = 0;

    while(true){
        bfs_cnt++;
        queue<pair<int,int>> q;
        memset(zero, false, sizeof(zero));

        q.push({0,0});
        zero[0][0] = 1;

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int dx = x + dir[i][0];
                int dy = y + dir[i][1];
                if(zero[dx][dy]) continue;
                if(dx > n-1 || dy >m-1 || dx < 0 ||  dy<0) continue;
                if(graph[dx][dy] == 0){
                    q.push({dx,dy});
                    zero[dx][dy]=1;
                }
            }
        }

        memset(visited, false, sizeof(visited));
        cnt = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(graph[i][j] == 0 && zero[i][j] == 1 && !visited[i][j]){
                    bfs(i,j);
                }
            }
        }
        
        if(cnt == 0){
            break;
        } else {
            last_cnt = cnt;
        }

    }

    cout << bfs_cnt - 1 << '\n';
    cout << last_cnt << '\n';


}
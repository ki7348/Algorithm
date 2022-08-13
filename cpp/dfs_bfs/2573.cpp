#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;
int n,m;
int graph[301][301];
bool check[301][301];
bool visited[301][301];
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};

void bfs(int x,int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = true;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(visited[dx][dy]) continue;
            if(dx > n-1 || dy > m-1 || dx < 0 || dy < 0) continue;
            if(graph[dx][dy] > 0){
                visited[dx][dy] = true;
                q.push({dx,dy});
            }
        }
    }
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

    int result = 0;
    bool not_melt = false;


    while(true){
        result++;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                check[i][j] = false;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(graph[i][j] != 0){
                    int cnt = 0;
                    for(int k=0;k<4;k++){
                        int dx = i + dir[k][0];
                        int dy = j + dir[k][1];
                        if(dx > n-1 || dy > m-1 || dx < 0 || dy < 0) continue;
                        if(graph[dx][dy] == 0 && !check[dx][dy]){
                            cnt++;
                        }
                    }
                    check[i][j] = true;
                    if(cnt > graph[i][j]){
                        graph[i][j] = 0;
                    }else{
                        graph[i][j] -= cnt;
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                visited[i][j] = false;
            }
        }
        
        int bfs_cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(graph[i][j] > 0 && !visited[i][j]){
                    bfs(i,j);
                    bfs_cnt++;
                }
            }
        }

        if(bfs_cnt > 1){
            break;
        }

        if(bfs_cnt == 0){
            not_melt= true;
            break;
        }
    }

    if(not_melt){
        cout <<  0 << '\n';
        return 0;
    }
    cout << result << '\n';
    
}

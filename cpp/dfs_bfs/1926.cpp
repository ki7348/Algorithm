#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
int graph[501][501];
bool check[501][501];
queue<pair<int,int>> q;
int result = 0;
int total = 0;
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int bfs(int x,int y){
    check[x][y] = 1;
    q.push(make_pair(x,y));
    int temp = 0;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(dx<0 || dy<0 || dx>n-1 || dy>m-1)
                continue;
            if(!check[dx][dy] && graph[dx][dy]>0){
                temp++;
                check[dx][dy] = 1;
                q.push(make_pair(dx,dy));
                graph[dx][dy] = 0;
            }
        }
    }
    return temp+1;
}

int main(){
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cin >> x;
            graph[i][j] = x;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j]==1){
                total++;
                int temp = bfs(i,j);
                result = max(temp,result);
            }
        }
    }
    cout << total << '\n';
    cout << result << '\n';
}
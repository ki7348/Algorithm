#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n,m;
int graph[101][101];
bool check[101][101] = {false};
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
queue<pair<int,int>> q;

void bfs(int x,int y){
    q.push(make_pair(x,y));
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
                check[dx][dy] = 1;
                q.push(make_pair(dx,dy));
                graph[dx][dy] = graph[x][y] + 1;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        for(int j=0;j<m;j++){
            graph[i][j] = str[j]-'0';
        }
    }
    bfs(0,0);
    cout << graph[n-1][m-1] << '\n';
}
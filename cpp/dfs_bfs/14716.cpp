#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n,m;
int graph[251][251];
bool check[251][251];
int result = 0;
int dir[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1,-1}, {-1,1}, {1,1}, {1,-1} };
queue<pair<int,int>> q;

void bfs(int x,int y){
    q.push(make_pair(x,y));
    check[x][y] = 1;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0;i<8;i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(dx<0 || dy<0 || dx>n-1 || dy>m-1)
                continue;
            if(!check[dx][dy] && graph[dx][dy]==1){
                check[dx][dy] = 1;
                q.push(make_pair(dx,dy));
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cin >> x;
            graph[i][j] = x;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j]==1 && !check[i][j]){
                result++;
                bfs(i,j);
            }
        }
    }
    cout << result << '\n';
}
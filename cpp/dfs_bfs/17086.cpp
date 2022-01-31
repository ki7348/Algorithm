#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n,m;
int graph[51][51];
int new_graph[51][51];
bool check[51][51];
queue<pair<int,int>> q;
int dir[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1,-1}, {-1,1}, {1,1}, {1,-1} };


void bfs(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<8;i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(dx<0 || dy<0 || dx>n-1 || dy>m-1)
                continue;
            if(!check[dx][dy] && graph[dx][dy]==0){
                check[dx][dy] = 1;
                graph[dx][dy] = graph[x][y] + 1;
                q.push(make_pair(dx,dy));
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cin >> x;
            graph[i][j] = x;
        }
    }
    int final = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j] == 1){
                q.push(make_pair(i,j));
                check[i][j] = 1;
            }
        }
    }
    bfs();
    int max_elem = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            max_elem = max(max_elem,graph[i][j]);            
        }
    }
    cout << max_elem - 1 << '\n';

}
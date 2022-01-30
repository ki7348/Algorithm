#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n,m;
int graph[1001][1001];
bool check[1001][1001];
int max_tomato = 0;
queue<pair<int,int>> q;
queue<pair<int,int>> temp;

int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs(queue<pair<int,int>> temp){
    while(!temp.empty()){
        int temp1 = temp.front().first;
        int temp2 = temp.front().second;
        check[temp1][temp2] = 1;
        temp.pop();
        q.push(make_pair(temp1,temp2));
    }
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
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
    cin >> m >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cin >> x;
            graph[i][j] = x;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j]==1){
                temp.push(make_pair(i,j));
            }
        }
    }
    bfs(temp);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j]==0){
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            max_tomato = max(max_tomato,graph[i][j]);
        }
    }
    cout << max_tomato -1 << '\n';
}
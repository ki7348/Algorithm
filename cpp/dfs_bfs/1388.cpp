#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n,m;
char graph[51][51];
bool check[51][51];

int dir[2][2] = { {-1, 0}, {1, 0}};
int dir2[2][2] = {{0,-1}, {0,1}};
queue<pair<int,int>> q;
vector<int> v;
int cnt = 0;

void bfs(int x, int y) {
    q.push(make_pair(x,y));
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        if(graph[x][y] == '-'){
            for(int i=0;i<2;i++){
                int dx = x + dir2[i][0];
                int dy = y + dir2[i][1];
                if(dx<0 || dy<0 || dx>n-1 || dy>m-1)
                    continue;
                if(!check[dx][dy] && graph[dx][dy] == '-'){
                    check[dx][dy] = 1;
                    q.push(make_pair(dx,dy));
                }
            }
        }else {
            for(int i=0;i<2;i++){
                int dx = x + dir[i][0];
                int dy = y + dir[i][1];
                if(dx<0 || dy<0 || dx>n-1 || dy>m-1)
                    continue;
                if(!check[dx][dy] && graph[dx][dy] == '|'){
                    check[dx][dy] = 1;
                    q.push(make_pair(dx,dy));
                }
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
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!check[i][j]){
                bfs(i,j);
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
}
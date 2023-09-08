#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int graph[4][4];
bool check[4][4];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
queue<pair<int,int>> q;
int n;

void bfs(int x, int y){
    check[x][y] = 1;
    q.push({x,y});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int dx = x + graph[x][y] * dir[i][0];
            int dy = y + graph[x][y] * dir[i][1];
            if(check[dx][dy]){
                continue;
            }
            if(dx > n-1 || dy > n-1 || dx < 0 || dy<0){
                continue;
            }

            q.push({dx,dy});
            check[dx][dy] = true;
        }

    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x;
            cin >> x;
            graph[i][j] = x;
        }
    }

    bfs(0,0);

    if(check[n-1][n-1]){
        cout << "HaruHaru" << '\n';
    }else{
        cout << "Hing" << '\n';
    }
}
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

bool check[101][101];
int dir[4][2] = {{-1,0}, {1,0}, {0,1}, {0,-1}};
int n;
char graph[101][101];

void bfs(int x, int y){
    check[x][y] = true;
    queue<pair<int,int>> q;
    q.push({x,y});

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];

            if(dx > n-1 || dy > n-1 || dx < 0 || dy < 0){
                continue;
            }

            if((graph[x][y] == 'R' || graph[x][y] == 'G') && (graph[dx][dy] == 'R' || graph[dx][dy] == 'G')){
                check[dx][dy] = 1;
                q.push({dx,dy});
            }

            else if((graph[x][y] == 'B') && (graph[dx][dy] == 'B')){
                check[dx][dy] = 1;
                q.push({dx,dy});
            }

        }
    }
}

int main() {
    cin >> n;
    int extra = 0;
    int ordinary = 0;


    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        for(int j=0;j<n;j++){
            graph[i][j] = str[i];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if((!check[i][j])){
                bfs(i,j);
                extra++;
            }
        }
    }

    cout << extra << '\n';
}
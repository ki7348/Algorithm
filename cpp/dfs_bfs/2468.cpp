#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n;
int max_elem = 0;
int graph[101][101];
bool check[101][101];
int result = 0;
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
queue<pair<int,int>> q;

void bfs(int x,int y,int level){
    q.push(make_pair(x,y));
    check[x][y] = 1;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(dx<0 || dy<0 || dx>n-1 || dy>n-1)
                continue;
            if(!check[dx][dy] && graph[dx][dy]>level){
                check[dx][dy] = 1;
                q.push(make_pair(dx,dy));
            }
        }
    }
}

void reset(){
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            check[i][j] = 0;
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
            max_elem = max(max_elem,graph[i][j]);
        }
    }
    for(int k=1;k<=max_elem;k++){
        int temp = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(graph[i][j]>k&&!check[i][j]){
                    bfs(i,j,k);
                    temp+=1;
                }
            }
        }
        reset();
        result = max(result,temp);
    }
    if(result==0){
        cout << 1 << '\n';
        return 0;
    }
    cout << result <<'\n';
}
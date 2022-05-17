#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int n,m;
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
char graph[601][601];
bool check[601][601];
int result = 0;
queue<pair<int,int>> q;

void bfs(int x,int y) {
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(dx<0 || dy<0 || dx>n-1 || dy>m-1)
                continue;
            if(graph[dx][dy] == 'P' && !check[dx][dy]){
                result+=1;
                check[dx][dy] = 1;
                q.push(make_pair(dx,dy));
            }else if(graph[dx][dy] == 'O' && !check[dx][dy]){ 
                q.push(make_pair(dx,dy));
                check[dx][dy] = 1;
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
            if(graph[i][j] == 'I'){
                q.push(make_pair(i,j));
                check[i][j] =1;
                bfs(i,j);
            }
        }
    }
    if(result > 0){
        cout << result << '\n';
    }else {
        cout << "TT" << '\n';
    }
}
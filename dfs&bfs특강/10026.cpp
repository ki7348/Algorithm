#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int n;
char graph[101][101];
queue<pair<int,int>> q;
queue<pair<int,int>> q2;
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
bool check[101][101] = {false,};
bool check2[101][101] = {false,};
int cnt = 0;
int cnt2 = 0;

void bfs(int a, int b) {
    q.push({a,b});
    check[a][b] = true;
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
            if(check[dx][dy]){
                continue;
            }
            if(graph[x][y] == 'R' && graph[dx][dy] == 'R'){
                check[dx][dy] = true;
                q.push({dx,dy});
            }
            else if(graph[x][y] == 'G' && graph[dx][dy] == 'G'){
                check[dx][dy] = true;
                q.push({dx,dy});
            }
            else if(graph[x][y] == 'B' && graph[dx][dy] == 'B'){
                check[dx][dy] = true;
                q.push({dx,dy});
            }
        }
    }
}

void bfs2(int a, int b) {
    q2.push({a,b});
    check2[a][b] = true;
    while(!q2.empty()){
        int x = q2.front().first;
        int y = q2.front().second;
        q2.pop();
        for(int i=0;i<4;i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(dx > n-1 || dy > n-1 || dx < 0 || dy < 0){
                continue;
            }
            if(check2[dx][dy]){
                continue;
            }
            if(graph[x][y] == 'R' && (graph[dx][dy] == 'R' || graph[dx][dy] == 'G')){
                check2[dx][dy] = true;
                q2.push({dx,dy});
            }
            else if(graph[x][y] == 'G' && (graph[dx][dy] == 'G' || graph[dx][dy] == 'R')){
                check2[dx][dy] = true;
                q2.push({dx,dy});
            }
            else if(graph[x][y] == 'B' && graph[dx][dy] == 'B'){
                check2[dx][dy] = true;
                q2.push({dx,dy});
            }
        }
    }
}

int main() {
    cin >> n;
    for(int i=0;i<n;i++){
        string temp;
        cin >> temp;
        for(int j=0;j<n;j++){
            graph[i][j] = temp[j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!check[i][j]){
                bfs(i,j);
                cnt++;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!check2[i][j]){
                bfs2(i,j);
                cnt2++;
            }
        }
    }
    cout << cnt << ' ';
    cout << cnt2 << '\n';
}
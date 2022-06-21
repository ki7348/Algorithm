#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n,m;
char graph[1001][1001];
bool visited[1001][1001];
int finished[1001][1001];
int result = 0;

void dfs(int x,int y){
    visited[x][y] = true;
    int next_x = x;
    int next_y = y;
    if(graph[x][y] == 'D'){
        next_x = x+1;
    }else if(graph[x][y] == 'L'){
        next_y = y-1;
    }else if(graph[x][y] == 'R'){
        next_y = y+1;
    }else {
        next_x = x-1;
    }
    if(!visited[next_x][next_y]){
        dfs(next_x,next_y);
    }else if(!finished[next_x][next_y]){
        while(next_x != x && next_y != y){
            result++;
            if(graph[x][y] == 'D'){
                next_x = x+1;
            }else if(graph[x][y] == 'L'){
                next_y = y-1;
            }else if(graph[x][y] == 'R'){
                next_y = y+1;
            }else {
                next_x = x-1;
            }
        }
        result++;
    }
    finished[x][y] = true;
}

int main() {
    cin >> n >> m;
    for(int i=0;i<n;i++){
        string temp;
        cin >> temp;
        for(int j=0;j<m;j++){
            graph[i][j] = temp[j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]){
                dfs(i,j);
            }
        }
    }
    cout << result << '\n';
}
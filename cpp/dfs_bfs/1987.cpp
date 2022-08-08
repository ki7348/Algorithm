#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
char graph[21][21];
map<char,int> mp;
int r,c;
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int answer = 0;

void dfs(int x,int y,int cnt){
    answer = max(answer,cnt);
    for(int i=0;i<4;i++){
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];
        if(dx > r-1 || dy > c-1 || dx < 0 || dy < 0){
            continue;
        }
        if(mp[graph[dx][dy]]){
            continue;
        }
        mp[graph[dx][dy]] = 1;
        dfs(dx,dy,cnt+1);
        mp[graph[dx][dy]] = 0;
        
    }
}

int main() {
    cin >> r >> c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> graph[i][j];
        }
    }
    mp[graph[0][0]] = 1;
    dfs(0,0,1);
    cout << answer << '\n';
}
#include <iostream>
#include <algorithm>
#include <queue>
#include <numeric>
#include <cmath>

using namespace std;

int n,m;
char graph[101][101];
bool check[101][101];
queue<pair<int,int>> q;
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int bfs(int x,int y,char ch){
    check[x][y] = 1;
    int temp = 1;
    q.push(make_pair(x,y));
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(dx<0 || dy<0 || dx>n-1 || dy>m-1)
                continue;
            if(!check[dx][dy] && graph[dx][dy]==ch){
                check[dx][dy] = 1;
                q.push(make_pair(dx,dy));
                temp++;
            }
        }
    }
    return temp;
}

int main(){
    cin >> m >> n;
    int white = 0;
    int black = 0;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        for(int j=0;j<m;j++){
            graph[i][j] = str[j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!check[i][j]){
                int sum_power = bfs(i,j,graph[i][j]);
                if(graph[i][j]=='W'){
                    white+=pow(sum_power,2);
                }else{
                    black+=pow(sum_power,2);
                }
            }
        }
    }
    cout << white << ' ' << black << '\n';
}
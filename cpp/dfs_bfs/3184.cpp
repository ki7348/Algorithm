#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n,m;
bool check[251][251];
char graph[251][251];
int wolf = 0;
int sheep = 0;
queue<pair<int,int>> q;
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};


void bfs(int x,int y){
    int v_count = 1;
    int o_count = 0;
    check[x][y] = 1;
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
            if(!check[dx][dy] && graph[dx][dy]!='#'){
                check[dx][dy] = 1;
                if(graph[dx][dy]=='.'){
                    q.push(make_pair(dx,dy));
                }else if(graph[dx][dy]=='v'){
                    v_count++;
                    q.push(make_pair(dx,dy));
                }else if(graph[dx][dy]=='o'){
                    o_count++;
                    q.push(make_pair(dx,dy));
                }
            }
        }
    }
    if(v_count>=o_count){
        wolf+=v_count;
        sheep-=o_count;
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char x;
            cin >> x;
            graph[i][j] = x;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j]=='v' && !check[i][j]){
                bfs(i,j);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j]=='o'){
                sheep+=1;
            }
        }
    }
    cout << sheep << ' ' << wolf << '\n';
}